#include <stdlib.h>
#include <stdio.h>

#include "canvas.h"

void displayCanvas(char** canvas, int num_rows, int num_cols) {
    // print column headers

    printf("\n");
    // print board
    for (int row = 0; row < num_rows; ++row) {
        printf("%d ", (num_rows-row)-1);  // row header
        for (int col = 0; col < num_cols; ++col) {
            printf("%c ", canvas[row][col]);
        }
        printf("\n");
    }

    printf("  ");

    for(int col = 0; col < num_cols; ++col){
        printf("%d ", col);
    }

    printf("\n");
}

char** createCanvas( int num_rows,  int num_cols, const char blank_space) {
    char** canvas = (char**) malloc(num_rows * sizeof(char*));
    for(int row = 0; row < num_rows; ++row){
        canvas[row] = (char*) malloc(num_cols * sizeof(char));
        for (int col = 0; col < num_cols; ++col) {
            canvas[row][col] = blank_space;
        }
    }
    return canvas;
}


//FIXME: Exception
void increaseCanvas(char** canvas,  int *num_rows,  int *num_cols,  int *new_rows,  int *new_cols, const char blank_space) {
    int i, j;

    for(i = (*new_rows); i < (*num_rows); i++) {
        free(canvas[i]);
        *canvas[i] = NULL;
    }

    canvas = (char**)realloc(canvas, (*new_rows) * sizeof(char*));
    for(i = *num_rows; i < *new_rows; i++) {
        canvas[i] = (char*)malloc((*new_cols)*sizeof(char));
        for(j = 0; j < *new_cols; j++) {
            canvas[i][j] = blank_space;
        }
    }

    for(i = 0; i < *new_rows; i++) {
        canvas[i] = (char*)realloc(canvas[i], *new_cols * sizeof(char));
        for(j = *num_cols; j < *new_cols; j++) {
            canvas[i][j] = blank_space;
        }
    }

    *num_cols = *new_cols;
    *num_rows = *new_rows;
}



void cleanUp(char*** canvas,  int num_rows,  int num_cols) {
    for(int row = 0; row < num_rows; ++row){
        free((*canvas)[row]);
    }
    free(*canvas);
    *canvas = NULL;
}