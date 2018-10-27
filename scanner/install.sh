#!/bin/bash

sudo apt update && sudo apt upgrade -y

sudo apt install libopencv-dev python-opencv libzbar0 python-pip -y

pip install pyzbar imutils picamera
# pip install opencv-python numpy
