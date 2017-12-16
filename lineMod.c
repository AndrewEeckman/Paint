//
// Created by Tucker on 12/11/17.
//

#include <stdlib.h>
#include <stdio.h>

#include "lineMod.h"

void colAdd (char ** canvas, int* num_rows, int * num_cols, const char blank_space, const int colNumber){

    (*num_cols)++;

    int i, j;

    for(i = 0; i < (*num_rows); i++) {
        canvas[i] = (char*)realloc(canvas[i], *num_cols * sizeof(char));

        for(j = (*num_cols)-1; j > colNumber; j--) {
            canvas[i][j] = canvas[i][j-1];
        }

        canvas[i][j] = blank_space;
    }
}

//FIXME: Memory out of Bound
void rowAdd(char** canvas, int *num_rows, int *num_cols, const char blank_space, const int rowNumber) {

    (*num_rows)++;

    canvas = (char**)realloc(canvas, (*num_rows+1) * sizeof(char*));

    int i, j;

    for(i = *num_rows - 1; i > rowNumber; i--) {
         canvas[i] = canvas[i - 1];
    }

    canvas[rowNumber] = (char*)malloc(*num_cols * sizeof(char));
    for(j = 0; j < *num_cols; j++) {
        canvas[i][j] = blank_space;
    }
}

void deleteRow(char** canvas, int *numRows, int *numCols, int pos) {

    free(canvas[(*numRows-1)-pos]);
    (*numRows)--;
    printf("numrows = %d\n", *numRows);
    for(int i = pos; i < (*numRows); i++) {
        canvas[i] = canvas[i + 1];
    }

    canvas = (char**)realloc(canvas, (*numRows) * sizeof(char*));
}


//FIXME: Doesn't work
void deleteCol(char ** canvas, int *numRows, int *numCols, int pos) {

    for(int row = 0; row < (*numRows); row++) {
        canvas[row][pos] = NULL;
    }

    (*numCols)--;

    for(int i = 0; i < (*numRows); i++) {
        for(int j = pos; j < *numCols; j++) {
            canvas[i][j] = canvas[i][j+1];
        }

        canvas[i] = (char*)realloc(canvas[i], (*numCols) * sizeof(char));
    }
}


