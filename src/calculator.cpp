#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include <../include/calculator.h>

using namespace std;

// Constructor
Calculator::Calculator() : expressions(), variables() {}

// User Input
void Calculator::readLine() {
    string line;

    std::getline(cin, line);

    cout << line << endl;
}