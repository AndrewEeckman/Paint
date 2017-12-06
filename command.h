//
// Created by Andrew Eeckman on 12/5/17.
//

#ifndef PAINT_COMMAND_H
#define PAINT_COMMAND_H

void getCommand(char** canvas, const int numRows, const int numColumns, const char blank_space, char *command,
                int *row_start, int *col_start, int *row_end, int *col_end, int *num_rows, int *num_cols, char *rowOrCol, int *pos, int *row, int *col, char fileName[]);
#endif //PAINT_COMMAND_H
