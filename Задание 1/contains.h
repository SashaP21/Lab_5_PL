#ifndef _1_CONTAINS_H
#define _1_CONTAINS_H

template <typename T>
bool contains(const T& el, const T* arr, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == el)
            return true;
    }
    return false;
}

#endif //_1_CONTAINS_H