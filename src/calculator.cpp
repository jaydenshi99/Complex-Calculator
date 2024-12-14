#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include <../include/calculator.h>

using namespace std;

// Constructor
Calculator::Calculator() : expressions(), variables() {}

// User Input
bool Calculator::readLine() {
    string line;

    std::getline(cin, line);

    if (line == "exit") {
        return false;
    }

    cout << line << endl;

    return true;
}

// System Control
void Calculator::initialise() {
    cout << "Calculator Initialised" << endl;

    while (readLine()) {

    }
}