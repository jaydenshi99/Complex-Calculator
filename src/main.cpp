#include <iostream>

#include "../include/complex.h"
#include "../include/other.h"
#include "../include/calculator.h"
#include "../include/functions.h"

int main (void) {
    Complex z = Complex(1, 2);
    cexp(z).display_cartesian();
    csin(z).display_cartesian();
    ccos(z).display_cartesian();
    ctan(z).display_cartesian();
    clogp(z).display_cartesian();
    csinh(z).display_cartesian();
    ccosh(z).display_cartesian();
    ctanh(z).display_cartesian();
    // Calculator calc;
    // calc.initialise();
}