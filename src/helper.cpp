#include <string>
#include <vector>
#include <cmath>
#include <stack>

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
    if (isEnclosedByParentheses(rhs)) {
        rhs = rhs.substr(1, rhs.length() - 2);
    }

    if (isEnclosedByParentheses(lhs)) {
        lhs = lhs.substr(1, lhs.length() - 2);
    }

    return vector<string>{lhs, rhs};
}

bool isNumber(const string& str) {
    // Check if the string is a valid number
    try {
        size_t idx;
        stod(str, &idx); // Convert to double and get the position of the last parsed character
        return idx == str.size(); // Ensure the entire string was parsed
    } catch (const invalid_argument&) {
        return false; // Not a valid number
    } catch (const out_of_range&) {
        return false; // Number is too large or small
    }
}

bool isEnclosedByParentheses(string expression) {
    if (expression.length() < 2 || expression.front() != '(' || expression.back() != ')') {
        return false;
    }

    stack<int> parentheses;
    int bracketNum = 0;
    for (int i = 0; i < expression.length() - 1; i++) {
        if (expression[i] == '(') {
            parentheses.push(bracketNum);
            bracketNum++;
        } else if (expression[i] == ')') {
            parentheses.pop();
        }
    }

    return parentheses.size() == 1 && parentheses.top() == 0;
}

vector<string> parseFunction(string expression) {
    if (expression.length() < 2) {
        return vector<string>();
    }

    int i = 0;
    while (i < expression.length()) {
        if (expression[i] == '(') break;
        i++;
    }

    string fName = expression.substr(0, i);
    string z = expression.substr(i, expression.length() - 1);

    vector<string> ret;
    if (isEnclosedByParentheses(z)) {
        ret.push_back(fName);
        ret.push_back(z.substr(1, z.length() - 2));
    }

    return ret;
}