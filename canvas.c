#include <stdlib.h>
#include <stdio.h>
#include "canvas.h"

void displayCanvas(char** canvas, const int num_rows, const int num_cols) {
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

char** createCanvas(const int num_rows, const int num_cols, const char blank_space) {
    char** canvas = (char**) malloc(num_rows * sizeof(char*));
    for(int row = 0; row < num_rows; ++row){
        canvas[row] = (char*) malloc(num_cols * sizeof(char));
        for (int col = 0; col < num_cols; ++col) {
            canvas[row][col] = blank_space;
        }
    }
    return canvas;
}
void cleanUp(char*** canvas, const int num_rows, const int num_cols) {
    for(int row = 0; row < num_rows; ++row){
        free((*canvas)[row]);
    }
    free(*canvas);
    *canvas = NULL;
}