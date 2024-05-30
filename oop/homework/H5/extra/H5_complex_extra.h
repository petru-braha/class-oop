#pragma once
#include <ostream>

class Complex 
{
    double real_data;
    double imag_data;
public:
    Complex();
    Complex(double real, double imag);
    Complex(const Complex& temp);

    bool is_real() const;

    double real() const;
    double imag() const;
    double abs() const;
    Complex conjugate() const;

    Complex& operator =(const Complex& temp);
    
    // op++ postfixed MUST use op++ prefixed
    // op-- postfixed MUST use op-- prefixed
    Complex& operator++();
    Complex  operator++(int);
    Complex& operator--();
    Complex  operator--(int);
    Complex& operator()(double real, double imag);
};

Complex operator+(const Complex& l, const Complex& r);
Complex operator+(const Complex& l, double r);
Complex operator+(double l, const Complex& r);

Complex operator-(const Complex& obj, const Complex& obj2);
Complex operator-(const Complex& obj, double r);
Complex operator-(double r, const Complex& obj2);

Complex operator*(const Complex& obj, const Complex& obj2);
Complex operator*(const Complex& obj2, double r);
Complex operator*(double r, const Complex& obj2);

Complex operator-(const Complex& obj2);

bool operator==(const Complex& l, const Complex& r);
bool operator!=(const Complex& l, const Complex& r);

std::ostream& operator<<(std::ostream& out, const Complex& complex);