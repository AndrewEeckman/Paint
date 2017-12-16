//
// Created by Andrew Eeckman on 12/15/17.
//

#ifndef PAINT_FILEIO_H
#define PAINT_FILEIO_H

void saveToFile(char** canvas, int *numRows, int *numCols, char* fileName);
void loadSelectFile(char** canvas, int *numRows, int *numCols, char* fileName);

#endif //PAINT_FILEIO_H
