//
// Created by Andrew Eeckman on 12/5/17.
//

#ifndef PAINT_CANVAS_H
#define PAINT_CANVAS_H

void displayCanvas(char** canvas, const int num_rows, const int num_cols, const int rowsViewable, const int colsViewable);
char** createCanvas(const int num_rows, const int num_cols, const char blank_space);
void increaseCanvas (char** canvas, const int num_rows, const int num_cols, const int new_rows, const int new_cols, const char blank_space);
        void cleanUp(char*** canvas, const int num_rows, const int num_cols);

#endif //PAINT_CANVAS_H
