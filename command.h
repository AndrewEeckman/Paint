//
// Created by Andrew Eeckman on 12/5/17.
//

#ifndef PAINT_COMMAND_H
#define PAINT_COMMAND_H

//void commandChecker(char * commandArgs[], int argsNeeded );
void quitProg();
void printHelp();
void getCommand(char** canvas, const int num_rows, const int num_columns, const char blank_space, char *command,
                int* row, int* col);

#endif //PAINT_COMMAND_H
