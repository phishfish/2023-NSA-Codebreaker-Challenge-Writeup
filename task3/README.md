# Task 3 Solution
Task 3 involves finding the secret key to decrypt the kernel of the device. Doing this involves setting up the docker container to emulate booting up the device with QEMU. I achieved this using Windows WSL (as I like a challenge) by putting u-boot and the device tree blob file into the myfiles directory.

Afterwards, I ran the Docker commands outlined in the provided README.md to set up the Docker container and then run QEMU for the device's bootloader

Once inside, I explored u-boot by looking through the command list I got from typing '?'. While searching, I found a promising lead when I found a memory address while looking at the device's environment variables. 

With the key address, let's take a look at what is stored at that location by running the command "md 467a0000 32". The md (memory display) command prints out the first 32 bytes at the specified location:  

However, entering in the string does not yield the decryption key quite yet. As it turns out, since the system is in little endian, the string must be converted to account for this. Once converted, entering the string yields the flag for task3.  
