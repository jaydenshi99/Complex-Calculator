#include <iostream>

#include "../include/complex.h"
#include "../include/other.h"
#include "../include/calculator.h"
#include "../include/functions.h"

int main (void) {
    Complex z = Complex(1, 2);
    cExp(z).display_cartesian();
    cSin(z).display_cartesian();
    cCos(z).display_cartesian();
    cTan(z).display_cartesian();
    // Calculator calc;
    // calc.initialise();
}