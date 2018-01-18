## libPySeek

# Description
This lib is a Python wrapper for Seek Thermal CompactPRO (https://www.thermal.com/compact-series.html)
* [Seek Thermal CompactPRO](http://www.thermal.com/products/compactpro)

# Reference
Most of codes are refered or resued from the following repo's
1. Seek-Thermal library
https://github.com/maartenvds/libseek-thermal
2. cv::Mat <--> Python Numpy array
https://github.com/GarrickLin/numpy-opencv-converter

# Build
Dependencies:
* cmake
* Opencv 3.x.x
* libusb-1.0-0-dev
* boost_1_66_0

```
cd libPySeek
vi src/CMakeLists.txt
```
(Find key word "PLEASE_CHANGE_TO_YOUR_PATH". Change the paths to yours)
```
mkdir build
cd build
cmake ../
make
```

# Run
An object file "build/src/pyseek.so" will be created. Copy that file to your wokring dir.

# Example
```
from pyseek import thSeekThermalPro
import cv2

seek = thSeekThermalPro()
status = seek.seekInit()
print status

while True:
	if seek.seekRead() == 1:
		frame = seek.seekGetGrayCvFrame()
		cv2.imshow('seek',frame)
	if cv2.waitKey(1) & 0xFF == ord('q'):
		break

cv2.destroyAllWindows()
```
Note: Please use sudo yourcode.py

## Getting USB access

You need to add a udev rule to be able to run the program as non root user:

Udev rule:

```
SUBSYSTEM=="usb", ATTRS{idVendor}=="289d", ATTRS{idProduct}=="XXXX", MODE="0666", GROUP="users"
```

Replace 'XXXX' with:
* 0011: Seek Thermal CompactPRO

or manually chmod the device file after plugging the usb cable:

```
sudo chmod 666 /dev/bus/usb/00x/00x
```

with '00x' the usb bus found with the lsusb command
