#include <iostream>

#include "../include/complex.h"
#include "../include/other.h"

// Displays Mandlebrot Set
void display_mandlebrot() {
    const double inc = 0.04;
    for (double y = 1; y >= -1; y -= inc) {
        for (double x = -2; x <= 1; x += inc/2) {
            Complex c = Complex(x, y);
            Complex z = Complex(x, y);

            bool diverges = false;
            for (int i = 0; i < 1000; i++) {
                z = z * z + c;
                if (z.getReal() * z.getReal() + z.getImag() * z.getImag() > 4) {
                    std::cout << ".";
                    diverges = true;
                    break;
                }
            }

            if (!diverges) {
                std::cout << "#";
            }
        }

        std::cout << std::endl;
    }
}