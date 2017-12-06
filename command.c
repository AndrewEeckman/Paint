//
// Created by Andrew Eeckman on 12/5/17.
//

#include "command.h"
#include <stdio.h>

void getArgsByCommand(char command, int *numArgsNeeded, int *charCount, int *intCount);

void getCommand(char** canvas, const int num_rows, const int num_columns, const char blank_space, char *command,
             int* row, int* col) {
    int num_args_read = 1;
    int num_args_needed = 1;

    int charCount = 0;
    int intCount = 0;

    do {
        printf("Enter your command: ");
        scanf("%c", &(*command));
        getArgsByCommand(*command, &num_args_needed, &charCount, &intCount);

        for(int i = 0; i < num_args_needed; i++) {
            if(charCount != 0) {
                for(int c = 0; c < charCount; c++) {
                    scanf("%c", )
                }
            }
        }

    } while(!isValidCommand(num_args_read, num_args_needed, canvas, num_rows, num_columns, *col, *row, blank_space));
}

void getArgsByCommand(char command, int *numArgsNeeded, int *charCount, int *intCount) {
    if(command == 'h') {
        *numArgsNeeded = 1;
        *charCount = 0;
        *intCount = 0;
    } else if(command == 'w') {
        *numArgsNeeded = 5;
        *charCount = 0;
        *intCount = 4;
    }
}