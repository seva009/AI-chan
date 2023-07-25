#include <cmath>
#include <iostream>
#ifndef CALCFUNC_H
#define CALCFUNC_H

using namespace std;

// This function multiplies the weight by a certain multiplier (Mtpl)
// and rounds the result to 2 decimal places using round() function
double calculateWeight(double weight, double multiplier, bool UseUnitTest)
{
    if (UseUnitTest) {
        if (calculateWeight(1, 2, false) == 2) {
            return 0;
        } else {
            return 1;
        }
    }
    return round(weight * 100) / 100 * round(multiplier * 100) / 100;
}

// This function adds a certain value (Pstwt) to the weight
// and rounds the result to 2 decimal places using round() function
double addWeight(double weight, double valueToAdd, bool UseUnitTest)
{
    if (UseUnitTest) {
        if (addWeight(1, 2, false) == 3) {
            return 0;
        } else {
            return 1;
        }
    } else {
        return round(weight * 100) / 100 + round(valueToAdd * 100) / 100;
    }
}

#endif // CALCFUNC_H
