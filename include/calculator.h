#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <vector>
#include <unordered_map>
#include <string>

#include "expression.h"
#include "complex.h"

class Calculator {
    private:
        std::vector<Expression> expressions;
        std::unordered_map<std::string, Complex> variables;

        // User input
        void readLine();
    
    public:
        // Constructor
        Calculator();

        // System Control
        void initialise();
        void shutdown();
};

#endif