/*  Olivia Caulfield
    Cañas
    CSC 251
    Feb 1, 2022
*/

// include statements
#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
#include  <sys/types.h>
#include  <stdbool.h>
#include  <sys/time.h>
#include  <unistd.h>


int main(){
    // create variables
    int i = 0;
    char *line = NULL; 
    size_t len = 0;
    ssize_t lineSize = 0;

    // ask for first line and split it
    printf("enter data: ");
    lineSize = getline(&line, &len, stdin);
    char *splitString = strtok(line, " ");

    // as long as exit or enter weren't typed format print
    if(strcmp(line, "exit\n") && strcmp(line, "\n")){
        while (splitString != NULL){
            printf("argv[%d] %s\n", i, splitString);
            splitString = strtok(NULL, " ");
            i++;
        }
    }

    // ask again until until exit is typed
    while(strcmp(line, "exit\n") != 0){
        i = 0;
        printf("enter data: ");
        lineSize = getline(&line, &len, stdin);
        splitString = strtok(line, " ");
        // make sure that exit or enter weren't typed, then format print
        if(strcmp(line, "exit\n") && strcmp(line, "\n")){
            while (splitString != NULL){
                printf("argv[%d] %s\n", i, splitString);
                splitString = strtok(NULL, " ");
                i++;
            }
        }
    }

    // when exit is typed print and end
    printf("OK close shop and go home\n");
    return 0;
}