//
// Created by Tucker on 12/6/17.
//

int pickABrush(int xCoord1, int yCoord1, int xCoord2, int yCoord2) { //Function in charge of picking draw funciton is going to be used
    if () { //Horizontal line drawing

    } else if (){ //Vertical Line Drawing

    } else if (){
        /*      /
         *    /
         *  /
         */



    } else if () {
        /*\
         * \
         *  \
         *   \
         */

        for(int i = xcoord1)




// Created by Andrew Eeckman on 12/6/17.
//

#include "draw.h"
#include <stdio.h>
#include <stdlib.h>

void determineLine(char** canvas, const int numRows, const int numCols, const char* pieces, const char blankspace, const int row_start, const int col_start, const int row_end, const int col_end) {
    int rise = 0;
    int run = 0;

    int slope = 0;

    rise = row_end - row_start;
    run = col_end - col_start;

    if(rise != 0 && run != 0) {
        slope = rise / run;
    }

    if(slope == -1 && rise % run == 0) {
        drawAscendingDiagonal(canvas, numRows, numCols, pieces, blankspace, row_start, col_start, row_end, col_end, rise, run);
    } else if(slope == 1 && rise % run == 0) {
        drawDescendingDiagonal(canvas, numRows, numCols, pieces, blankspace, row_start, col_start, row_end, col_end, rise, run);
    } else if(rise != 0 && run == 0) {
        drawVertical(canvas, numRows, numCols, pieces, blankspace, row_start, col_start, row_end, col_end, rise, run);
    } else if(rise == 0 && run != 0) {
        drawHorizontal(canvas, numRows, numCols, pieces, blankspace, row_start, col_start, row_end, col_end, rise, run);
    } else {
        printf("Invalid line attempted to be drawn");
    }
}

void drawAscendingDiagonal(char** canvas, const int numRows, const int numCols, const char* pieces, const char blankspace,
                           const int row_start, const int col_start, const int row_end, const int col_end, int rise, int run) {

}

void drawDescendingDiagonal(char** canvas, const int numRows, const int numCols, const char* pieces, const char blankspace,
                            const int row_start, const int col_start, const int row_end, const int col_end, int rise, int run) {

}

void drawHorizontal(char** canvas, const int numRows, const int numCols, const char* pieces, const char blankspace,
                    const int row_start, const int col_start, const int row_end, const int col_end, int rise, int run) {
    for(int i = 0; i < run; i ++) {
        if(canvas[row_start][col_start + i] != blankspace) {
            canvas[row_start][col_start + i] = '+';
        } else {
            canvas[row_start][col_start + i] = '-';
        }
    }
}

void drawVertical(char** canvas, const int numRows, const int numCols, const char* pieces, const char blankspace,
                  const int row_start, const int col_start, const int row_end, const int col_end, int rise, int run) {
    for(int i = 0; i < rise; i ++) {
        if(canvas[row_start + i][col_start] != blankspace) {
            canvas[row_start + i][col_start] = '+';
        } else {
            canvas[row_start + i][col_start] = '-';
        }
    }
}