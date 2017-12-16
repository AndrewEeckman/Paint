//
// Created by Andrew Eeckman on 12/5/17.
//

#ifndef PAINT_CANVAS_H
#define PAINT_CANVAS_H

void displayCanvas(char** canvas, int num_rows, int num_cols);
char** createCanvas( int num_rows, int num_cols, const char blank_space);
void increaseCanvas (char** canvas,  int *num_rows,  int *num_cols,  int *new_rows, int *new_cols, const char blank_space);
void cleanUp(char*** canvas,  int num_rows,  int num_cols);

#endif //PAINT_CANVAS_H
