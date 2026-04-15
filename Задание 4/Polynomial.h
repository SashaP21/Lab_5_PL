#ifndef _4_POLYNOMIAL_H
#define _4_POLYNOMIAL_H

#include <vector>
#include <iostream>

using std::vector;

template<typename T>
class Polynomial {
    vector<T> coefficients;
    void trim();
public:
    Polynomial(const vector<T>& coefficients);
    Polynomial(const T& scalar = T());

    int Degree() const;
    T operator[](int degree) const;
    T operator()(const T& x) const;

    Polynomial& operator+=(const Polynomial& other);
    Polynomial& operator-=(const Polynomial& other);
    Polynomial& operator*=(const Polynomial& other);

    Polynomial& operator+=(const T& scalar);
    Polynomial& operator-=(const T& scalar);
    Polynomial& operator*=(const T& scalar);

    template<typename U>
    friend Polynomial<U> operator+(const Polynomial<U>& lhs, const Polynomial<U>& rhs);
    template<typename U>
    friend Polynomial<U> operator-(const Polynomial<U>& lhs, const Polynomial<U>& rhs);
    template<typename U>
    friend Polynomial<U> operator*(const Polynomial<U>& lhs, const Polynomial<U>& rhs);
    template<typename U>
    friend bool operator==(const Polynomial<U>& lhs, const Polynomial<U>& rhs);
    template<typename U>
    friend bool operator!=(const Polynomial<U>& lhs, const Polynomial<U>& rhs);
    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const Polynomial<U>& p);
};

template<typename T>
Polynomial<T>::Polynomial(const vector<T> &coefficients) {
    this->coefficients = coefficients;
    trim();
}

template<typename T>
Polynomial<T>::Polynomial(const T &scalar) {
    if (scalar != T())
        coefficients.push_back(scalar);
}

template<typename T>
void Polynomial<T>::trim() {
    while (!coefficients.empty() && coefficients.back() == T())
        coefficients.pop_back();
}

template<typename T>
int Polynomial<T>::Degree() const {
    if (coefficients.empty()) return 0;
    return static_cast<int>(coefficients.size()) - 1;
}

template<typename T>
Polynomial<T>& Polynomial<T>::operator+=(const Polynomial<T>& other) {
    *this = *this + other;
    return *this;
}

template<typename T>
Polynomial<T>& Polynomial<T>::operator-=(const Polynomial<T>& other) {
    *this = *this - other;
    return *this;
}

template<typename T>
Polynomial<T>& Polynomial<T>::operator*=(const Polynomial<T>& other) {
    *this = *this * other;
    return *this;
}

template<typename T>
Polynomial<T>& Polynomial<T>::operator+=(const T& scalar) {
    if (coefficients.empty())
        coefficients.push_back(scalar);
    else
        coefficients[0] += scalar;
    trim();
    return *this;
}

template<typename T>
Polynomial<T>& Polynomial<T>::operator-=(const T& scalar) {
    return *this += (-scalar);
}

template<typename T>
Polynomial<T>& Polynomial<T>::operator*=(const T& scalar) {
    if (scalar == T()) {
        coefficients.clear();
    } else {
        for (auto& c : coefficients)
            c *= scalar;
    }
    trim();
    return *this;
}

template<typename T>
Polynomial<T> operator+(const Polynomial<T>& lhs, const Polynomial<T>& rhs) {
    vector<T> res(std::max(lhs.coefficients.size(), rhs.coefficients.size()), T());
    for (size_t i = 0; i < res.size(); ++i) {
        T a = (i < lhs.coefficients.size()) ? lhs.coefficients[i] : T();
        T b = (i < rhs.coefficients.size()) ? rhs.coefficients[i] : T();
        res[i] = a + b;
    }
    return Polynomial<T>(res);
}

template<typename T>
Polynomial<T> operator-(const Polynomial<T>& lhs, const Polynomial<T>& rhs) {
    vector<T> res(std::max(lhs.coefficients.size(), rhs.coefficients.size()), T());
    for (size_t i = 0; i < res.size(); ++i) {
        T a = (i < lhs.coefficients.size()) ? lhs.coefficients[i] : T();
        T b = (i < rhs.coefficients.size()) ? rhs.coefficients[i] : T();
        res[i] = a - b;
    }
    return Polynomial<T>(res);
}

template<typename T>
Polynomial<T> operator*(const Polynomial<T>& lhs, const Polynomial<T>& rhs) {
    if (lhs.coefficients.empty() || rhs.coefficients.empty())
        return Polynomial<T>();
    vector<T> res(lhs.coefficients.size() + rhs.coefficients.size() - 1, T());
    for (size_t i = 0; i < lhs.coefficients.size(); ++i)
        for (size_t j = 0; j < rhs.coefficients.size(); ++j)
            res[i + j] = res[i + j] + lhs.coefficients[i] * rhs.coefficients[j];
    return Polynomial<T>(res);
}

template<typename T>
bool operator==(const Polynomial<T>& lhs, const Polynomial<T>& rhs) {
    return lhs.coefficients == rhs.coefficients;
}

template<typename T>
bool operator!=(const Polynomial<T>& lhs, const Polynomial<T>& rhs) {
    return !(lhs == rhs);
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Polynomial<T>& p) {
    if (p.coefficients.empty()) {
        os << "0";
    } else {
        for (int i = static_cast<int>(p.coefficients.size()) - 1; i >= 0; --i) {
            os << p.coefficients[i];
            if (i > 0) os << ' ';
        }
    }
    return os;
}

template<typename T>
T Polynomial<T>::operator()(const T& x) const {
    T result = T();
    for (int i = static_cast<int>(coefficients.size()) - 1; i >= 0; --i)
        result = result * x + coefficients[i];
    return result;
}

template<typename T>
T Polynomial<T>::operator[](int degree) const {
    if (degree >= static_cast<int>(coefficients.size()))
        return T();
    return coefficients[degree];
}

template<typename T>
Polynomial<T> operator+(const Polynomial<T>& p, const T& scalar) {
    Polynomial<T> res(p);
    res += scalar;
    return res;
}

template<typename T>
Polynomial<T> operator+(const T& scalar, const Polynomial<T>& p) {
    return p + scalar;
}

template<typename T>
Polynomial<T> operator-(const Polynomial<T>& p, const T& scalar) {
    Polynomial<T> res(p);
    res -= scalar;
    return res;
}

template<typename T>
Polynomial<T> operator-(const T& scalar, const Polynomial<T>& p) {
    Polynomial<T> res(scalar);
    res -= p;
    return res;
}

template<typename T>
Polynomial<T> operator*(const Polynomial<T>& p, const T& scalar) {
    Polynomial<T> res(p);
    res *= scalar;
    return res;
}

template<typename T>
Polynomial<T> operator*(const T& scalar, const Polynomial<T>& p) {
    return p * scalar;
}

template<typename T>
bool operator==(const Polynomial<T>& p, const T& scalar) {
    return p == Polynomial<T>(scalar);
}

template<typename T>
bool operator==(const T& scalar, const Polynomial<T>& p) {
    return p == scalar;
}

template<typename T>
bool operator!=(const Polynomial<T>& p, const T& scalar) {
    return !(p == scalar);
}

template<typename T>
bool operator!=(const T& scalar, const Polynomial<T>& p) {
    return !(scalar == p);
}

#endif //_4_POLYNOMIAL_H