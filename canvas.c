#include <stdlib.h>
#include <stdio.h>
#include "canvas.h"

void displayCanvas(char** canvas, const int num_rows, const int num_cols, const int rowsViewable, const int colsViewable) {
    // print column headers

    printf("\n");
    // print board
    for (int row = 0; row < rowsViewable; ++row) {
        printf("%d ", (num_rows-row)-1);  // row header
        for (int col = 0; col < colsViewable; ++col) {
            printf("%c ", canvas[row][col]);
        }
        printf("\n");
    }

    printf("  ");

    for(int col = 0; col < colsViewable; ++col){
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

void increaseCanvas(char** canvas, const int num_rows, const int num_cols, const int new_rows, const int new_cols, const char blank_space) {
    canvas = (char**)realloc(canvas, new_rows * sizeof(char*));
    for(int i = 0; i < num_rows; i ++) {
        canvas[i] = (char*)realloc(canvas[i], new_cols* sizeof(char));
    }
    for(int j = num_rows; j < new_rows; j++) {
        canvas[j] = (char*)realloc(canvas[j], new_cols * sizeof(char));
        for (int newCol = num_cols; newCol < new_cols; newCol++) {
            canvas[j][newCol] = blank_space;
        }
    }
}



void cleanUp(char*** canvas, const int num_rows, const int num_cols) {
    for(int row = 0; row < num_rows; ++row){
        free((*canvas)[row]);
    }
    free(*canvas);
    *canvas = NULL;
}