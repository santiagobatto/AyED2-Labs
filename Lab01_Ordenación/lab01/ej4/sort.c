#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

///////////////////////SELECTION SORT/////////////////////////////////////

static unsigned int min_pos_from(int a[], unsigned int i, unsigned int length) {
    unsigned int min_pos = i;

    for (unsigned int j = i + 1; j < length; ++j) {    
        if (goes_before(a[j],a[min_pos])) { //Si en j va antes que nuestro minimo actual
            min_pos = j;
        }
    }
    return (min_pos);
}

void selection_sort(int a[], unsigned int length) {
    for (unsigned int i = 0; i < length; ++i) {
        unsigned int min_pos = min_pos_from(a, i, length);
        swap(a, i, min_pos);
    }
}
///////////////////////////INSERTION SORT///////////////////////////////////////////////////////

static void insert(int a[], unsigned int i) {
   unsigned int j = i;

    while (j > 0 && goes_before(a[j], a[j-1])) {
        swap(a, j-1, j);
        j--;
    }
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1; i < length; ++i) {
        assert(array_is_sorted(a, i));
         //Parte C: verificacion de cumplimiento de la invariante: el segmento a[0, i) esta ordenado
        insert(a, i);
    }
}

//////////////////////////////QUICK SORT////////////////////////////////////////

static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
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
        if (der > ppiv) {
            quick_sort_rec (a, ppiv + 1, der);
        }
    }
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}
