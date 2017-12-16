//
// Created by Tucker on 12/11/17.
//

#ifndef PAINT_LINEMOD_H
#define PAINT_LINEMOD_H


void row_or_col(char ** canvas, int num_rows, int num_cols, const char blank_space, const char rowOrCol, const int lineNumber);
void colAdd (char ** canvas, int * num_rows, int * num_cols, const char blank_space, const int colNumber);
void rowAdd (char ** canvas,  int num_rows,  int num_cols, const char blank_space, const int rowNumber);


#endif //PAINT_LINEMOD_H
