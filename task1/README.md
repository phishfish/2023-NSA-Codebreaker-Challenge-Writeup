# Task 1 Solution
Task 1 within the scenario involved downloading a .db (database) file that can not be read by a human as well as a file containing the coordinates and the timestamp of an interesting signal. We are tasked with searching the given database for entries that line up with the signal geographically within 1/100th of a degree as well as making sure the entries are within 10 minutes of each other. 

Interacting with the data will involve using a tool called SQLite. SQLite is a database engine that stores information in tables where you can then query to get information from it. So, let's open up the database using SQLite. 

Using the command ".schema", we can see that the database contains columns under ____ tables labeled longitude and latitude. 

With this knowledge, execute the query "WHERE * FROM _____ WHICH longituge BETWEEN _______ AND latitude BETWEEN" gives us the following results:

Entering in the two IDs gives us the flag for task1, however, wouldn't it be cooler if it were... more complicated????

## Descending Into the SQLite API Dungeons
