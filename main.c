#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "canvas.h"
#include "command.h"

//void checkConditions(int argc, char **argv);

bool inputChecker(int passArgs, char** argv);

int main(int argc, char** argv) {

    int row = 0;
    int col = 0;

    if (inputChecker(argc, argv)) {
        row = atoi(argv[1]);
        col = atoi(argv[2]);

    } else {
        row = 10;
        col = 10;
    }

    const char blankSpace = '*';
    const char pieces[] = "/-+\|";

    const int numRows = row;
    const int numCols = col;

    char command = ' ';

    char** canvas = createCanvas(numRows, numCols, blankSpace);
    displayCanvas(canvas, numRows, numCols);

    int playerTurn = 0;

    char c = ' ';

    //do {

        displayCanvas(canvas, numRows, numCols);

        //getCommand(canvas, numRows, numCols, blankSpace, &command, &rowPlayed, &colPlayed);
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