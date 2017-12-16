#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "canvas.h"
#include "command.h"
#include "draw.h"
#include "lineMod.h"
#include "inputValidation.h"
#include <string.h>

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

        /*
        printf("Command: %c\n", command);

        printf("Variables used by the [w]rite command\n");
        printf("row_start: %d\n", row_start);
        printf("col_start: %d\n", col_start);
        printf("row_end: %d\n", row_end);
        printf("col_end: %d\n", col_end);

        printf("Variables used by the [r]esize command\n");
        printf("num_rows: %d\n", num_rows);
        printf("num_cols: %d\n", num_cols);

        printf("Variables used by the [a]dd and [d]elete commands\n");
        printf("rowOrCol: %c\n", rowOrCol);
        printf("pos: %d\n", pos);

        printf("Variables used by the [e]rase command\n");
        printf("row: %d\n", row);
        printf("col: %d\n", col);

        printf("Variables used by the [s]ave and [l]oad commands\n");
        printf("fileName: %s", fileName);
        */

        if(command == 'w') {
            determineLine(canvas, numRows, numCols, pieces, blankSpace, row_start, col_start, row_end, col_end);
        } else if(command == 'r') {
            //increaseCanvas(canvas, &numRows, &numCols, num_rows, num_cols, blankSpace);
            //increaseCanvas(canvas, &numRows, &numCols, num_rows, num_cols, blankSpace);
        } else if(command == 'a') { //add row or collumn
            row_or_col(canvas, numRows, numCols, blankSpace, rowOrCol, pos);
                if (rowOrCol == 'r'){
                    numRows++;
                } else if(rowOrCol == 'c') {
                    numCols++;
                }
        } else if(command == 'e') {
            erase(canvas, numRows, numCols, pieces, blankSpace, row, col);

        }


        /*
        makeMove(board, rowPlayed, colPlayed, pieces[playerTurn]);
        playerTurn = changeTurn(playerTurn);
         */

    } while(command != 'q');

         /*
    displayBoard(board, numRows, numCols);
    declareEndResult(playerTurn, board, numRows, numCols, blankSpace, w);
         */

    cleanUp(&canvas, numRows, numCols);

    return 0;
}

bool inputChecker(int passArgs, char **argv) {

    if (passArgs == 3) {
        int x = atoi(argv[1]);
        int y = atoi(argv[2]);

        if(x > 0 && y > 0) {
            return true;
        }
    } else if(passArgs == 1) {

        return false;

    } else {

        printf("Wrong number of command line arguements entered.\n");
        printf("Usage: ./paint.out [num_rows num_cols]\n");
        return false;
    }
}