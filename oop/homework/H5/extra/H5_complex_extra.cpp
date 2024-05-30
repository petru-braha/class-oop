#include "H5_complex_extra.h"

Complex::Complex() : Complex(0, 0) {}

Complex::Complex(double real, double imag) {
    real_data = real;
    imag_data = imag;
}

Complex::Complex(const Complex& temp)
{
    this->real_data = temp.real();
    this->imag_data = temp.imag();
}

bool Complex::is_real() const {
    return imag() == 0;
}

double Complex::real() const {
    return real_data;
}

double Complex::imag() const {
    return imag_data;
}

double Complex::abs() const {
    return sqrt(real() * real() + imag() * imag());
}

Complex Complex::conjugate() const {
    return { real(), -imag() };
}

Complex& Complex::operator =(const Complex& temp)
{
    this->real_data = temp.real();
    this->imag_data = temp.imag();
    return *this;
}

//---------------------------------------------------------------------------------------

Complex& Complex::operator++()
{
    ++this->real_data;
    return *this;
}
Complex Complex::operator++(int)
{
    ++(*this);
    return Complex(this->real_data - 1, this->imag_data);
}
Complex& Complex::operator--()
{
    --this->real_data;
    return *this;
}
Complex Complex::operator--(int)
{
    --(*this);
    return Complex(this->real_data + 1, this->imag_data);
}
Complex& Complex::operator()(double real, double imag)
{
    this->real_data = real;
    this->imag_data = imag;
    return *this;
}

Complex operator+(const Complex& l, const Complex& r)
{
    return Complex(l.real() + r.real(), l.imag() + r.imag());
}
Complex operator+(const Complex& l, double r)
{
    return Complex(l.real() + r, l.imag());
}
Complex operator+(double l, const Complex& r)
{
    return Complex(r.real() + l, r.imag());
}

Complex operator-(const Complex& obj, const Complex& obj2)
{
    return Complex(obj.real() - obj2.real(), obj.imag() - obj2.imag());
}
Complex operator-(const Complex& obj, double r)
{
    return Complex(obj.real() - r, obj.imag());
}
Complex operator-(double r, const Complex& obj2)
{
    return Complex(obj2.real() - r, obj2.imag());
}

// (a+ib) * (m+in) == am - bn + i(an + bm)
Complex operator*(const Complex& obj, const Complex& obj2)
{
    return Complex(obj.real() * obj2.real() - obj.imag() * obj2.imag(), obj.real() * obj2.imag() + obj.imag() * obj2.real());
}
Complex operator*(const Complex& obj2, double r)
{
    return Complex(obj2.real() * r, obj2.imag() * r);
}
Complex operator*(double r, const Complex& obj2)
{
    return Complex(obj2.real() * r, obj2.imag() * r);
}

Complex operator-(const Complex& obj2)
{
    return Complex(obj2.real() * -1, obj2.imag() * -1);
}

bool operator==(const Complex& l, const Complex& r)
{
    if (l.imag() != r.imag())
        return false;
    if (l.real() != r.real())
        return false;
    return true;
}
bool operator!=(const Complex& l, const Complex& r)
{
    return !(l == r);
}

#include <stdio.h>
std::ostream& operator<<(std::ostream& out, const Complex& complex)
{
    double r = complex.real();
    double i = complex.imag();

    if (r == 0 && i == 0)
    {
        printf("0");
        return out;
    }
  
    if (r == 0)
    {
        printf("%fi", i);
        return out;
    }
    if (i == 0)
    {
        printf("%f", r);
        return out;
    }
    
    printf("%f + %fi", complex.real(), complex.imag());
    return out;
}
