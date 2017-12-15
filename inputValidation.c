//
// Created by Andrew Eeckman on 12/6/17.
//

#include "inputValidation.h"
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool isValidFormat(const int numArgsRead, const int numArgsNeeded) {
    bool isValid = numArgsRead == numArgsNeeded;

    char c;

    do {
        scanf("%c", &c);
        if(!isspace(c)) {
            return false;
        }
    } while(c != '\n');

    return isValid;
}

bool valueInBound(const int val, const int upperBound, const int lowerBound) {
    return val >= lowerBound && val <= upperBound;
}
