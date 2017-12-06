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



/*  === Tucker's Attempt at dynamic input ===
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

// === Andrew's Dynamic Overflow ====
void getCommand(char** canvas, const int num_rows, const int num_columns, const char blank_space, char *command,
             int* row, int* col) {
    int num_args_read = 1;
    int num_args_needed = 1;

    // Counters to receive a particular number of chars and ints from the line
    // FIXME: CANNOT DETECT OVERFLOW!!!!!
    int charCount = 0;
    int intCount = 0;

    // Second Character used for the Addition & Deletion Commands
    char comSubsetForAddDel = ' ';


    //do {
        printf("Enter your command: ");
        scanf("%c", &(*command));

        int *x1, *y1, *x2, *y2;

        if(*command == 'w') {
            num_args_needed = 4;
            num_args_read = scanf(" %d %d %d %d", x1, y1, x2, y2);

            if(num_args_read != num_args_needed) {
                printf("NOOOOOOO");
            } else {
                printf("\n%c %d %d %d %d", *command, *x1, *y1, *x2, *y2);
            }

        }


        printf("\n");

    //} while(!isValidCommand(num_args_read, num_args_needed, canvas, num_rows, num_columns, *col, *row, blank_space));

}
