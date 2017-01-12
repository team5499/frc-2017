#!/bin/sh

# Set regular user
safeuser="INSERT_USERNAME_HERE"

if [ $safeuser = "INSERT_USERNAME_HERE"]
then
  echo "Change safeuser username!"
  exit 1
fi

# Exit if an error occurs
set -e

# Make sure script is root
if [ "$(id -u)" != "0" ]; then
  echo "ERROR: Must run as root!"
  exit 1
fi

roborioPrep()
{
  ssh admin@roborio-973-frc.local
  wget http://inabaudongein.reisen/frc/973-roborio.tar.gz -O - | tar --skip-old-files -vzxf - -C /usr
  exit
}

# Debian based installation
debianInstall()
{
  curl -sSl http://inabaudongein.reisen/frc/repo/go | sudo sh
  add-apt-repository ppa:wpilib/toolchain
  apt-get update
  apt-get install frc-toolchain wpilib-cpp ctre-toolsuite doxygen build-essential libboost-test-dev
}

# macOS installation
macInstall()
{
  # Get RoboRio toolchain
  wget http://first.wpi.edu/FRC/roborio/toolchains/FRC-2017-OSX-Toolchain-4.9.3.pkg.tar.gz
  tar xvf FRC-2017-OSX-Toolchain-4.9.3.pkg.tar.gz
  installer -pkg FRC\ ARM\ Toolchain.pkg/ -target /

  curl -sSL http://inabaudongein.reisen/frc/973-osx.tar.bz2 | tar -xjvf - -C /usr/local/arm-frc-linux-gnueabi

  # Check for Homebrew. If installed, update
  # Drop root to install Homebrew
  sudo -u $safeuser $0
  which -s brew
  if [[ $? != 0 ]] ; then
    # Install Homebrew
    /usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
  else
    brew update
    brew install cmake doxygen boost
  fi
}

echo "Prepare RoboRio?"
select yn in "Yes" "No"; do
    case $yn in
        Yes ) roborioPrep; break;;
        No ) break;;
    esac
done

echo "Install on Debian or macOS?"
select yn in "Debian" "macOS"; do
    case $yn in
        Debian ) debianInstall; break;;
        macOS ) macInstall; break;;
    esac
done

echo "Done."
