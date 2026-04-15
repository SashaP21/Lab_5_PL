#include <cmath>
#include <string>
#include <sstream>
#include "complex.h"

using std::string;
using std::stringstream;

Complex::Complex() {
    re = 0;
    im = 0;
}

Complex::Complex(double x, double y) {
    this->re = x;
    this->im = y;
}

Complex::Complex(const Complex &c) {
    re = c.re;
    im = c.im;
}

void Complex::set_re(double re) {
    this->re = re;
}

void Complex::set_im(double im) {
    this->im = im;
}

double Complex::get_re() const {
    return re;
}

double Complex::get_im() const {
    return im;
}

double Complex::abs() const {
    return sqrt(re * re + im * im);
}

double Complex::arg() const {
    if (re > 0 && im > 0 || re > 0 && im < 0)
        return atan(im / re);
    else if (re < 0 && im > 0)
        return atan(im / re) + M_PI;
    else if (re < 0 && im < 0)
        return atan(im / re) - M_PI;
    else if (re == 0 && im > 0)
        return M_PI / 2;
    else if (re == 0 && im < 0)
        return M_PI / -2;
    else if (re > 0 && im == 0 || re == 0 && im == 0)
        return 0;
    else
        return M_PI;
}

string Complex::to_string() const {
    stringstream ss;
    ss << re;

    if (im != 0)
        ss << ((im > 0) ? " + " : " - ") << fabs(im) << "*i";

    return ss.str();
}

string Complex::to_string_trig() const {
    stringstream ss;

    double phi = arg();

    ss << "cos(" << phi << ")" << " + i*sin(" << phi << ")";

    return ss.str();
}

string Complex::to_string_exp() const {
    stringstream ss;

    double phi = arg();
    double ro = abs();

    ss << ro << "*e^" << ((phi > 0) ? "i*" : "-i*") << phi;

    return ss.str();
}

Complex& Complex::operator=(const Complex &c) {
    if (this != &c) {
        re = c.re;
        im = c.im;
    }
    return *this;
}

Complex &Complex::operator++() {
    re += 1;
    im += 1;
    return *this;
}

Complex Complex::operator++(int) {
    Complex copy(*this);
    ++(*this);
    return copy;
}

Complex &Complex::operator--() {
    re -= 1;
    im -= 1;
    return *this;
}

Complex Complex::operator--(int) {
    Complex copy(*this);
    --(*this);
    return copy;
}

Complex operator+(const Complex& c1, const Complex& c2) {
    return {c1.get_re() + c2.get_re(), c1.get_im() + c2.get_im()};
}

Complex operator-(const Complex &c) {
    return {-c.get_re(), -c.get_im()};
}


Complex operator-(const Complex &c1, const Complex &c2) {
    return {c1.get_re() - c2.get_re(), c1.get_im() - c2.get_im()};
}

Complex operator*(const Complex &c1, const Complex &c2) {
    return {c1.get_re() * c2.get_re() - c1.get_im() * c2.get_im(),
        c1.get_re() * c2.get_im() + c1.get_im() * c2.get_re()};
}

Complex operator/(const Complex &c1, const Complex &c2) {
    return {(c1.get_re() * c2.get_re() + c1.get_im() * c2.get_im()) /
        (c2.get_re() * c2.get_re() + c2.get_im() * c2.get_im()),

        (-c1.get_re() * c2.get_im() + c1.get_im() * c2.get_re()) /
            (c2.get_re() * c2.get_re() + c2.get_im() * c2.get_im())};
}

bool operator>(const Complex &c1, const Complex &c2) {
    return c1.abs() > c2.abs();
}

bool operator<(const Complex &c1, const Complex &c2) {
    return c1.abs() < c2.abs();
}

bool operator>=(const Complex &c1, const Complex &c2) {
    return c1.abs() >= c2.abs();
}

bool operator<=(const Complex &c1, const Complex &c2) {
    return c1.abs() <= c2.abs();
}

bool operator==(const Complex &c1, const Complex &c2) {
    return c1.get_re() == c2.get_re() && c1.get_im() == c2.get_im();
}

bool operator!=(const Complex &c1, const Complex &c2) {
    return !(c1 == c2);
}

std::istream& operator>>(std::istream& in, Complex &c) {
    double re, im;
    in >> re >> im;
    c.set_re(re);
    c.set_im(im);
    return in;
}

std::ostream &operator<<(std::ostream &out, const Complex &c) {
    out << c.to_string();
    return out;
}
