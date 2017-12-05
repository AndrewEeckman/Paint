#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//void checkConditions(int argc, char **argv);

bool inputChecker(int passArgs);

int main(int argc, char** argv) {
    const char blankSpace = '*';
    const char pieces[] = "/-+\|";

    const int numRows = 10;
    const int numCols = 10;

    int rowPlayed;
    int colPlayed;

    char** board = createBoard(numRows, numCols, blankSpace);

    int playerTurn = 0;

    do {

        displayBoard(board, numRows, numCols);

        getMove(board, numRows, numCols, blankSpace, &rowPlayed, &colPlayed);
        makeMove(board, rowPlayed, colPlayed, pieces[playerTurn]);
        playerTurn = changeTurn(playerTurn);

    } while(!isGameOver(board, numRows, numCols, blankSpace, w));

    displayBoard(board, numRows, numCols);
    declareEndResult(playerTurn, board, numRows, numCols, blankSpace, w);

    cleanUp(&board, numRows, numCols);

    return 0;
}

bool inputChecker(int passArgs) {
    if (passArgs < 4) {
        printf("Not enough arguments entered\n");
        printf("Usage connectn.out num_rows num_columns");
        printf(" number_of_pieces_in_a_row_needed_to_win");
        return true;
    }
    if (passArgs > 4) {
        printf("Too many arguments entered\n");
        printf("Usage connectn.out num_rows num_columns");
        printf(" number_of_pieces_in_a_row_needed_to_win");
        return true;
    }
    return false;
}