#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static void insert(int a[], unsigned int i, unsigned int length) { //Parte A: insertion sort
    unsigned int j = i;

    while (j > 0 && goes_before(a[j], a[j-1])) {

        //Parte B: muestro que voy a mover
        printf("Swap: Muevo el valor %d a la posicion %u\n", a[j], j-1);
        
        swap(a, j-1, j);
        j--;

        //muestro como quedo luego de ordenar esa parte
        array_dump(a,length);
    }
}

void insertion_sort(int a[], unsigned int length) {
    printf("Arreglo original:\n");
    array_dump(a,length);

    for (unsigned int i = 1; i < length; ++i) {
        assert(array_is_sorted(a, i));
         //Parte C: verificacion de cumplimiento de la invariante: el segmento a[0, i) esta ordenado
        insert(a, i, length);
        printf("Fin de iteracion %u\n", i);
        printf("------------------\n");
    }
}
