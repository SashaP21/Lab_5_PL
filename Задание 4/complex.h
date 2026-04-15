#ifndef _4_COMPLEX_H
#define _4_COMPLEX_H

#include <string>

class Complex {
    double re;
    double im;
public:
    Complex();
    Complex(double x, double y);
    Complex(const Complex& c);
    void set_re(double re);
    void set_im(double im);
    double get_re() const;
    double get_im() const;
    double abs() const;
    double arg() const;
    std::string to_string() const;
    std::string to_string_trig() const;
    std::string to_string_exp() const;
    Complex& operator=(const Complex& c);
    Complex& operator++();
    Complex operator++(int);
    Complex& operator--();
    Complex operator--(int);
};

Complex operator+(const Complex& c1, const Complex& c2);
Complex operator-(const Complex& c);
Complex operator-(const Complex& c1, const Complex& c2);
Complex operator*(const Complex& c1, const Complex& c2);
Complex operator/(const Complex& c1, const Complex& c2);
bool operator>(const Complex& c1, const Complex& c2);
bool operator<(const Complex& c1, const Complex& c2);
bool operator>=(const Complex& c1, const Complex& c2);
bool operator<=(const Complex& c1, const Complex& c2);
bool operator==(const Complex& c1, const Complex& c2);
bool operator!=(const Complex& c1, const Complex& c2);
std::istream& operator>>(std::istream& in, Complex& c);
std::ostream& operator<<(std::ostream& out, const Complex& c);

#endif //_4_COMPLEX_H