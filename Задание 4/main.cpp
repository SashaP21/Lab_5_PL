#include <iostream>
#include "Polynomial.h"
#include "complex.h"


using std::cout;
using std::endl;

int main() {
    cout << "=== Polynomial<int> ===" << endl;
    vector<int> coeffs1 = {1, 2, 3};
    vector<int> coeffs2 = {0, -1, 1};
    Polynomial<int> p1(coeffs1);
    Polynomial<int> p2(coeffs2);
    Polynomial<int> p3(5);

    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;
    cout << "p3 = " << p3 << endl;
    cout << "Degree of p1: " << p1.Degree() << endl;
    cout << "p1[2] = " << p1[2] << ", p1[5] = " << p1[5] << endl;
    cout << "p1(2) = " << p1(2) << endl;

    cout << "p1 + p2 = " << p1 + p2 << endl;
    cout << "p1 - p2 = " << p1 - p2 << endl;
    cout << "p1 * p2 = " << p1 * p2 << endl;
    cout << "p1 * 2 = " << p1 * 2 << endl;
    cout << "3 + p2 = " << 3 + p2 << endl;
    cout << "p2 - 1 = " << p2 - 1 << endl;

    cout << "p1 == p1? " << (p1 == p1) << endl;
    cout << "p1 != p2? " << (p1 != p2) << endl;
    cout << "p3 == 5? " << (p3 == 5) << endl;
    cout << "5 != p2? " << (5 != p2) << endl;


    cout << "\n=== Polynomial<Complex> ===" << endl;
    Complex c1(1, 0), c2(0, 1), c3(2, -1);
    vector<Complex> ccoeff1 = {c1, c2};
    vector<Complex> ccoeff2 = {Complex(0,0), Complex(0,0), c3};
    Polynomial<Complex> cp1(ccoeff1);
    Polynomial<Complex> cp2(ccoeff2);
    Polynomial<Complex> cp3(Complex(3, 2));

    cout << "cp1 = " << cp1 << endl;
    cout << "cp2 = " << cp2 << endl;
    cout << "cp3 = " << cp3 << endl;
    cout << "Degree of cp2: " << cp2.Degree() << endl;
    cout << "cp1(Complex(2,0)) = " << cp1(Complex(2,0)) << endl;

    cout << "cp1 + cp2 = " << cp1 + cp2 << endl;
}