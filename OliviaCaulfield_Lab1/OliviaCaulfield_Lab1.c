/*  Olivia Caulfield
    Cañas
    CSC 251
    Feb 1, 2022
*/

// include statements
#include  <stdio.h>
#include  <stdlib.h>
#include  <sys/types.h>
#include  <stdbool.h>
#include  <sys/time.h>
#include  <unistd.h>

// Simple test function
int myNewFunction(){
    return 5;
}

// Function nanosec converts the time into nanoseconds
long nanosec(struct timeval t){
    return (t.tv_sec*1000000+t.tv_usec)*1000;
}

int main(){
    // Creates necessary local variables
    struct timeval sysStart, sysEnd, funStart, funEnd;
    int check, x;
    float sysDiff, funDiff;
    int iterations = 1000000;

    /* SYSTEM CALLS
       Get the start and end time for the repeating system call */
    check = gettimeofday(&sysStart, NULL); 
    for (int i = 0; i < iterations; i++){
        getppid();
    }
    check = gettimeofday(&sysEnd, NULL);

    /* FUNCTION CALLS
       Get the start and end time for the repeating function call */
    check = gettimeofday(&funStart, NULL);
    for(int i = 0; i < iterations; i++){
        x = myNewFunction();
    }
    check = gettimeofday(&funEnd, NULL);

    // Find the time difference for each type of call in nanoseconds
    sysDiff = (nanosec(sysEnd) - nanosec(sysStart))/iterations*1.0;
    funDiff = (nanosec(funEnd) - nanosec(funStart))/iterations*1.0;

    // Print the average time for the system call and function call
    printf("Average System Call time: %f nsec\nAverage Function Call time: %f nsec\n", sysDiff, funDiff);
}