#include <iostream>

#include "../include/complex.h"

using namespace std;

int main (void) {
    const double inc = 0.04;
    for (double y = 1; y >= -1; y -= inc) {
        for (double x = -2; x <= 1; x += inc/2) {
            Complex c = Complex(x, y);
            Complex z = Complex(x, y);

            bool diverges = false;
            for (int i = 0; i < 10000; i++) {
                z = z * z + c;
                if (
                fabs(z.getReal()) == INFINITY || z.getImag() == INFINITY ||
                isnan(z.getReal()) || isnan(z.getImag())
                ) {
                    cout << " ";
                    diverges = true;
                    break;
                }
            }

            if (!diverges) {
                cout << "#";
            }
        }

        cout << endl;
    }
}