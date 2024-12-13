#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>

using namespace std;


class Expression{
    private:
        string expression;
    
    public:
        // Constructor
        Expression(string e = "");
};

#endif