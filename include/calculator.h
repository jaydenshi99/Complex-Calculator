#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <vector>
#include <unordered_map>
#include <string>

#include "complex.h"

class Calculator {
    private:
        // Data
        std::vector<std::string> expressions;
        std::unordered_map<std::string, std::string> variables;

        // Settings
        bool debugMode;

        void toggleDebug();

        // User Input
        bool readLine();

        // Settings
        bool debugMode;

        void toggleDebug();

        // Evaluation
        Complex evaluateExpression(std::string expression);

    public:
        // Constructor
        Calculator();

        // System Control
        void initialise();
};

#endif