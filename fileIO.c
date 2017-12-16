//
// Created by Andrew Eeckman on 12/15/17.
//

#include "fileIO.h"
#include <stdlib.h>
#include <stdio.h>

void saveToFile(char** canvas, int *numRows, int *numCols, char* fileName) {

    FILE *fp;
    fp = fopen(fileName, "w");

    fprintf(fp, "%d ", *numRows);
    fprintf(fp, "%d\n", *numCols);

    if(fp == NULL) {
        printf("Improper save command or file could not be created.\n");
        return;
    }

    for(int i = 0; i < *numRows; i++) {
        for(int j = 0; j < *numCols; j++) {
            fprintf(fp, "%c", canvas[i][j]);
        }
    }

    fclose(fp);
}
void loadSelectFile(char** canvas, int *numRows, int *numCols, char* fileName) {

}