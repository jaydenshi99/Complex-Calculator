#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <cctype>
#include <stdexcept>

#include <../include/calculator.h>
#include <../include/helper.h>
#include <../include/constants.h>
#include <../include/functions.h>

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
        Complex res = evaluateExpression(line);
        cout << "Result: ";
        res.display_cartesian_no_space();
        cout << endl;
        expressions.push_back(line);
    } else {
        cout << "ERROR: multiple equal signs" << endl;
        return NEXT;
    }

    return NEXT;
}

// Evaluation
Complex Calculator::evaluateExpression(string expression) {

    // Expression is enclosed by parentheses
    if (isEnclosedByParentheses(expression)) {
        if (debugMode) cout << "in parentheses: " << expression << endl;
        return evaluateExpression(expression.substr(1, expression.length() - 2));
    }

    // Empty expression is 0
    if (expression == "") {
        if (debugMode) cout << "empty: " << expression << endl;
        return Complex(0, 0);
    }

    // Expression is a constant
    if (expression == "e") {
        if (debugMode) cout << "exponential constant: " << expression << endl;
        return Complex(Constants::E, 0);
    } else if (expression == "pi") {
        if (debugMode) cout << "pi constant: " << expression << endl;
        return Complex(Constants::PI, 0);
    }

    // Expression is a real number
    if (isNumber(expression)) {
        if (debugMode) cout << "real number: " << expression << endl;
        return Complex(stod(expression), 0);
    }

    // Expression is imaginary number
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

    // Powers and Roots 
    splitXpn = splitExpression(expression, '^');
    if (!splitXpn.empty()) {
        if (debugMode) cout << "power: " << splitXpn[0] << "^" << splitXpn[1] << endl;
        Complex lhs = evaluateExpression(splitXpn[0]);
        Complex rhs = evaluateExpression(splitXpn[1]);
        return cpowp(lhs, rhs);
    }

    // Functions
    vector<string> fn = parseFunction(expression);
    if (fn.size() == 2) {
        if (debugMode) cout << "complex function: " << fn[0] << "| input: " << fn[1] << endl;

        string fName = fn[0];
        Complex z = evaluateExpression(fn[1]);

        if (fName == "exp") return cexp(z);
        if (fName == "log") return clogp(z);
        if (fName == "sin") return csin(z);
        if (fName == "cos") return ccos(z);
        if (fName == "tan") return ctan(z);
        if (fName == "sinh") return csinh(z);
        if (fName == "cosh") return ccosh(z);
        if (fName == "tanh") return ctanh(z);
    }

    // Should never reach this point
    cout << "invalid input or my code has a bug!" << endl;
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