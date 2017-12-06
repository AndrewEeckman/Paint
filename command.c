//
// Created by Andrew Eeckman on 12/5/17.
//

#include "command.h"
#include <stdio.h>
#include <stdlib.h>


void getCommand(char** canvas, const int numRows, const int numColumns, const char blank_space, char *command,
             int *row_start, int *col_start, int *row_end, int *col_end,
                int *num_rows, int *num_cols,
                char *rowOrCol, int *pos,
                int *row, int *col,
                char fileName[]) {

    int num_args_read = 1;
    int num_args_needed = 1;

    //do {
        printf("Enter your command: ");
        scanf("%c", &(*command));

        if(*command == 'w') {
            num_args_needed = 4;
            num_args_read = scanf(" %d %d %d %d", row_start, col_start, row_end, col_end);

            if(num_args_read != num_args_needed) {
                printf("NOOOOOOO");
            } else {
                printf("\n%c %d %d %d %d", *command, *row_start, *col_start, *row_end, *col_end);
            }

        }


        printf("\n");

    //} while(!isValidCommand(num_args_read, num_args_needed, canvas, num_rows, num_columns, *col, *row, blank_space));
}