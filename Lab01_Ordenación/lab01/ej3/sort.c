#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    /* PRECONDITION: 
       0 <= izq < der < length of the array

     Permutes elements of a[izq..der] and returns pivot such that:
     - izq <= pivot <= der
     - elements in a[izq,pivot) all 'go_before' (according to function goes_before) a[pivot]
     - a[pivot] 'goes_before' all the elements in a(pivot,der]
    */

    unsigned int i, j;
    unsigned int ppiv = 0;

    i = izq + 1;
    j = der;

    while (i <= j) {
        if (goes_before(a[i], a[ppiv])) i = i + 1;
        if (goes_before(a[ppiv], a[j])) j = j - 1;
        if (a[i] > a[ppiv] && a[j] < a[ppiv]) {
            swap(a, i, j);
            i += 1;
            j -= 1;
        }
    }
    swap(a, ppiv, j);
    ppiv = j;

    return ppiv;
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    unsigned int ppiv = 0;

    if (der > izq) {
        ppiv = partition(a, izq, der);

        if (ppiv > izq) {
            quick_sort_rec (a, izq, ppiv - 1); //Segmentation fault porque si ppiv = 0 y ppiv = -1 es out of bounds
        
        } else quick_sort_rec (a, ppiv + 1, der);

        quick_sort_rec(a,ppiv + 1, der);
    }
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}

