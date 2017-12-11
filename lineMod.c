//
// Created by Tucker on 12/11/17.
//

#include "lineMod.h"


void lineAdd (char ** canvas, int * num_rows, int * num_cols, int * new_rows, int * new_cols, const char blank_space, const int rowNumber) {
        char * holder = canvas[*num_rows-1];
    for( int row = rowNumber - 1; row <= *num_rows; row++) {
        canvas[*num_rows - row] = canvas[*num_rows - row - 1];
    }

    // last line -> holder
    // 2nd to last line ->  last line
    // 3rd to last -> 2nd to last
    // line 3


}


