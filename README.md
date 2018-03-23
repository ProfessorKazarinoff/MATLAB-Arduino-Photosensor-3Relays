# MATLAB-Arduino-Photosensor-3Relays
A student project in ENGR114 at Portland Community College that uses a photosensor connected to an Arduino to activate 3 relays

## Problem Statement:

This project is presented by the team named Bye Felicia!!! Our project consists to regulate the intensity of sun light to simulate the indoor light of the fish tank. The lighting system for the fish tank is currently operated manually. Our objective is to automate the lighting, so the lights turn on and off relative to the falling and rising of the sun. The MATLAB code reads the data from the Arduino code and decides to switch on/off the light according to the amount of light that the hardware box (including relays, photo-resistors).

## Hardware Setup:

### Bill of Materials:

### Hardware Schematic

### Hardware Hookup Guide

## Arduino Code

[Arduino_Code.ino](Arduino_Code.ino)

The Arduino .ino file was uploaded to the Arduino using the Arduino IDE. Ensure the ```COM``` port is set correctly before trying to upload.

## MATLAB Code

[MATLAB_Code.m](MATLAB_Code.m)

This MATLAB code receives a numerical value from Arduino every two seconds. It then builds an array of all the values received over a set time and plots it into a histogram of number of lights on vs time. The histogram divides the values into four different bins related to the range of the relays. These are represented on the x-axis as the number of lights that are on. Because the y-axis is the number of units each bin has, it should be noted that the number needs to be double to account for the two second delay from the Arduino.

## Results

## Future Work

Future groups could figure a way to use Wi-Fi into this project. Instead of using a photo-resistor they could pull figures from a weather site. They could also mount the photo-resistor separate from the Arduino breadboard. For MATLAB there are still problems with getting the graph to compile data the way we would like. Currently the graph complies data different for each computer it’s connected to. This causes the graph to look different too. 

## License

GNU General Public License v3.0
