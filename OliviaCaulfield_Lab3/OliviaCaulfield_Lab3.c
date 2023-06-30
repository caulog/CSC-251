/*  Olivia Caulfield
    Cañas
    CSC 251
    Feb 27, 2022
*/

// include statements
#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
#include  <stdbool.h>
#include  <unistd.h>
#include  <signal.h>
#include  <sys/wait.h>

#define BUFFER_LEN 1024

// function to make sure exit doesnt occur with control C
void noExit(int signalNumber){
    signal(SIGINT, noExit);
    fflush(stdout);
}

int main(){
    char line[BUFFER_LEN];          // get command line
    char* argv[120];                // user command
    int argc ;                      // argument count
    char *path= "/bin/";            // set path at bin  
    char instruct[50];              // full instruction
    bool amp = false;               // if & boolean

    // loop executes while 'exit' is not typed
    while(strcmp(line, "exit") != 0){
        signal(SIGINT, noExit);         // checks for control C
        size_t length;                  // length of input
        char *splitString;              // stores split command line
        int count = 0;                  // iterator variable

        if(!amp){
            printf("enter command: ");      // asks for line             
        }
        amp = false;               

        // COMMAND SYNTAX CHECKS
        if(!fgets(line,BUFFER_LEN, stdin)){ break; }                // checks command length
        length = strlen(line); 
        if(length == 0){ break; }                                   // checks that a command was input
        if (line[length - 1] == '\n'){ line[length - 1] = '\0'; }   // checks if input ends in new line

        // checks if command terminates with &
        if(line[length-2] == '&'){ 
            amp = true; 
            line[length-2] = '\0';
        }

        // splits command                  
        splitString = strtok(line," ");
        if(splitString == NULL){ continue; }
        while(splitString != NULL){
            argv[count] = splitString;      
            splitString = strtok(NULL," ");
            count++;
        }
        argv[count] = NULL; 
        
        // makes instruction /bin/userinput[0]
        strcpy(instruct, path);
        strcat(instruct, argv[0]); 

        // executes as long as command exists
        if (access(instruct,F_OK) == 0){
            pid_t pid;
            pid_t waitPid;
            int status;
            
            pid = fork();
            // child process
            if (pid == 0) { 
                if (execvp(instruct, argv) == -1) {
                  perror("error exec"); 
                }
                exit(EXIT_FAILURE);
            } 
            // parent process
            else if (pid > 0) {
                // if & then do not wait
                if(!amp){
                    //amp = false;
                    // use waitpid to wait until the process w pid 'pid' finishes
                    waitPid = waitpid(pid, &status, WUNTRACED);
                }
            } 
            // if error occurs in fork
            else {
                perror("error fork");
            }
        }
        // if command does not exist and is not 'exit'
        else {
            if (strcmp(line, "exit") != 0){
                printf("Invalid Command\n"); 
            }
        }           
    }
} 