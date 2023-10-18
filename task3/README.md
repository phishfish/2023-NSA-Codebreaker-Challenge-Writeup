# Task 3 Solution
Task 3 involves finding the secret key to decrypt the kernel of the device. Doing this involves setting up the docker container to emulate booting up the device with QEMU. I achived this using Windows WSL (as I like a challenge) by putting u-boot and the device tree blob file into the myfiles directory. 

Afterwards, I ran the Docker commands outlined in the given README.md to set up the Docker container and then run QEMU for the device's bootloader.

Once inside, I snooped around by looking through the command list I got from typing '?'. While searching, I found a promising lead when I found a memory address while looking at the device's environment variables. 
