# Task 4 Solution
Task 4 involved finding out how a USB device mounts and decrypts a certain filesystem. While you can search for how the system does this using the QEMU docker container from task3, I found it much easier to instead extract the pertinent files by running the command "binwalk -e usb.img". The command searches usb.img for embedded files and executable files while the -e flag extracts the files:

Using this method, we can now see that the device has some type of script that looks to be mounting an encrypted partition. Additionally, we can see that the encrypted partition is being encrypted through LUKS. 
