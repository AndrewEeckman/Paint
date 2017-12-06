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

    // Counters to receive a particular number of chars and ints from the line
    // FIXME: CANNOT DETECT OVERFLOW!!!!!
    int charCount = 0;
    int intCount = 0;

    // Second Character used for the Addition & Deletion Commands
    char comSubsetForAddDel = ' ';


    //do {
        printf("Enter your command: ");
        scanf("%c", &(*command));

        // Function to sort each command and assign it a specific number of chars, ints, and args needed
        getArgsByCommand(*command, &num_args_needed, &charCount, &intCount);

        // Creates an array containing all ints entered on the line
        // FIXME: BASED ON NUM OF INTS ASSIGN VALUES TO POINTERS SUCH AS ROW AND COL AND COORDINATES
        int arrayOfInts[intCount];

        for(int i = 1; i < num_args_needed; i++) {
            if(charCount != 0) {
                scanf(" %c", &comSubsetForAddDel);
                i++;
            }
            if(intCount != 0) {
                for(int j = 0; j < intCount; j++) {
                    scanf(" %d", &arrayOfInts[j]);
                    i++;
                }
            }
        }

        // FIXME: REMOVE, ONLY PRINTS THE LINE ENTERED
        for(int i = 0; i < num_args_needed; i++) {
            if(i == 0) {
                printf("%c", *command);
            } else if(i == 1 && charCount == 1) {
                printf(" %c", comSubsetForAddDel);
            } else if(i == 1 && charCount == 0){
                printf(" %d", arrayOfInts[0]);
            } else {
                printf(" %d", arrayOfInts[i-1]);
            }
        }
        printf("\n");

    //} while(!isValidCommand(num_args_read, num_args_needed, canvas, num_rows, num_columns, *col, *row, blank_space));
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

