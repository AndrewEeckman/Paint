//
// Created by Tucker on 12/11/17.
//

#include "lineMod.h"
#include <stdlib.h>


void lineAdd (char ** canvas, int * num_rows, int * num_cols, int * new_rows, int * new_cols, const char blank_space, const int rowNumber) {
        char * holder = canvas[*num_rows-1];
        char ** newCanvas = (char**)malloc((*num_rows + 1) * sizeof(char*));
    for( int row = 0; row <= (*num_rows + 1); row++)                                         {
        canvas[*num_rows - row] = canvas[*num_rows - row - 1];

    }

    // last line -> holder
    // 2nd to last line ->  last line
    // 3rd to last -> 2nd to last
    // line 3


}


