#!/bin/bash

# Update the system and install packages
sudo apt update && sudo apt upgrade -y
sudo apt install libopencv-dev python-opencv libzbar0 python-pip make g++ pkg-config -y
pip install pyzbar imutils picamera

# Build i2c driver
cd i2c
make
cd ..

read -p "Do you want to log in now? (y/n)" -n 1 -r
echo    # (optional) move to a new line
if [[ $REPLY =~ ^[Yy]$ ]]; then
  bash login.sh
else
    echo 'Done. Log in later with ./login.sh'
fi
