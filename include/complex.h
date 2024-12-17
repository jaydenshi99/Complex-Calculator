#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
    private:
        double real;
        double imag;

    public:
        // Constructor
        Complex(double r = 0, double i = 0);

        // Getter and Setter methods
        double getReal() const;
        double getImag() const;
        void setReal(double r);
        void setImag(double i);

        // Arithmetic Operators
        Complex operator+(const Complex& other) const;
        Complex operator-(const Complex& other) const;
        Complex operator*(const Complex& other) const;
        Complex operator/(const Complex& other) const;

        // Equality
        bool operator==(const Complex& other) const;

        // Other Operations
        double magnitude() const;
        double pArg() const;
        Complex conjugate() const;

        // Display
        void display_cartesian() const;
        void display_cartesian_no_space() const;
};

#endif