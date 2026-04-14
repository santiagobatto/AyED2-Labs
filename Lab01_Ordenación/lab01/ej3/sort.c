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
    unsigned int ppiv = izq; //La primera posicion del segmento a ordenar

    i = izq + 1;
    j = der;

    while (i <= j) {
        
        if (goes_before(a[i], a[ppiv])) { //Si es menor va a la izq del pivot y sigue avanzando
            i = i + 1;
        } else if (goes_before(a[ppiv], a[j])) { //Si es mayor va a la der del pivot y retrocede buscando otro
            j = j - 1;
        } else { // a[i] es mayor y a[j] es menor
            swap(a, i, j);
            i += 1;
            j -= 1;
        }
    }
    swap(a, izq, j);
    ppiv = j;

    return ppiv;
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    unsigned int ppiv;

    if (der > izq) {
        ppiv = partition(a, izq, der);

        if (ppiv > izq) {
            quick_sort_rec (a, izq, ppiv - 1);
        }

        if (ppiv < der) {
            quick_sort_rec (a, ppiv + 1, der);
        }    
    }
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}

