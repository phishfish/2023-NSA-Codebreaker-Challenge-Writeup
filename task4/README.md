# Task 4 Solution
Task 4 involved finding out how a USB device mounts and decrypts a certain filesystem. While you can search for how the system does this using the QEMU docker container from task3, I found it much easier to instead extract the pertinent files by running the command "binwalk -e usb.img". The command searches usb.img for embedded files and executable files while the -e flag extracts the files:

Using this method, we can now see that the device has some type of script that looks to be mounting an encrypted partition. Additionally, we can see that the encrypted partition is being encrypted through LUKS. Since we ran the -e flag, we can now go to the "_usb.img.extracted" directory to look at the script responsible for mounting the filesystem, mount_part:

Analyzing the script, we can see that the way the script is decrypting the partition is by combining what is contained in the file hostname (briefframe), attaching the first three characters from a file from /private/id.txt, hashing it with sha1, and then piping the output as a passphrase to cryptsetup where if it is correct, it opens the encrypted partition part.enc. While the file hostname was recovered successfully, it appears that the data in id.txt was lost. 

However, we can work around this by bruteforcing the password. To do this, I first wrote a Python script to generate all the possible combinations of briefframe?a?a?a, hashed it with sha1, and then stored the output into a .txt file. This returned a very large amount of hashes (much more than can be done by writing a script to write try all of them). So, we turn to hashcat and instead utilize (fry) my GPU:

Using the list of hashes from my script, hascat was able to successfully find a hit in only 30 minutes. Submitting the flag gave me a shiny new badge (and a very hot laptop).
