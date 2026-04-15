#include <iostream>
#include <string>
#include "change.h"

using std::cout;
using std::string;

template <typename T>
void printArray(const T* arr, int size) {
    for (int i = 0; i < size; ++i) {
        if (i > 0)
            cout << ", ";
        cout << arr[i];
    }
    cout << "\n";
}

int main() {
    cout << "=== int ===\n";
    int sizeInt = 5;
    int* intArr = new int[sizeInt]{10, 20, 30, 40, 50};
    cout << "Original Array: ";
    printArray(intArr, sizeInt);

    cout << "Change 20 and 40:\n";
    change(20, 40, intArr, sizeInt);
    cout << "After change: ";
    printArray(intArr, sizeInt);

    cout << "Change 60 and 30:\n";
    change(60, 30, intArr, sizeInt);
    cout << "After attempt: ";
    printArray(intArr, sizeInt);

    delete[] intArr;
    cout << "\n";

    cout << "=== double ===\n";
    int sizeDouble = 4;
    double* doubleArr = new double[sizeDouble]{1.1, 2.2, 3.3, 4.4};
    cout << "Original array: ";
    printArray(doubleArr, sizeDouble);

    cout << "Change 1.1 and 4.4:\n";
    change(1.1, 4.4, doubleArr, sizeDouble);
    cout << "After change: ";
    printArray(doubleArr, sizeDouble);

    cout << "Change 5.5 and 2.2 (5.5 not in array):\n";
    change(5.5, 2.2, doubleArr, sizeDouble);
    cout << "After attempt: ";
    printArray(doubleArr, sizeDouble);

    delete[] doubleArr;
    cout << "\n";

    cout << "=== string ===\n";
    int sizeStr = 3;
    string* strArr = new string[sizeStr]{"apple", "banana", "cherry"};
    cout << "Original array: ";
    printArray(strArr, sizeStr);

    cout << "Change \"apple\" and \"cherry\":\n";
    change(string("apple"), string("cherry"), strArr, sizeStr);
    cout << "After change: ";
    printArray(strArr, sizeStr);

    cout << "Change \"kiwi\" and \"banana\" (kiwi not in array):\n";
    change(string("kiwi"), string("banana"), strArr, sizeStr);
    cout << "After attempt: ";
    printArray(strArr, sizeStr);

    delete[] strArr;
}