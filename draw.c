//
// Created by Tucker and Andrew Eeckman on 12/6/17.
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

    if(slope == 1 && rise % run == 0) {
        drawAscendingDiagonal(canvas, numRows, numCols, pieces, blankspace, row_start, col_start, row_end, col_end, rise, run);
    } else if(slope == -1 && rise % run == 0) {
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
        /*   /
         *  /
         * /
        */
    if(row_end > row_start) {
        for (int i = row_start; i <= row_end; i++) {

            if (canvas[numRows - i - 1][col_start + i - (row_start)] == blankspace) {
                canvas[numRows - i - 1][col_start + i - (row_start)] = pieces[0];
            } else {
                canvas[numRows - i - 1][col_start + i - (row_start)] = pieces[2];
            }
        }
    } else if(row_start > row_end) {
        for (int i = row_end; i <= row_start; i++) {

            if (canvas[numRows - i - 1][col_start + i - (row_start)] == blankspace) {
                canvas[numRows - i - 1][col_start + i - (row_start)] = pieces[0];
            } else {
                canvas[numRows - i - 1][col_start + i - (row_start)] = pieces[2];
            }
        }
    }
}

void drawDescendingDiagonal(char** canvas, const int numRows, const int numCols, const char* pieces, const char blankspace,
                            const int row_start, const int col_start, const int row_end, const int col_end, int rise, int run) {
        /* \
         *  \
         *   \
         */

    if(row_start > row_end) {
        rise = row_start - row_end;

        for (int i = row_end; i <= row_start; i++) {
            if (canvas[numRows - row_start - 1 + i][col_start + i] != blankspace) {
                canvas[numRows - row_start - 1 + i][col_start + i] = '+';
            } else {
                canvas[numRows - row_start - 1 + i][col_start + i] = '\\';
            }
        }
    } else if(row_end > row_start) {
        rise = row_end - row_start;

        for (int i = row_start; i <= row_end; i++) {
            if (canvas[numRows - row_start - 1 - i][col_start - i] != blankspace) {
                canvas[numRows - row_start - 1 - i][col_start - i] = '+';
            } else {
                canvas[numRows - row_start - 1 - i][col_start - i] = '\\';
            }
        }
    }


}

void drawHorizontal(char** canvas, const int numRows, const int numCols, const char* pieces, const char blankspace,
                    const int row_start, const int col_start, const int row_end, const int col_end, int rise, int run) {

    if(col_start > col_end) {
        for (int i = col_end; i <= col_start; i++) {
            if (canvas[numRows - row_start - 1][col_end + i] != blankspace) {
                canvas[numRows - row_start - 1][col_end + i] = '+';
            } else if (canvas[numRows - row_start - 1][col_end + i] == blankspace) {
                canvas[numRows - row_start - 1][col_end + i] = '-';
            }
        }
    } else if(col_end > col_start) {
        for (int i = 0; i <= run; i++) {
            if (canvas[numRows - row_start - 1][col_start + i] != blankspace) {
                canvas[numRows - row_start - 1][col_start + i] = '+';
            } else if (canvas[numRows - row_start - 1][col_start + i] == blankspace) {
                canvas[numRows - row_start - 1][col_start + i] = '-';
            }
        }
    }
}

void drawVertical(char** canvas, const int numRows, const int numCols, const char* pieces, const char blankspace,
                  const int row_start, const int col_start, const int row_end, const int col_end, int rise, int run) {
    int tempRow = 0;
    int rowS = row_start;
    int rowE = row_end;

    if(rowS > rowE) {
        tempRow = rowE;
        rowE = rowS;
        rowS = tempRow;
    }

    rise = rowE - rowS;

    for(int i = 0; i <= rise; i ++) {
        if(canvas[numRows - i - 1][col_start] != blankspace) {
            canvas[numRows - i - 1][col_start] = '+';
        } else {
            canvas[numRows - i - 1][col_start] = '|';
        }
    }
}