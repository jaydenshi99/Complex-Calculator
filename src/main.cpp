#include <iostream>

#include "../include/complex.h"

using namespace std;

int main (void) {
    Complex z = Complex(2, 2);
    Complex w = Complex(1, 1);

    (z + w).print_cartesian();
    (z - w).print_cartesian();
    (z * w).print_cartesian();
    (z / w).print_cartesian();
}