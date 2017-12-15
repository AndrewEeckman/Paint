//
// Created by Tucker on 12/11/17.
//

#include "lineMod.h"
#include <stdlib.h>

void row_or_col(char ** canvas, int * num_rows, int * num_cols, const char blank_space, const char rowOrCol, const int lineNumber){
    if(rowOrCol == 'c') {
        colAdd( canvas, num_rows, num_cols,  blank_space, lineNumber);
    } else if (rowOrCol == 'r') {
        rowAdd( canvas, num_rows, num_cols,  blank_space, lineNumber);
    } else {

    }
}

void colAdd (char ** canvas, int * num_rows, int * num_cols, const char blank_space, const int colNumber){

}

void rowAdd (char ** canvas, int * num_rows, int * num_cols, const char blank_space, const int rowNumber) {
    char ** tempCanvas = (char**)malloc((*num_rows) * sizeof(char*));
        for(int i = 0; i <*num_rows; i++) {
            tempCanvas[i] = (char*)malloc((*num_cols) * sizeof(char*));
            for(int j = 0; j < *num_cols; j ++){
                canvas[i][j] = tempCanvas[i][j];
            }
        }
    canvas = (char**)realloc(canvas, (*num_rows+1)*sizeof(char*));
    for( int row = 0; row <= (*num_rows + 1); row++) {
        canvas[row] = (char*)realloc(canvas[row], sizeof(char*));
            for (int col = 0; col <= *num_cols; col++) {
                if (row == rowNumber) {
                    canvas[row][col] = blank_space;
                } else {
                    canvas[row][col] = tempCanvas[row][col];
                }
            }
        free(tempCanvas[row]);
    }
    free(tempCanvas);
}

