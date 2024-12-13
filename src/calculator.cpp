#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include <../include/calculator.h>

using namespace std;

// Constructor
Calculator::Calculator(vector<Expression> e, unordered_map<string, Complex> v) : expressions(e), variables(v) {}