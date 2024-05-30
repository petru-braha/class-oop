#include <stdio.h>
#include "ex 1/H5_number.h"

int H5_number_main()
{
    Number n1("10110010", 2);
    Number n2("734", 8);
    Number n3("FF", 16);

    printf("n1 has %d digits and it is written in base %d\n", n1.GetDigitsCount(), n1.GetBase());
    for (int tr = 0; tr < n1.GetDigitsCount(); tr++)
    {
        printf("n1[%d]=%c\n", tr, n1[tr]);
    }
    n1.Print();
    n2.Print();
    n1 = (n2 + n3 - n1) + n1; // after this n1 will be in base 16
    n1.SwitchBase(2);
    n1.Print();

    if (n1 > n2) printf("n1 is bigger than n2\n"); else printf("n2 is bigger than n1\n");

    Number n4 = 12345; // n4 will be in base 10
    n1 = 255; // n1 will be 11111111 (value 255 from base 10 in base 2)
    n4 = n4 + n1;
    n4.Print();

    n4 = "13579"; // n4 mentains its base (10) and will be 13579
    n4.Print();
    --n4; // the first digit from n4 will be remove ==> n4 becomes 3579
    n4.Print();
    n4--; // the last digit from n4 will be remove ==> n4 becomes 357
    n4.Print();

    return 0;
}

#include <iostream>
#include <cmath>
#include "extra/H5_complex_extra.h" //#include "complex.h"

bool double_equals(double l, double r) {
    return abs(l - r) < 0.001;
}

#define check(x)    \
    if (!(x)) {     \
        printf("at line #%d -> `%s` is not satisfied\n", __LINE__, #x); \
    }

void H5_complex_extra_main() 
{
    Complex a{ 1, 2 };
    check(double_equals(a.real(), 1));
    check(double_equals(a.imag(), 2));
    
    Complex b{ 2, 3 };
    Complex c = a + b;
    check(double_equals(c.real(), 3));
    check(double_equals(c.imag(), 5));
    
    Complex d = c - a;
    check(b == d);
    
    Complex e = (a * d).conjugate();
    check(double_equals(e.imag(), -7));
    
    {
        // increment the real part
        Complex res1 = e++;
        check(res1 == e - 1);
        Complex& res2 = ++e;
        check(res2 == e);
        check(double_equals(e.real(), -2));
    }
    
    {
        // decrement the real part
        Complex res1 = e--;
        check(res1 == e + 1);
        Complex& res2 = --e;
        check(res2 == e);
        check(double_equals(e.real(), -4));
    }
    
    Complex f = (a + b - d) * c;
    if (f != Complex{ 1, 2 }) {
        // prints in the format a +/i bi
        // if a or b are not 0, they won't be printed
        // if they're both 0, 0 will be printed
        // examples:                 5 + 4i
        //                          -3 - 2i
        //                          -6
        //                           5i
        std::cout << f << '\n' << a << '\n';
        std::cout << Complex{ 1, 2 } << '\n'
            << Complex{ 1, -2 } << '\n'
            << Complex{ 0, 5 } << '\n'
            << Complex{ 7, 0 } << '\n'
            << Complex{ 0, 0 } << '\n';
    }
    
    // op() will update the real part and the imaginary part
    // it will behave as a setter for both
    Complex g = f(-1, -2)(-2, -3)(-4, -5);
    Complex h = { -4, -5 };
    check(g == h);

    Complex i = h - (h + 5) * 2;
    check(double_equals(i.real(), -6));

    // unary op-
    Complex j = -i + i;
    check(double_equals(j.abs(), 0));
}
