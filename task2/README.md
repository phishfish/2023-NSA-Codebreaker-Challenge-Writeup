# Task 2 Solution
Task 2 involved "wiring" the pins of a device that seems to be transmitting and recieving data given the device CPU, debug ports, and output when attempting to read from HDMI. While we can not physically wire the device onto a breadboard (heartbreaking), we can provide the correct pin numbers to power, ground, allow for UART transmission, and allow for recieving UART messages. To do this, we will need to examine the picture of the device's CPU to get an idea of what type of device we are looking at and where to hunt for information.

As we can see from looking at the image, we are working with a Broadcom BCM2837. So, using the power of Google, I was able to find the corresponding processor sheet that included information on wiring the device. 
