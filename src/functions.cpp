#include <cmath>

#include "../include/functions.h"
#include "../include/constants.h"

using namespace std;

Complex cexp(Complex z) {
    double magn = pow(Constants::E, z.getReal());
    return Complex(magn * cos(z.getImag()), magn * sin(z.getImag()));
}

Complex csin(Complex z) {
    Complex w = cexp(Complex(0, 1) * z) - cexp(Complex(0, -1) * z);
    return w / Complex(0, 2);
}

Complex ccos(Complex z) {
    Complex w = cexp(Complex(0, 1) * z) + cexp(Complex(0, -1) * z);
    return w / Complex(2, 0);
}

Complex ctan(Complex z) {
    return csin(z) / ccos(z);
}