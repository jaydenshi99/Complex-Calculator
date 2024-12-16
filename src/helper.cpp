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

// Splits an expression by the first instance of the given operator
vector<string> splitExpression (string expression, char opt) {
    string lhs = "";
    string rhs = "";
    int lbCount = 0;
    int rbCount = 0;

    bool operatorFound = false;
    for (char c : expression) {
        if (c == opt && lbCount == rbCount && !operatorFound) {
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

    // Return empty vector to indicate no operator was found
    if (!operatorFound) {
        return vector<string>();
    }

    // Remove parentheses
    if (lhs.front() == '(' && lhs.back() == ')') {
        lhs = lhs.substr(1, lhs.length() - 2);
    }

    if (rhs.front() == '(' && rhs.back() == ')') {
        rhs = rhs.substr(1, rhs.length() - 2);
    }

    return vector<string>{lhs, rhs};
}

bool isNumber(const std::string& str) {
    // Check if the string is a valid number
    try {
        size_t idx;
        std::stod(str, &idx); // Convert to double and get the position of the last parsed character
        return idx == str.size(); // Ensure the entire string was parsed
    } catch (const std::invalid_argument&) {
        return false; // Not a valid number
    } catch (const std::out_of_range&) {
        return false; // Number is too large or small
    }
}