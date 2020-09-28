# Cypress-PSoC4

This repository contains some **examples to start with Cypress PSoC 4** platform. I have followed the tutorials from **"Cypress Academy: PSoC 101"**, you can find them on the following YouTube's list: https://www.youtube.com/watch?v=LrXXpQr1itY&list=PLX6sqqUB8iOjsMfGEDcsPSuYLEFCh50Hr

I think Cypress made a great work, the tutorials were short and easy to follow, and are the base for more complex developments in the future. If you are getting familiar with the PSoC platform, I encourage you to watch them.

I am using the Cypress CY8CKIT-042, and the projects on this repository were designed and compiled for that board, but in case you are using another PSoC kit, you just have to change the device and adjust the pin-out.

# What do you need?

 - PSoC Creator (IDE)
 - PSoC 4 Development Kit (Development Board)
 - Wires

# Repository Structure

In the following lines I will specify what you can find in the folders.

## Lesson 1: Software Output Pins
In this lesson we learn about the software outputs. In this example we are programming the software to blink a led. This is such a *"Hello World"* program, and this will be useful to generate digital signals through software in the future.

## Lesson 2: Software Input Pins
This example was made to learn how to read from input pins. In this scenario we use the on-board switch. Additionally, the intention is to work with the schematics, adding new components  and configuring them. The program function is to read the input value and assigning it to a led, which is the output, as in the first example. All of this is made by software.

## Lesson 3: Interrupts

## Lesson 4: Hardware Pins
## Lesson 5: Toggle Flip-Flop
## Lesson 6: Basic Counter
## Lesson 7: Timer, Counter and PWM Component
## Lesson 8: Pulse Width-Modulator
## Lesson 9: Timer
## Lesson 10: I2C Receive
## Lesson 11: I2C Transmit
## Lesson 12: UART
## Lesson 13: CapSense (Using it as an Slider)
## Lesson 13-b: CapSense (Using it as independent buttons)
## Lesson 14: Status Register
## Lesson 15: Control Register 
## Lesson 16: Sleep (Using a Timer Interruption)
## Lesson 16-b: Sleep (Using a Software Interruption)
## Lesson 17: Deep Sleep

## Training Projects
In this folder you can find some projects that uses and applies what was learnt from the previous lessons.
### CapSense Led Patterns
This shows how to choose between different led blinking or fading patterns using capsense as buttons.
### KITT
A very easy project to test a few leds. It just turns on and off the leds in sequence, creating an effect similar to KITT lights in Knight Rider TV Show.
### LED PWM Meter
In this case Capsense value is represented in an array of 4 LEDs. Depending on the Capsense value, some LEDs might be on and or one of them could be attenuated. This effect is achieved using 4 PWM signals, which allows to choose the brightness of a LED.
### ADC-UART
It just obtains the value of an analog voltage and digitalizes it, printing it's value through an UART communication. I have tested it using a linear variable resistor.
### ADC-PWM-UART
It does the same than the previous one, but the ADC value is used to modify the duty-cycle of a PWM.
### Buttons-LEDs-UART
There are 2 buttons atached to a IRS. This program detects which button has been pressed or release, and prints it on screen through UART communication. I have tried to represent it in the way car doors work, in case that the door is opened, the interior light turns on and a warning message appears to the driver.
### RGB UART Control
In this project an RGB LED is controlled through commands using UART communication. User can send a command to set the value of all the colours or change the brightness of an specific LED.
### SPI-LEDs_Driver_Test
This project controls a 14-segments display, sending commands to a TLC5926 LED Driver via SPI. The evolution of the project is quite interesting, because since the first version major changes have been done. Finally, the brightness and the chars transitions can be controlled in time and some different patterns or dimming effects have been implemented.
