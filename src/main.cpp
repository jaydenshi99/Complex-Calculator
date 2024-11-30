#include <iostream>

#include "../include/complex.h"

using namespace std;

int main (void) {
    const double inc = 0.05;
    for (double y = 1; y >= -1; y -= inc) {
        for (double x = -2; x <= -1; x += inc) {
            Complex c = Complex(x, y);
            Complex z = Complex(x, y);

            for (int i = 0; i < 20; i++) {
                z = z * z + c;
            }

            if (fabs(z.getImag()) == INFINITY || z.getReal() == INFINITY) {
                cout << " ";
            } else {
                cout << "#";
            }
        }

        cout << endl;
    }
}