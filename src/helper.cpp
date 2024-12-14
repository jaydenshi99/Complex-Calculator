#include <cmath>

#include "../include/helper.h"

using namespace std;

// Returns: 1 if greater, 0 if equal, -1 if lesser.
// Comparison of double variables with a small epsilon tolerance
int compareDouble(double a, double b) {
    if (fabs(a - b) < EPSILON) {
        return 0;
    } else if (a > b) {
        return 1;
    }

    return -1;
}

// Check if double is zero with small epsilon tolerance
bool isZero(double a) {
    return fabs(a) < EPSILON;
}

vector<string> splitExpression (string expression, char opt) {
    string lhs = "";
    string rhs = "";
    int lbCount = 0;
    int rbCount = 0;

    bool operatorFound = false;
    for (char c : expression) {
        if (c == opt && lbCount == rbCount) {
            operatorFound = true;
            continue;
        } else if (c == '(') {
            lbCount++;
        } else if (c == ')') {
            rbCount++;
        }

        if (operatorFound) {
            rhs += c;
        } else {
            lhs += c;
        }
    }

    if (!operatorFound) {
        return vector<string>();
    }

    return vector<string>{lhs, rhs};
}