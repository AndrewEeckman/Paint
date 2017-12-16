//
// Created by Andrew Eeckman on 12/15/17.
//

#include <stdlib.h>
#include <stdio.h>

#include "canvas.h"
#include "fileIO.h"

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
    int i, j;
    int rowsInFile;
    int colsInFile;
    FILE *fp;

    fp = fopen(fileName, "r");

    if(fp == NULL) {
        printf("Failed to open file: %s", fileName);
        return;
    }

    fscanf(fp, "%d", &rowsInFile);
    fscanf(fp, " %d", &colsInFile);

    increaseCanvas(canvas, numRows, numCols, &rowsInFile,  &colsInFile, '*');

    char** tempCanvas = (char**)malloc(rowsInFile * sizeof(char*));
    for(i = 0; i < rowsInFile; i++) {
        tempCanvas[i] = (char*)malloc(colsInFile * sizeof(char));
        for(j = 0; j < colsInFile; j++) {
            fscanf(fp, " %c", &tempCanvas[i][j]);
        }
    }

    for(i = 0; i < rowsInFile; i++) {
        for(j = 0; j < colsInFile; j++) {
            canvas[i][j] = tempCanvas[i][j];
        }
    }

    fclose(fp);
}