#!/bin/bash

# Update the system and install packages
sudo apt update && sudo apt upgrade -y
sudo apt install libopencv-dev python-opencv libzbar0 python-pip -y
pip install pyzbar imutils picamera

# Enable pigpiod
sudo systemctl enable pigpiod.service
sudo systemctl start pigpiod.service

read -p "Do you want to log in now? (y/n)" -n 1 -r
echo
if [[ $REPLY =~ ^[Yy]$ ]]; then
  bash login.sh
else
    echo 'Done. Log in later with ./login.sh'
fi
