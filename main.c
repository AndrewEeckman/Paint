#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "canvas.h"
#include "command.h"
#include "draw.h"
#include "lineMod.h"
#include "fileIO.h"

bool inputChecker(int passArgs, char** argv);

int main(int argc, char** argv) {
    /////////////////////////////////////////////////////////////////////////////////////////////
    /* Start of Code for Input Checker */

    int r = 0;
    int c = 0;

    if (inputChecker(argc, argv)) {
        r = atoi(argv[1]);
        c = atoi(argv[2]);

    } else {
        r = 10;
        c = 10;
    }
    /* End of Code for Input Checker */
    /////////////////////////////////////////////////////////////////////////////////////////////
    /* Variables used for canvas display */

    const char blankSpace = '*';    // For when nothing is drawn at (x, y)
    const char pieces[] = "/-+\\|";  // / and \ is diagonal, - is horizontal, | is vertical, + is intersecting
    int numRows = r;          // How "Tall" the canvas is
    int numCols = c;          // How "Wide" the canvas is
    char** canvas = createCanvas(numRows, numCols, blankSpace);

    /* End of variables used for canvas display */
    /////////////////////////////////////////////////////////////////////////////////////////////
    /* Beginning of Variables used by Commands */

    char command = ' '; // h, q, w, r, a, d, e, s, l

    // Variables used by the [w]rite command
    int row_start = 0;  // w x _ _ _
    int col_start = 0;  // w _ y _ _
    int row_end = 0;    // w _ _ x _
    int col_end = 0;    // w _ _ _ y

    // Variables used by the [r]esize command
    int num_rows = 0;   // r x _
    int num_cols = 0;   // r _ y

    // Variables used by the [a]dd and [d]elete commands
    char rowOrCol = ' ';      // a r|c ___ // d r|c ___
    int pos = 0;        // a ___ x|y // d ___ x|y

    // Variables used by the [e]rase command
    int row = 0;        // e r _
    int col = 0;        // e _ c

    // Variables used by the [s]ave and [l]oad commands
    char fileName[1024] = " ";    //(s|l) file_name

    /* End of Variables used by Commands */

    /////////////////////////////////////////////////////////////////////////////////////////////
    /* Begin Nerve Center */
    do {

        displayCanvas(canvas, numRows, numCols);

        getCommand(canvas, numRows, numCols, blankSpace, &command,
                   &row_start, &col_start, &row_end, &col_end,
                   &num_rows, &num_cols,
                   &rowOrCol, &pos,
                   &row, &col, &(*fileName)
                    );

        //Write Command
        if(command == 'w') {
            determineLine(canvas, numRows, numCols, pieces, blankSpace, row_start, col_start, row_end, col_end);
        }

        //Erase Command
        else if(command == 'e') {
            erase(canvas, numRows, numCols, pieces, blankSpace, row, col);

        }

        //Resize Command
        else if(command == 'r') {
            increaseCanvas(canvas, &numRows,  &numCols,  &num_rows,  &num_cols, blankSpace);
        }

        //Add Command
        else if(command == 'a') { //add row or collumn
            if (rowOrCol == 'r'){
                rowAdd(canvas, &numRows, &numCols, blankSpace, pos);
            } else if(rowOrCol == 'c') {
                colAdd(canvas, &numRows, &numCols, blankSpace, pos);
            }

        }

        //Delete Command
        else if(command == 'd') {
            if(rowOrCol == 'r') {
                deleteRow(canvas, &numRows, &numCols, &pos);
            } else if(rowOrCol == c) {
                deleteCol(canvas, &numRows, &numCols, &pos);
            }
        }

        //Save Command
        else if(command == 's') {
            saveToFile(canvas, &numRows, &numCols, fileName);
        }

        //Load Command
        else if(command == 'l') {
            loadSelectFile(canvas, &numRows, &numCols, fileName);
        }


    } while(command != 'q');


    cleanUp(&canvas, numRows, numCols);

    return 0;
}

bool inputChecker(int passArgs, char **argv) {

    if(passArgs == 1)
    {
        return false;
    }
    else if(passArgs == 3)
    {
        int x = atoi(argv[1]);
        int y = atoi(argv[2]);
        if (isalpha(*argv[1])) {
            printf("The number of rows is not an integer.\nMaking default board of 10 X 10.");
            return false;
        } else if (isalpha(*argv[2])) {
            printf("The number of columns is not an integer.\nMaking default board of 10 X 10.");
            return false;
        }

        if (y < 1) {
            printf("The number of columns is less than 1.\nMaking default board of 10 X 10.");
            return false;
        } else if (x < 1) {
            printf("The number of rows is less than 1.\nMaking default board of 10 X 10.");
            return false;
        }

        return true;

    } else if(passArgs != 4) {
        printf("Wrong number of command line arguments entered.\nUsage: ./paint.out [num_rows num_cols]\nMaking default board of 10 X 10.");
        return false;
    } else if(strlen(argv[2]) > 3 || strlen(argv[3]) > 3) {
        printf("Wrong number of command line arguements entered.\nUsage: ./paint.out [num_rows num_cols]\nMaking default board of 10 X 10.");
        return false;
    } else {
        int x = atoi(argv[1]);
        int y = atoi(argv[2]);

        if (y < 1) {
            printf("The number of columns is less than 1.\nMaking default board of 10 X 10.");
            return false;
        } else if (x < 1) {
            printf("The number of rows is less than 1.\nMaking default board of 10 X 10.");
            return false;
        }

        return true;
    }
}