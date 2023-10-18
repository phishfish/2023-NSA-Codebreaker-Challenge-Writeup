# Task 2 Solution
Task 2 involved "wiring" the pins of a device that seems to be transmitting and recieving data given the device CPU, debug ports, and output when attempting to read from HDMI. While physically wiring the device onto a breadboard is not possible (heartbreaking), we can provide the correct pin numbers for power, ground, enabling UART transmission, and receiving UART messages.

As we can see from looking at the image, we are working with a Broadcom BCM2837. So, using the power of Google, I was able to find the corresponding processor sheet that included information on wiring the device. Using the information provided by the sheet as well as the information from the debug ports, I was able to get the pins for powering and grounding the device. However, I ran into an issue with finding the pins for sending and recieving UART messages. 

The missing information needed to complete Task 2 was found in the boot-up prompt. In it, it is revealed that the device uses the ALT5 alternative function. This corresponds to 2 specific pin numbers for sending and recieving UART messages. Sure enough, entering the two pin numbers provided the flag for Task 2.
