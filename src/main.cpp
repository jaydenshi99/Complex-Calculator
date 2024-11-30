#include <iostream>

#include "../include/complex.h"

using namespace std;

int main (void) {
    Complex c1 = Complex(2, 2);
    c1.print_cartesian();
    cout << c1.magnitude() << '\n';
}