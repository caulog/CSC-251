NAME: Olivia Caulfield
CSC-251 - Lab 1: Functions and System Calls

The purpose of completing this lab was to determine if system calls are more expensive than
function calls. To do so, I first made a system call to getppid() which returns the process 
ID of the parent of the calling process. Then, I created a simple function called 
myNewFunction() which simply returns an integer. In two separate for loops I made repetitive
calls to each and tracked the average amount of time it took for each process.

Compile and Execute instructions:
    In order to compile this code, I used 
        cc OliviaCaulfield_Lab1.c
    followed by
        ./a.out
    in order to execute the code.

By printing the time required for both the system call and function call to complete, I was 
able to conclude that the function call was much more time efficient than the system call. 
On average, the system call took approximately 300ns while the function call took only about 
3ns. This time difference is due to the fact that a system call is a call into kernel code 
which requires the execution of an interrupt. This interrupt switches the control of the 
program to the kernel in order to execute the action requested before then switching the mode 
back to the previously executing process. Furthermore, this mode switching in order for 
interaction with the underlying operating system that occurs when a system call is made is 
not necessary when a function call is made which thus explains why a system call is much more 
time expensive than a simple function call.