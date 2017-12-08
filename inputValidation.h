//
// Created by Andrew Eeckman on 12/6/17.
//

#ifndef PAINT_INPUTVALIDATION_H
#define PAINT_INPUTVALIDATION_H

#include <stdbool.h>

bool isValidFormat(const int numArgsRead, const int numArgsNeeded);
bool valueInBound(const int val, const int upperBound, const int lowerBound);

#endif //PAINT_INPUTVALIDATION_H
