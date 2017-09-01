#!/bin/sh
team_number=$1
program=$2
robot_command=$3

ROBORIO_FOUND=1
probe()
{
    echo "Probing..."
    ssh -o ConnectTimeout=30 lvuser@roborio-${team_number}-frc.local "true"
    if [ $? -eq 0 ]; then
        echo "Target found"
        ROBORIO_FOUND=0
    else
        echo "Target not found"
        ROBORIO_FOUND=1
    fi
}
deploy()
{
    echo "removing old program..."
    ssh lvuser@roborio-${team_number}-frc.local "rm -f ~/FRCUserProgram"
    echo "copying over new program..."
    scp ${program} lvuser@roborio-${team_number}-frc.local:~/FRCUserProgram
    echo "stopping netconsole-host..."
    ssh lvuser@roborio-${team_number}-frc.local "killall -q netconsole-host || :"
    echo "copying over robotcommand..."
    scp ${robot_command} lvuser@roborio-${team_number}-frc.local:~/robotCommand
    echo "cleaning up..."
    ssh lvuser@roborio-${team_number}-frc.local ". /etc/profile.d/natinst-path.sh; chmod a+x ~/FRCUserProgram; /usr/local/frc/bin/frcKillRobot.sh -t -r; sync"
}

probe
if [ ROBORIO_FOUND -eq 0 ]; then
    deploy
    echo "deploy success!!"
else
    echo "failed to find the roborio... check your network"
fi