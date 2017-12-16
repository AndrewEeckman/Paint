//
// Created by Andrew Eeckman on 12/5/17.
//

#ifndef PAINT_COMMAND_H
#define PAINT_COMMAND_H

#include <stdbool.h>

void getCommand(char** canvas, int numRows, int numColumns, const char blank_space, char *command,
                int *row_start, int *col_start, int *row_end, int *col_end, int *num_rows, int *num_cols, char *rowOrCol, int *pos, int *row, int *col, char fileName[]);

bool isValidCommand(int num_args_read, int num_args_needed,
                    char** canvas, int numRows, int numColumns, const char blank_space, char *command,
                    int *row_start, int *col_start, int *row_end, int *col_end,
                    int *num_rows, int *num_cols,
                    char *rowOrCol, int *pos,
                    int *row, int *col,

                    char fileName[]);

void quitProg();
void printHelp();

#endif //PAINT_COMMAND_H
