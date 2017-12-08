//
// Created by Andrew Eeckman on 12/6/17.
//

#ifndef PAINT_DRAW_H
#define PAINT_DRAW_H

void determineLine(char** canvas, const int numRows, const int numCols, const char* pieces, const char blankspace, const int row_start, const int col_start, const int row_end, const int col_end);
void drawAscendingDiagonal(char** canvas, const int numRows, const int numCols, const char* pieces, const char blankspace, const int row_start, const int col_start, const int row_end, const int col_end, int rise, int run);
void drawDescendingDiagonal(char** canvas, const int numRows, const int numCols, const char* pieces, const char blankspace, const int row_start, const int col_start, const int row_end, const int col_end, int rise, int run);
void drawHorizontal(char** canvas, const int numRows, const int numCols, const char* pieces, const char blankspace, const int row_start, const int col_start, const int row_end, const int col_end, int rise, int run);
void drawVertical(char** canvas, const int numRows, const int numCols, const char* pieces, const char blankspace, const int row_start, const int col_start, const int row_end, const int col_end, int rise, int run);

#endif //PAINT_DRAW_H
