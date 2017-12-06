#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "canvas.h"
#include "command.h"
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
    const char pieces[] = "/-+\|";  // / and \ is diagonal, - is horizontal, | is vertical, + is intersecting
    const int numRows = r;          // How "Tall" the canvas is
    const int numCols = c;          // How "Wide" the canvas is
    char** canvas = createCanvas(numRows, numCols, blankSpace);

    // Function called to display the starting canvas
    displayCanvas(canvas, numRows, numCols);

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
    char rowOrCol;      // a r|c ___ // d r|c ___
    int pos = 0;        // a ___ x|y // d ___ x|y

    // Variables used by the [e]rase command
    int row = 0;        // e r _
    int col = 0;        // e _ c

    // Variables used by the [s]ave and [l]oad commands
    char fileName[1024];    //(s|l) file_name

    /* End of Variables used by Commands */

    /////////////////////////////////////////////////////////////////////////////////////////////
    /* Begin Nerve Center */
    //do {

        displayCanvas(canvas, numRows, numCols);

        getCommand(canvas, numRows, numCols, blankSpace, &command, &row, &col);
        /*
        makeMove(board, rowPlayed, colPlayed, pieces[playerTurn]);
        playerTurn = changeTurn(playerTurn);
         */

    //} while(!quitProgram());

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
    }
    return false;
}