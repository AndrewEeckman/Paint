//
// Created by Andrew Eeckman on 12/5/17.
//

#include "command.h"
#include <stdio.h>
#include <stdlib.h>

void getArgsByCommand(char command, int *numArgsNeeded, int *charCount, int *intCount);

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