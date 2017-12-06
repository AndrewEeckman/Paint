//
// Created by Andrew Eeckman on 12/5/17.
//

#include "command.h"
#include <stdio.h>
void commandChecker(char * commandArgs[], argNums ) {
    numsRead = 0;
    commmandArgs[argNums];
    char currentRead;

    while(currentRead != '\n'){
        if()
        scanf(" %c", &currentRead);
        commandArgs[numRead] = currentRead;

        numRead++;
    }
}

void getCommand(char** canvas, const int num_rows, const int num_columns, const char blank_space, char *command,
             int* row, int* col) {
    int num_args_read;
    int num_args_needed = 1;
    command = ' ';

    do {c
        printf("Enter your command: ");
        num_args_read = scanf("%c", &command);

        if(command == 'h') {

        }

    } while(!isValidCommand(num_args_read, num_args_needed, canvas, num_rows, num_columns, *col, *row, blank_space));
}
