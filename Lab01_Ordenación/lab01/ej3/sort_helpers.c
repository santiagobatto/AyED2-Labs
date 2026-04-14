#include "sort_helpers.h"

bool goes_before(int x, int y) {
    return x <= y; // Orden ascendente estándar
}

bool array_is_sorted(int a[], unsigned int length) {
    bool sorted = true;
    for (unsigned int i = 0; i < length - 1; i++) {
        sorted = sorted && goes_before(a[i], a[i+1]);
    }
    return sorted;
}

void swap(int a[], unsigned int i, unsigned int j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}