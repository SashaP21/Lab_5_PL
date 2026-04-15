#include "Matrix.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

int main() {
    try {
        cout << "=== int ===\n";

        Matrix<int> intMat1(2, 2);
        intMat1.Set_element(0, 0, 1);
        intMat1.Set_element(0, 1, 2);
        intMat1.Set_element(1, 0, 3);
        intMat1.Set_element(1, 1, 4);
        
        cout << "Matrix intMat1:\n" << intMat1;

        Matrix<int> intMat2(intMat1);
        cout << "Matrix intMat2 (copy of intMat1):\n" << intMat2;

        cout << "Element at (0,1) in intMat2: " << intMat2.Get_element(0, 1) << "\n\n";

        Matrix<int> intSum = intMat1 + intMat2;
        cout << "intMat1 + intMat2:\n" << intSum;

        Matrix<int> intProd = intMat1 * intMat2;
        cout << "intMat1 * intMat2:\n" << intProd;

        cout << "Enter integer matrix (rows cols then elements):\n";
        Matrix<int> intInput;
        cin >> intInput;
        cout << "You entered:\n" << intInput;

        intInput = intProd;
        cout << "After assignment intInput = intProd:\n" << intInput;

        cout << "\n=== string ===\n";
        
        Matrix<string> strMat1(2, 2);
        strMat1.Set_element(0, 0, "Hello");
        strMat1.Set_element(0, 1, " ");
        strMat1.Set_element(1, 0, "World");
        strMat1.Set_element(1, 1, "!");
        
        cout << "Matrix strMat1:\n" << strMat1;
        
        Matrix<string> strMat2(2, 2);
        strMat2.Set_element(0, 0, "C++");
        strMat2.Set_element(0, 1, " is");
        strMat2.Set_element(1, 0, " great");
        strMat2.Set_element(1, 1, "!");
        
        cout << "Matrix strMat2:\n" << strMat2;

        Matrix<string> strSum = strMat1 + strMat2;
        cout << "strMat1 + strMat2 (concatenation):\n" << strSum;

        cout << "Enter string matrix (rows cols then words):\n";
        Matrix<string> strInput;
        cin >> strInput;
        cout << "You entered:\n" << strInput;

        cout << "Element at (1,0) in strInput: " << strInput.Get_element(1, 0) << "\n";
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
}