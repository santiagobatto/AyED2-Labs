#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "list.h"

#define MAX_LENGTH 100

struct _list {
    elem elems[MAX_LENGTH];
    int size; //cantidad de vagones ocupados
};

list empty() {
    list l = malloc(sizeof(struct _list)); //Reservo memoria para un arreglo fijo de 100 elementos, entonces ya no necesito hacerlo para vada vagon nuevo
    l->size = 0;

    return l;
}

list addl(elem e, list l) { //agrega al inicio, tengo que desplazar los elementos del arreglo a la derecha

    assert(l->size < MAX_LENGTH); //Que la ultima pos disponible para desplazar un vagon sea el penultimo, asi desplazo al ultimo
    
    for (int i = l->size; i > 0; i--) { //i empieza en size, pero como el arreglo arranca en 0, estoy parado en la pos size+1, que es un hueco libre
        l->elems[i] = l->elems[i-1];   //muevo el elemento de la izquierda(i-1) a la derecha(i), i corta en 1 -> a[][i][]... y no en 0 ->a[i] pq sino intenta acceder a algo fuera del limite  
    }

    //cuando termine de desplazarlos
    l->elems[0] = e;
    l->size +=1;

    return l;
}

bool is_empty(list l) {
    return (l->size == 0);
}

elem head(list l) { //primer elemento
    assert(!is_empty(l));
    return l->elems[0];
}

list tail(list l) { //quita el primero y deja los demas
    assert(!is_empty(l));

    for (int i = 0; i < l->size - 1; i++) { //debo ir desde i=0 hasta i=3, que seria el 4to elemento
        l->elems[i] = l->elems[i+1];
    }

    l->size --;
    return l;
}

list addr(list l, elem e) { //añade e al final de la lista
    assert(l->size < MAX_LENGTH);

    l->elems[l->size] = e;
    l->size ++;

    return l;
}

int length(list l) {
    return l->size;
}

list concat(list l, list l0) {
    assert((l->size + l0->size) <= MAX_LENGTH);

    for(int i = 0; i < l0->size; i++) {
        l->elems[l->size] = l0->elems[i]; //Va añadiendo al final de la lista l los elementos de l0 (l->size es el primer hueco)
        l->size++; //size crece de a 1
    }

    return l;
}

elem index(list l, int n) {
    assert(l->size > n);

    return l->elems[n];
}

list take(list l, int n) { //toma los primeros n y remueve el resto
    
    if (n < l->size) {
        l->size = n; //Recorto los vagones que sobran
    }

    return l; //Si toma todos o mas vagones devuelvo la lista original
}

list drop(list l, int n){ //remuevo los primero n vagones
    
    if (n > l->size) { //si pide borrar mas vagones de los que tengo la dejo vacio y retorno
        l->size = 0;
        return l;
    }
    
    int i = 0;

    while (i < n) {
        l = tail(l); //va removiendo el primer elemento y desplazando los demas
        i++;
    }

    return l;
}

list copy_list(list l) {
    list copy = empty();
    copy->size = l->size;

    for(int i=0; i < l->size; i++) {
        copy->elems[i] = l->elems[i];
    }

    return copy;
}

void destroy_list(list l) { //como solo hice un mallon para el arreglo completo de 100, solo necesito destruir una vez
    free(l);
}
