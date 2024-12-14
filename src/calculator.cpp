#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <cctype>

#include <../include/calculator.h>
#include <../include/helper.h>

#define NEXT true
#define EXIT false

using namespace std;

// Constructor
Calculator::Calculator() : expressions(), variables() {}

// User Input
bool Calculator::readLine() {
    string line;

    std::getline(cin, line);

    // Check if calculator is terminating
    if (line == "exit" || line == "EXIT") {
        return EXIT;
    }

    // Remove spaces in expression
    line.erase(remove(line.begin(), line.end(), ' '), line.end());

    // Expression or Variable
    int equalCharCount = 0;
    for (char c : line) {
        if (c == '=') {
            equalCharCount++;
        }
    }

    if (equalCharCount == 1) {
        size_t pos = line.find('=');
        string variableName = line.substr(0, pos);
        string expression = line.substr(pos + 1);

        for (char c : variableName) {
            if (!isalpha(c)) {
                cout << "ERROR: variable name may only contain letters (a~z, A~Z)" << endl;
                return NEXT;
            }
        }

        variables[variableName] = expression;
        Complex res = evaluateExpression(expression);

        cout << variableName << "=";
        res.display_cartesian_no_space();
        cout << endl;
    } else if (equalCharCount == 0) {
        Complex res = evaluateExpression(line);
        res.display_cartesian_no_space();
        cout << endl;
    } else {
        cout << "ERROR: multiple equal signs" << endl;
        return NEXT;
    }

    return NEXT;
}

// Evaluation
Complex Calculator::evaluateExpression(string expression) {
    // Empty expression is 0
    if (expression == "") {
        return Complex(0, 0);
    }

    vector<string> splitXpn = splitExpression(expression, '+');
}

// System Control
void Calculator::initialise() {
    cout << "Calculator ready" << endl;

    while (readLine()) {

    }
}