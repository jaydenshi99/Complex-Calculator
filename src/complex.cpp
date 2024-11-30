#include <iostream>
#include <cmath>

#include "../include/complex.h"

using namespace std;

// Constructor
Complex::Complex(double r, double i) : real(r), imag(i) {}

// Getter and Setter functions
double Complex::getReal() const {
    return real;
}

double Complex::getImag() const {
    return imag;
}

void Complex::setReal(double r) {
    real = r;
}

void Complex::setImag(double i) {
    imag = i;
}

// Other Operations
double Complex::magnitude() const {
    return sqrt(real * real + imag * imag);
}

Complex Complex::conjugate() const {
    return Complex(real, -imag);
}

// Display
void Complex::print_cartesian() const {
    cout << "complex number in cartesian form\n";
}