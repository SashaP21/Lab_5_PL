#ifndef _3_MATRIX_H
#define _3_MATRIX_H

#include <iostream>

template <typename T>
class Matrix {
    T** matrix;
    int rows;
    int columns;
    void allocate();
public:
    Matrix();
    Matrix(int rows, int columns);
    Matrix(const Matrix& other);
    ~Matrix();
    T Get_element(int i, int j) const;
    void Set_element(int i, int j, const T& el);
    Matrix operator+(const Matrix& m2) const;
    Matrix operator*(const Matrix& m2) const;
    Matrix& operator=(const Matrix& other);
    template<typename U>
    friend std::istream& operator>>(std::istream& in, Matrix<U>& m);
    template<typename U>
    friend std::ostream& operator<<(std::ostream& out, const Matrix<U>& m);
};

template<typename T>
Matrix<T>::Matrix() {
    rows = 0;
    columns = 0;
    matrix = nullptr;
}

template<typename T>
void Matrix<T>::allocate() {
    matrix = new T*[rows];
    for (int i = 0; i < rows; i++)
        matrix[i] = new T[columns];
}


template<typename T>
Matrix<T>::Matrix(int rows, int columns) {
    this->rows = rows;
    this->columns = columns;
    allocate();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)
            matrix[i][j] = T();
    }
}

template<typename T>
Matrix<T>::Matrix(const Matrix &other) {
    rows = other.rows;
    columns = other.columns;
    allocate();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)
            matrix[i][j] = other.matrix[i][j];
    }
}


template<typename T>
Matrix<T>::~Matrix() {
    for (int i = 0; i < rows; i++)
        delete[] matrix[i];
    delete[] matrix;
}

template<typename T>
T Matrix<T>::Get_element(int i, int j) const {
    if (i >= rows || j >= columns)
        throw std::out_of_range("Index out of range");
    return matrix[i][j];
}

template<typename T>
void Matrix<T>::Set_element(int i, int j, const T& el) {
    if (i >= rows || j >= columns)
        throw std::out_of_range("Index out of range");
    matrix[i][j] = el;
}

template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix& other) {
    if (this != &other) {
        for (int i = 0; i < rows; i++)
            delete[] matrix[i];
        delete[] matrix;

        rows = other.rows;
        columns = other.columns;
        allocate();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j)
                matrix[i][j] = other.matrix[i][j];
        }
    }
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix &m2) const {
    if (rows != m2.rows || columns != m2.columns)
        throw std::invalid_argument("Matrix dimensions invalid for addition");
    Matrix result(rows, columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)
            result.matrix[i][j] = matrix[i][j] + m2.matrix[i][j];
    }
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix &m2) const {
    if (columns != m2.rows) {
        throw std::invalid_argument("Matrix dimensions invalid for multiplication");
    }
    Matrix result(rows, m2.columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < m2.columns; j++) {
            T sum = T();
            for (int k = 0; k < columns; k++)
                sum += matrix[i][k] * m2.matrix[k][j];
            result.matrix[i][j] = sum;
        }
    }
    return result;
}

template<typename U>
std::istream& operator>>(std::istream& in, Matrix<U> & m) {
    int rows, columns;
    in >> rows >> columns;
    m = Matrix<U>(rows, columns);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            in >> m.matrix[i][j];
        }
    }
    return in;
}

template<typename U>
std::ostream& operator<<(std::ostream& out, const Matrix<U> & m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.columns; j++)
            out << m.matrix[i][j] << " ";
        out << "\n";
    }
    return out;
}

#endif //_3_MATRIX_H