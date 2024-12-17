#include <cmath>

#include "../include/functions.h"
#include "../include/constants.h"

using namespace std;

Complex cexp(Complex z) {
    double magn = pow(Constants::E, z.getReal());
    return Complex(magn * cos(z.getImag()), magn * sin(z.getImag()));
}

Complex clogp(Complex z) {
    return Complex(log(z.magnitude()), z.pArg());
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

Complex csinh(Complex z) {
    Complex w = cexp(z) - cexp(Complex(-1, 0) * z);
    return w / Complex(2, 0);
}

Complex ccosh(Complex z) {
    Complex w = cexp(z) + cexp(Complex(-1, 0) * z);
    return w / Complex(2, 0);
}

Complex ctanh(Complex z) {
    return (cexp(z) - cexp(Complex(-1, 0) * z)) / (cexp(z) + cexp(Complex(-1, 0) * z));
}

Complex cpowp(Complex b, Complex p) {
    return cexp(p * clogp(b));
}