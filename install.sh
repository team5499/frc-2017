#!/bin/sh
# usage: ./newinstall.sh <team_number>

team_number=$1

HAL_VERSION=0
ATHENA_RUNTIME_VERSION=0
ATHENA_VERSION=0
CTRE_VERSION=0
CSCORE_VERSION=0

# create a temporary directory for installation
setup()
{
    ssh lvuser@roborio-${team_number}-frc.local "killall -q netconsole-host || :; . /etc/profile.d/natinst-path.sh; /usr/local/frc/bin/frcKillRobot.sh"
    cd ~
    mkdir tmp_roborio_install
    cd tmp_roborio_install
    mkdir lib
    mkdir local
    mkdir find_hal
    mkdir find_athena_runtime
    mkdir find_athena
    mkdir find_ctre
    mkdir find_cscore
    mkdir find_netconsole_host
}
# find files to download and download them
findfiles()
{
    # Find the HAL runtime libraries, and download them
    cd find_hal
    wget --spider -r -nv --no-parent http://first.wpi.edu/FRC/roborio/maven/release/edu/wpi/first/wpilib/hal/
    cd first.wpi.edu/FRC/roborio/maven/release/edu/wpi/first/wpilib/hal
    year=0
    major_version=0
    minor_version=0
    for f in *; do
        [[ -e $f ]] || continue
        arr=(`echo $f|tr '.' ' '`)
        arr_minor=(`echo ${arr[2]}|tr '-' ' '`)
        tmp_year=${arr[0]}
        tmp_major_version=${arr[1]}
        tmp_minor_version=${arr_minor[0]}
        if [ $tmp_year -eq $year ]; then
            if [ $tmp_major_version -gt $major_version ]; then
                major_version=$tmp_major_version
                minor_version=$tmp_minor_version
            elif [ $tmp_major_version -eq $major_version ]; then
                if [ $tmp_minor_version -gt $minor_version ]; then
                    minor_version=$tmp_minor_version
                fi
            fi
        elif [ $tmp_year -gt $year ]; then
            year=$tmp_year
            major_version=$tmp_major_version
            minor_version=$tmp_minor_version
        fi

    done
    HAL_VERSION="${year}.${major_version}.${minor_version}"
    echo "HAL Year:$year"
    echo "HAL Version:$major_version.$minor_version"
    cd ~/tmp_roborio_install/find_hal
    rm -rf first.wpi.edu
    wget http://first.wpi.edu/FRC/roborio/maven/release/edu/wpi/first/wpilib/hal/${year}.${major_version}.${minor_version}/hal-${year}.${major_version}.${minor_version}.zip
    ls
    cd ..
    # Find the Athena runtime libraries, and download them
    cd find_athena_runtime
    wget --spider -r -nv --no-parent http://first.wpi.edu/FRC/roborio/maven/release/edu/wpi/first/wpilib/athena-runtime/
    cd first.wpi.edu/FRC/roborio/maven/release/edu/wpi/first/wpilib/athena-runtime/
    year=0
    major_version=0
    minor_version=0
    for f in *; do
        [[ -e $f ]] || continue
        arr=(`echo $f|tr '.' ' '`)
        arr_minor=(`echo ${arr[2]}|tr '-' ' '`)
        tmp_year=${arr[0]}
        tmp_major_version=${arr[1]}
        tmp_minor_version=${arr_minor[0]}
        if [ $tmp_year -eq $year ]; then
            if [ $tmp_major_version -gt $major_version ]; then
                major_version=$tmp_major_version
                minor_version=$tmp_minor_version
            elif [ $tmp_major_version -eq $major_version ]; then
                if [ $tmp_minor_version -gt $minor_version ]; then
                    minor_version=$tmp_minor_version
                fi
            fi
        elif [ $tmp_year -gt $year ]; then
            year=$tmp_year
            major_version=$tmp_major_version
            minor_version=$tmp_minor_version
        fi

    done
    ATHENA_RUNTIME_VERSION="${year}.${major_version}.${minor_version}"
    echo "Athena_Runtime Year:$year"
    echo "Athena_Runtime Version:$major_version.$minor_version"
    cd ~/tmp_roborio_install/find_athena_runtime
    rm -rf first.wpi.edu
    wget http://first.wpi.edu/FRC/roborio/maven/release/edu/wpi/first/wpilib/athena-runtime/${year}.${major_version}.${minor_version}/athena-runtime-${year}.${major_version}.${minor_version}.zip
    ls
    cd ..
    # Find the Athena libraries, and download them
    cd find_athena
    wget --spider -r -nv --no-parent http://first.wpi.edu/FRC/roborio/maven/release/edu/wpi/first/wpilibc/athena/
    cd first.wpi.edu/FRC/roborio/maven/release/edu/wpi/first/wpilibc/athena/
    year=0
    major_version=0
    minor_version=0
    for f in *; do
        [[ -e $f ]] || continue
        arr=(`echo $f|tr '.' ' '`)
        arr_minor=(`echo ${arr[2]}|tr '-' ' '`)
        tmp_year=${arr[0]}
        tmp_major_version=${arr[1]}
        tmp_minor_version=${arr_minor[0]}
        if [ "${tmp_year}" -eq "${year}" ]; then
            if [ $tmp_major_version -gt $major_version ]; then
                major_version=$tmp_major_version
                minor_version=$tmp_minor_version
            elif [ $tmp_major_version -eq $major_version ]; then
                if [ $tmp_minor_version -gt $minor_version ]; then
                    minor_version=$tmp_minor_version
                fi
            fi
        elif [ $tmp_year -gt $year ]; then
            year=$tmp_year
            major_version=$tmp_major_version
            minor_version=$tmp_minor_version
        fi

    done
    ATHENA_VERSION="${year}.${major_version}.${minor_version}"
    echo "Athena Year:$year"
    echo "Athena Version:$major_version.$minor_version"
    cd ~/tmp_roborio_install/find_athena
    rm -rf first.wpi.edu
    wget http://first.wpi.edu/FRC/roborio/maven/release/edu/wpi/first/wpilibc/athena/${year}.${major_version}.${minor_version}/athena-${year}.${major_version}.${minor_version}.zip
    ls
    cd ..
    # Find the CTRE CAN Talon SRX libraries, and download them
    cd find_ctre
    wget -r -q --show-progress --no-parent http://www.ctr-electronics.com//downloads/lib/
    cd www.ctr-electronics.com/downloads/lib
    rm -rf index.html
    rm -rf robots.txt
    rm -rf CTRE_FRCLibs_NON-WINDOWS.zip
    zero=0
    version=(0 0 0 0)
    version_actual=0
    for f in *; do
        [[ -e $f ]] || continue
        arr=(`echo $f|tr 'v' ' '`)
        arr_minor=(`echo ${arr[1]}|tr 'z' ' '`)
        tmp_version=(`echo ${arr_minor[0]}|tr '.' ' '`)
        tmp_version_actual=${arr_minor[0]}
        if [ "${tmp_version[0]}" -gt "${version[0]}" ]; then
            version=("${tmp_version[@]}")
            version_actual=$tmp_version_actual
        elif [ "${tmp_version[0]}" -eq "${version[0]}" ]; then
            if [ "${tmp_version[1]}" -gt "${version[1]}" ]; then
                version=("${tmp_version[@]}")
                version_actual=$tmp_version_actual
            elif [ "${tmp_version[1]}" -eq "${version[1]}" ]; then
                if [ "${tmp_version[2]}" -gt "${version[2]}" ]; then
                    version=("${tmp_version[@]}")
                    version_actual=$tmp_version_actual
                elif [ "${tmp_version[2]}" -eq "${version[2]}" ]; then
                    if [ "${tmp_version[3]}" -gt "${version[3]}" ]; then
                        version=("${tmp_version[@]}")
                        version_actual=$tmp_version_actual
                    fi
                fi
            fi
        fi

    done
    CTRE_VERSION="${version_actual}"
    echo "CTRE Version:$version_actual"
    cd ~/tmp_roborio_install/find_ctre
    rm -rf www.ctr-electronics.com
    wget http://www.ctr-electronics.com//downloads/lib/CTRE_FRCLibs_NON-WINDOWS_v${version_actual}.zip
    ls
    cd ..
    # Find the cscore runtime libraries
    cd find_cscore
    wget --spider -r -nv --no-parent http://first.wpi.edu/FRC/roborio/maven/release/edu/wpi/cscore/cpp/cscore/
    cd first.wpi.edu/FRC/roborio/maven/release/edu/wpi/cscore/cpp/cscore/
    version=(0 0 0)
    for f in *; do
        [[ -e $f ]] || continue
        ver_arr=(`echo $f|tr '-' ' '`)
        indv_arr=(`echo ${ver_arr[0]}|tr '.' ' '`)
        if [ "${indv_arr[0]}" -eq "${version[0]}" ]; then
            if [ "${indv_arr[1]}" -eq "${version[1]}" ]; then
                if [ "${indv_arr[2]}" -gt "${version[2]}" ]; then
                    version=("${indv_arr[@]}")
                fi
            elif [ "${indv_arr[1]}" -gt "${version[1]}" ]; then
                version=("${indv_arr[@]}")
            fi
        elif [ "${indv_arr[0]}" -gt "${version[0]}" ]; then
            version=("${indv_arr[@]}")
        fi

    done
    CSCORE_VERSION="${version[0]}.${version[1]}.${version[2]}"
    echo "cscore Version:${version[0]}.${version[1]}.${version[2]}"
    cd ~/tmp_roborio_install/find_cscore
    rm -rf first.wpi.edu
    wget http://first.wpi.edu/FRC/roborio/maven/release/edu/wpi/cscore/cpp/cscore/${version[0]}.${version[1]}.${version[2]}/cscore-${version[0]}.${version[1]}.${version[2]}-athena-uberzip.zip
    ls
    cd ..
    # find netconsole-host
    cd find_netconsole_host
    git clone https://github.com/wpilibsuite/netconsole-host.git
    cd netconsole-host
    make
    cd ../..
}
# Extract necessary files, and put them into ./lib
extractfiles()
{
    # move HAL files
    cd ~/tmp_roborio_install/find_hal
    unzip hal-${HAL_VERSION}.zip
    mv lib/* ~/tmp_roborio_install/lib/
    cd ~/tmp_roborio_install
    rm -rf find_hal
    # move athena runtime files
    cd find_athena_runtime
    unzip athena-runtime-${ATHENA_RUNTIME_VERSION}.zip
    mv lib/* ~/tmp_roborio_install/lib/
    cd ~/tmp_roborio_install
    rm -rf find_athena_runtime
    # move athena files
    cd find_athena
    unzip athena-${ATHENA_VERSION}.zip
    mv lib/* ~/tmp_roborio_install/lib/
    cd ~/tmp_roborio_install
    rm -rf find_athena
    # move CTRE files
    cd find_ctre
    unzip CTRE_FRCLibs_NON-WINDOWS_v${CTRE_VERSION}.zip
    mv cpp/lib/* ~/tmp_roborio_install/lib/
    cd ~/tmp_roborio_install
    rm -rf find_ctre
    # move cscore files
    cd find_cscore
    unzip cscore-${CSCORE_VERSION}-athena-uberzip.zip
    mv lib/* ~/tmp_roborio_install/lib/
    cd ~/tmp_roborio_install
    rm -rf find_cscore
    # move netconsole-host
    cd find_netconsole_host
    mv netconsole-host/netconsole-host ~/tmp_roborio_install/local/
    cd ~/tmp_roborio_install
    rm -rf find_netconsole_host
    # check files
    echo "lib contents:"
    ls lib/
    echo "local contents:"
    ls local/frc/bin
}
# Package ./local and ./lib into tmp_roborio_setup.zip and move them to the roborio
movelibs()
{
    cd ~/tmp_roborio_install
    zip -r -v tmp_roborio_setup.zip lib local
    echo "WARNING:You will need to confirm the file transfer(press enter)..."
    ssh admin@roborio-${team_number}-frc.local "mkdir ~/tmp_setup"
    scp tmp_roborio_setup.zip admin@roborio-${team_number}-frc.local:~/tmp_setup/tmp_roborio_setup.zip
    echo "WARNING:You will need to confirm the the next step(press enter)..."
    ssh admin@roborio-${team_number}-frc.local "cd tmp_setup; unzip tmp_roborio_setup.zip; mv -f -v lib/* /usr/lib/; mv -f -v local/netconsole-host /usr/local/frc/bin/; cd ~; rm -rf tmp_setup; sync"
}
# Cleanup(remove unneccessary files, rebuild code)
cleanup()
{
    cd ~
    rm -rf tmp_roborio_install
    # make sure include paths are updated
    cd frc-2017-season/build
}
# Summarize what happened
summarize()
{
    echo "Summary:"
    echo "HAL version:${HAL_VERSION}"
    echo "Athena runtime version:${ATHENA_RUNTIME_VERSION}"
    echo "Athena version:${ATHENA_VERSION}"
    echo "CTRE version:${CTRE_VERSION}"
    echo "Cscore version:${CSCORE_VERSION}"
}


# Begin
echo "setting up directory structure..."
setup
echo "finding runtime libraries..."
findfiles
echo "moving things around..."
extractfiles
echo "moving stuff to the rio..."
movelibs
echo "cleaning up..."
cleanup
echo "summary..."
summarize