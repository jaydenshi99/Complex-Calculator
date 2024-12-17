#include <cmath>

#include "../include/functions.h"
#include "../include/constants.h"

using namespace std;

Complex cExp(Complex z) {
    double magn = pow(Constants::E, z.getReal());
    return Complex(magn * cos(z.getImag()), magn * sin(z.getImag()));
}

Complex cSin(Complex z) {
    Complex w = cExp(Complex(0, 1) * z) - cExp(Complex(0, -1) * z);
    return w / Complex(0, 2);
}

Complex cCos(Complex z) {
    Complex w = cExp(Complex(0, 1) * z) + cExp(Complex(0, -1) * z);
    return w / Complex(2, 0);
}

Complex cTan(Complex z) {
    return cSin(z) / cCos(z);
}