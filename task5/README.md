# Task 5 Solution
Task 5 involved studying the unencrypted filesystem with the passphrase found from completing task 4.
## Task 5 With Cheese
As many figured out through testing, the IP address needed for task 5 could be found without doing the above. Running the dropper file with the command "./dropper confi" gaves the following error message:



Indeed, this is the IP address found from doing the above. However, doing this means you do not get the username and password needed to complete task 6 and will therefore have to circle back and do it the "correct" way instead. 

## Task 5 Without Cheese
After extracting the files from the encrypted partition, I decided to put the look at the dropped files in Ghidra to get an idea of what each file is doing. On inspection, it appears the dropper file is communicating with a MongoDB server. Running the command "binwalk -e dropper" extracted a file. 
