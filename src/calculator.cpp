#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <cctype>
#include <stdexcept>

#include <../include/calculator.h>
#include <../include/helper.h>

#define NEXT true
#define EXIT false

using namespace std;

// Constructor
Calculator::Calculator() : expressions(), variables(), debugMode(false) {}

// User Input
bool Calculator::readLine() {
    string line;

    std::getline(cin, line);

    // Check if calculator is terminating
    if (line == "exit" || line == "EXIT") {
        return EXIT;
    }

    // Settings
    if (line == "debug") {
        toggleDebug();
        return NEXT;
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
        expressions.push_back(line);
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
    if (expression == "" || expression == "()") {
        if (debugMode) cout << "empty: " << expression << endl;
        return Complex(0, 0);
    }

    // Expression is a constant
    if (expression == "e") {
        if (debugMode) cout << "exponential constant: " << expression << endl;
        return Complex(2.718281828459045, 0);
    } else if (expression == "pi") {
        if (debugMode) cout << "pi constant: " << expression << endl;
        return Complex(3.141592653589793, 0);
    }

    // Expression is a real number
    if (isNumber(expression)) {
        if (debugMode) cout << "real number: " << expression << endl;
        return Complex(stod(expression), 0);
    }

    // Expression is complex number
    if (expression.back() == 'i') {
        expression.pop_back();
        if (expression == "") {
            if (debugMode) cout << "imaginary number: " << expression << 'i' << endl;
            return Complex(0, 1);
        }

        if (isNumber(expression)) {
            if (debugMode) cout << "imaginary number: " << expression << 'i' << endl;
            return Complex(0, stod(expression));
        }
        expression.push_back('i');
    }

    // Expression is a variable
    if (variables.find(expression) != variables.end()) {
        if (debugMode) cout << "variable: " << expression << endl;
        return evaluateExpression(variables[expression]);
    }

    // Expression is enclosed by parentheses
    if (isEnclosedByParentheses(expression)) {
        if (debugMode) cout << "in parentheses: " << expression << endl;
        return evaluateExpression(expression.substr(1, expression.length() - 2));
    }

    vector<string> splitXpn;
    
    // Addition
    splitXpn = splitExpression(expression, '+');
    if (!splitXpn.empty()) {
        if (debugMode) cout << "addition: " << splitXpn[0] << "+" << splitXpn[1] << endl;
        Complex lhs = evaluateExpression(splitXpn[0]);
        Complex rhs = evaluateExpression(splitXpn[1]);
        return lhs + rhs;
    }

    // Subtraction
    splitXpn = splitExpression(expression, '-');
    if (!splitXpn.empty()) {
        if (debugMode) cout << "subtraction: " << splitXpn[0] << "-" << splitXpn[1] << endl;
        Complex lhs = evaluateExpression(splitXpn[0]);
        Complex rhs = evaluateExpression(splitXpn[1]);
        return lhs - rhs;
    }

    // Multiplication
    splitXpn = splitExpression(expression, '*');
    if (!splitXpn.empty()) {
        if (debugMode) cout << "multiplication: " << splitXpn[0] << "*" << '(' << splitXpn[1] << ')' << endl;
        Complex lhs = evaluateExpression(splitXpn[0]);
        Complex rhs = evaluateExpression(splitXpn[1]);
        return lhs * rhs;
    }

    // Division 
    splitXpn = splitExpression(expression, '/');
    if (!splitXpn.empty()) {
        if (debugMode) cout << "division: " << splitXpn[0] << "/" << splitXpn[1] << endl;
        Complex lhs = evaluateExpression(splitXpn[0]);
        Complex rhs = evaluateExpression(splitXpn[1]);
        return lhs / rhs;
    }

    // Should never reach this point
    cout << "bug in evaluate expression" << endl;
    return Complex(); 
}

// Settings
void Calculator::toggleDebug() {
    debugMode = !debugMode;
    if (debugMode) {
        cout << "Debug mode on" << endl;
    } else {
        cout << "Debug mode off" << endl;
    }
}

// System Control
void Calculator::initialise() {
    cout << "Calculator ready" << endl;

    while (readLine()) {

    }
}