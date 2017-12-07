//
// Created by Andrew Eeckman on 12/5/17.
//

#include "command.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void getCommand(char** canvas, const int numRows, const int numColumns, const char blank_space, char *command,
             int *row_start, int *col_start, int *row_end, int *col_end,
                int *num_rows, int *num_cols,
                char *rowOrCol, int *pos,
                int *row, int *col,
                char fileName[]) {

    int num_args_read = 0;
    int num_args_needed = 0;

    bool invalidCommand = false;

    do {
        printf("Enter your command: ");
        scanf("%c", &(*command));

        if(*command == 'q') {
            num_args_needed = 0;
            num_args_read = scanf("");


        } else if (*command == 'h') {
            num_args_needed = 0;
            num_args_read = scanf("");


        } else if(*command == 'w') {
            num_args_needed = 4;
            num_args_read = scanf(" %d %d %d %d", row_start, col_start, row_end, col_end);

            printf("\n%c %d %d %d %d", *command, *row_start, *col_start, *row_end, *col_end);
            /*
            *num_rows = NULL;    *row = NULL;
            *num_cols = NULL;    *col = NULL;
            *rowOrCol = NULL;    *fileName = NULL;
            *pos = NULL;
            */
        } else if(*command == 'r') {
            num_args_needed = 2;
            num_args_read = scanf(" %d %d", num_rows, num_cols);

        }  else if(*command == 'a') {
            num_args_needed = 2;
            num_args_read = scanf(" %c %d", rowOrCol, pos);

        } else if(*command == 'd') {
            num_args_needed = 2;
            num_args_read = scanf(" %c %d", rowOrCol, pos);

        } else if(*command == 'e') {
            num_args_needed = 2;
            num_args_read = scanf(" %d %d", row, col);

        }  else if(*command == 's') {
            num_args_needed = 1;
            num_args_read = scanf(" %s", fileName);

        }   else if(*command == 'l') {
            num_args_needed = 1;
            num_args_read = scanf(" %s", fileName);

        } else {
            invalidCommand = true;
        }

    } while(!isValidCommand(num_args_read, num_args_needed,
                            canvas, numRows, numColumns, blank_space, command,
                            row_start, col_start, row_end, col_end,
                            num_rows, num_cols,
                            rowOrCol, pos,
                            row, col,
                            fileName));

}

bool isValidCommand(int num_args_read, int num_args_needed,
                    char** canvas, const int numRows, const int numColumns, const char blank_space, char *command,
                    int *row_start, int *col_start, int *row_end, int *col_end,
                    int *num_rows, int *num_cols,
                    char *rowOrCol, int *pos,
                    int *row, int *col,
                    char fileName[]) {
    return false;

}



void quitProg() {
    exit(0);
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