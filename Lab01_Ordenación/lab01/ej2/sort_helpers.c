#include "sort_helpers.h"

//Todo esto ya esta implementado pero en Linux

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

unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    unsigned int ppiv = izq;
    unsigned int i = izq + 1;
    unsigned int j = der;

    while (i <= j) {
        if (goes_before(a[i], a[ppiv])) {
            i++;
        } else if (goes_before(a[ppiv], a[j])) {
            j--;
        } else {
            swap(a, i, j);
            i++;
            j--;
        }
    }
    swap(a, ppiv, j);
    ppiv = j;
    return ppiv;
}