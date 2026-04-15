#include <iostream>
#include <string>
#include "contains.h"

using std::cout;
using std::boolalpha;
using std::string;

int main() {
    int *intArr = new int[5]{10, 20, 30, 40, 50};
    cout << "int: contains 30? " << boolalpha << contains(30, intArr, 5) << "\n";
    cout << "int: contains 99? " << boolalpha << contains(99, intArr, 5) << "\n";
    delete[] intArr;

    double *doubleArr = new double[4]{1.1, 2.2, 3.3, 4.4};
    cout << "double: contains 2.2? " << boolalpha << contains(2.2, doubleArr, 4) << "\n";
    cout << "double: contains 5.5? " << boolalpha << contains(5.5, doubleArr, 4) << "\n";
    delete[] doubleArr;

    string *strArr = new string[3]{"apple", "banana", "cherry"};
    cout << "string: contains \"banana\"? " << boolalpha
            << contains(string("banana"), strArr, 3) << "\n";
    cout << "string: contains \"grape\"? " << boolalpha
            << contains(string("grape"), strArr, 3) << "\n";
    delete[] strArr;
}
