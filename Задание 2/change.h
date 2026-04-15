#ifndef _2_CHANGE_H
#define _2_CHANGE_H

#include "contains.h"
#include <iostream>

template <typename T>
bool change(const T& el1, const T& el2, T* arr, int size) {
    if (!contains(el1, arr, size) || !contains(el2, arr, size)) {
        std::cout << "Error: element(s) not found\n";
        return false;
    }
    if (el1 == el2) {
        std::cout << "Elements are equal, no change needed\n";
        return true;
    }
    int i1 = -1, i2 = -1;
    for (int i = 0; i < size; i++) {
        if (arr[i] == el1) {
            i1 = i;
        }
        else if (arr[i] == el2) {
            i2 = i;
        }
        if (i1 != -1 && i2 != -1)
            break;
    }
    arr[i1] = el2;
    arr[i2] = el1;
    std::cout << "Change was successful\n";
    return true;
}

#endif //_2_CHANGE_H