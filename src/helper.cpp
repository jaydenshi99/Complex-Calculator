#include <cmath>

#include "../include/helper.h"

using namespace std;

// Returns: 1 if greater, 0 if equal, -1 if lesser.
// Comparison of double variables with a small epsilon tolerance
int compareDouble(double a, double b) {
    if (abs(a - b) < EPSILON) {
        return 0;
    } else if (a > b) {
        return 1;
    }

    return -1;
}

// Check if double is zero with small epsilon tolerance
bool isZero(double a) {
    return abs(a) < EPSILON;
}