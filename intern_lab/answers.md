1. What is your current working directory?
Answer: My current working directory is my intern_lab directory.
2. What is the difference between '/' and '~'?
Answer: '/' represents the root directory, while '~' represents my home directory.
3. What is the difference between '.' and '..'?
Answer: '.' represents the current directory, while '..' represents the parent directory.
4. What is the difference between an absolute and relative path?
Answer: An absolute path starts from the root directory '/' and gives a complete location of a file or directory, while a relative
path starts from the current working directory.
5. What command would you use to display hidden files?
Answer: The 'ls -la' command can be used to display hidden files.


PART 3 - PIPES
Task 3 - Names Challenge
1. Total number of names

Command:
cat intern_lab/data/names.txt | wc -l

Result:
50

2. Number of unique names

Command:
sort intern_lab/data/names.txt | uniq | wc -l

Result:
24

3. Alphabetically sorted names

Command:
sort intern_lab/data/names.txt

Result:
The 50 names are displayed in alphabetical order.

4. Names beginning with A

Command:
grep '^A' intern_lab/data/names.txt

Result:
Alice
Angela
Alice
Andrew
Alice
Angela
Alice
Angela
Alice

5. Names beginning with M

Command:
grep '^M' intern_lab/data/names.txt

Result:
Michael
Mary
Martha
Michael
Mary
Mark
Michael
Martha
Mary
Mark
Michael
Mary
Martha
Michael
Mark
Mark

6. Five most frequently occurring names

Command:
sort intern_lab/data/names.txt | uniq -c | sort -nr | head -5

Result:
5 Michael
5 Alice
4 Mary
4 Mark
3 Peter



PART 4 - SEARCHING
Task 4 - Investigation
1. How many .log files exist?

Command:
find intern_lab/investigation -type f -name "*.log"

Result:
2

2. Which files contain ERROR?

Command:
grep -l "ERROR" intern_lab/investigation/*

Result:
intern_lab/investigation/network.log
intern_lab/investigation/notes.txt
intern_lab/investigation/server.log

3. Which files contain WARNING?

Command:
grep -l "WARNING" intern_lab/investigation/*

Result:
intern_lab/investigation/server.log
intern_lab/investigation/network.log
intern_lab/investigation/notes.txt

4. Which files contain admin?

Command:
grep -il "admin" intern_lab/investigation/*

Result:
intern_lab/investigation/users.txt
intern_lab/investigation/server.log
intern_lab/investigation/network.log
intern_lab/investigation/notes.txt
intern_lab/investigation/config.txt

5. Find all occurrences of password

Command:
grep -irn "password" intern_lab/investigation/

Result:
intern_lab/investigation/notes.txt:4:A password reset was requested.
intern_lab/investigation/config.txt:4:password=secure_password

6. Find all files in the directory

Command:
find intern_lab/investigation -type f

Result:
intern_lab/investigation/network.log
intern_lab/investigation/notes.txt
intern_lab/investigation/config.txt
intern_lab/investigation/applications.txt
intern_lab/investigation/server.log
intern_lab/investigation/users.txt

7. Find all empty files

Command:
find intern_lab/investigation -type f -empty

Result:
No output — there are no empty files.

PART 5 - LINUX PERMISSIONS
Task 5 - Permission Laboratory
1. What does chmod do?

Answer:
chmod changes the permissions of a file or directory, controlling who can read, write, or execute it.

2. What does chmod 755 mean?

Answer:
chmod 755 gives the owner read, write, and execute permissions, while the group and others get read and execute permissions.

3. What does chmod 600 mean?

Answer:
chmod 600 gives the owner read and write permissions, while the group and others have no permissions.

4. Why does a script need execute permission?

Answer:
A script needs execute permission so that the operating system allows the user to run the script as a program.

5. What security problem can occur when sensitive files have excessive permissions?

Answer:
Excessive permissions can allow unauthorized users to read, modify, or delete sensitive files, which can lead to data exposure or security breaches.
