Olivia Caulfield
CSC - 251 - Lab 3

The purpose of this lab is to write a simple shell program. This simple shell must exit with 'exit', reprompt when a new line is entered, and NOT exit with control C. Additionally, the & operator should not wait for the command to terminate and run concurrently instead.
**NOTE: I used waitpid instead of wait because wait was reprompting before execution finished, so I used waitpid to ensure that the specific process finished before reprompting.

To compile: cc OliviaCaulfield_Lab3.c
To execute: ./a.out

Lab Questions
1) How can the shell identify if the command was executed successfully or not?
	If the command was executed successfully, the shell can identify this because a 0 will be returned. 
2) Under what circumstances will exec return to the calling process?
	If an error occurs exec will return to the calling process, otherwise, the child will execute first and then exec will return to the calling process. }
