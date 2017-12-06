//
// Created by Andrew Eeckman on 12/5/17.
//

#include "command.h"
#include <stdio.h>
#include <stdlib.h>

void quitProg() {
       exit (0);
}

void printHelp(){
    printf("Commands:\n");
    printf("Help: h\n");
    printf("Quit: q\n");
    printf("Draw line: w row_start col_start row_end col_end\n");
    printf("Resize: r num_rows num_cols\n");
    printf("Add row or column: a [r | c] pos\n");
    printf("Delete row or column: d [r | c] pos\n");
    printf("Erase: e row col\n");
    printf("Save: s file_name\n");
    printf("Load: l file_name\n");
}


/*
 * === Tucker's Attempt at dynamic input ===
void commandChecker(char * commandArgs[], argsNeeded ) {
    numsRead = 0;
    commmandArgs[argsNeeded];
    char currentRead;

    while(currentRead != '\n'){

        scanf(" %c", &currentRead);
        commandArgs[numRead] = currentRead;

        numRead++;
    }
    if(numRead != argsNeeded) {
        printf("Wrong number of command line arguements entered.\n");
        printf("Usage: ./paint.out [num_rows num_cols]\n");
    }
}
 */

/*   === Andrew's Dynamic Overflow ====
void getCommand(char** canvas, const int num_rows, const int num_columns, const char blank_space, char *command,
             int* row, int* col) {
    int num_args_read = 1;
    int num_args_needed = 1;

    int charCount = 0;
    int intCount = 0;

    do {c
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
 */

