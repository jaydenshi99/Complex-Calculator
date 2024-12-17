#include <iostream>
#include <cmath>

#include "../include/complex.h"
#include "../include/helper.h"
#include "../include/constants.h"

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

// Arithmetic Operations
Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, imag - other.imag);
}

Complex Complex::operator*(const Complex& other) const {
    return Complex(
        real * other.real - imag * other.imag, 
        real * other.imag + imag * other.real
    );
}

Complex Complex::operator/(const Complex& other) const {
    double m_squared = other.magnitude() * other.magnitude();

    return Complex(real / m_squared, imag / m_squared) * other.conjugate();
}

// Equality
bool Complex::operator==(const Complex& other) const {
    return compareDouble(real, other.real) == 0 && compareDouble(imag, other.imag) == 0;
}

// Other Operations
double Complex::magnitude() const {
    return sqrt(real * real + imag * imag);
}

double Complex::pArg() const {
    // Handle error case
    return atan2(imag, real);
}

Complex Complex::conjugate() const {
    return Complex(real, -imag);
}

// Display
void Complex::display_cartesian_no_space() const {
    if (isZero(real) && isZero(imag)) {
        cout << 0;
    }

    if (!isZero(real)) {
        cout << real;
    }

    if (compareDouble(imag, 1) == 0) {
        if (isZero(real)) {
            cout << "i";
        } else {
            cout << "+i";
        }

    } else if (!isZero(imag)) {
        if (isZero(real)) {
            cout << imag << "i";
        } else {
            if (compareDouble(imag, 0) == 1) {
                cout << "+" << fabs(imag) << "i";
            } else {
                cout << "-" << fabs(imag) << "i";
            }
        }
    }
}

void Complex::display_cartesian() const {
    if (isZero(real) && isZero(imag)) {
        cout << 0;
    }
    
    if (!isZero(real)) {
        cout << real;
    }

    if (compareDouble(imag, 1) == 0) {
        if (isZero(real)) {
            cout << "i";
        } else {
            cout << " + i";
        }

    } else if (!isZero(imag)) {
        if (isZero(real)) {
            cout << imag << "i";
        } else {
            if (compareDouble(imag, 0) == 1) {
                cout << " + " << fabs(imag) << "i";
            } else {
                cout << " - " << fabs(imag) << "i";
            }
        }
    }

    cout << endl;
}