//
// Created by Tucker on 12/11/17.
//

#ifndef PAINT_LINEMOD_H
#define PAINT_LINEMOD_H


void colAdd (char ** canvas, int *num_rows, int * num_cols, const char blank_space, const int colNumber);
void rowAdd (char ** canvas,  int *num_rows,  int *num_cols, const char blank_space, const int rowNumber);
void deleteRow(char ** canvas, int *numRows, int *numCols, int pos);
void deleteCol(char ** canvas, int *numRows, int *numCols, int pos);


#endif //PAINT_LINEMOD_H
