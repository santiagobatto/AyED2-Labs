#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "list.h"

#define MAX_LENGTH 100

struct _list {
    elem a[MAX_LENGTH];
    int start; //pos donde comienza los elementos de la lista
    int size; //cdad de elementos
};

list empty() {
    list l = malloc(sizeof(struct _list)); //si antes cuando usaba un arreglo, debia ya reservar la memoria para la caja entera, porque ahora no?
    l->start = 0;
    l->size = 0;

    return l;
}

list addl(elem e, list l) {
    assert(l->size < MAX_LENGTH);

    //si start es 0, un paso a la izq es -1 y no da la vuelta hacia el indice 99(MAX LENGTH - 1) entonces tengo que SUMARLE EL MAX ANTES DEL MODULO para que lo haga en circulo
    l->start = (l->start - 1 + MAX_LENGTH) % MAX_LENGTH; //nuevo primer vagon
    l->a[l->start] = e;
    l->size ++;

    return l;
}

bool is_empty(list l) {
    return (l->size == 0);
}

elem head(list l) {
    assert(!is_empty(l));

    return l->a[l->start];
}

list tail(list l) {
    assert(!is_empty(l));

    //el nuevo inicio es un paso a la derecha en circulo
    l->start = (l->start + 1) % MAX_LENGTH;
    l->size --;

    return l;
}

list addr(list l, elem e) {
    assert(l->size < MAX_LENGTH);

    //Donde va el ultimo vagon? En la pos start + size en circulo-> me deja exactamente en el nuevo vagon libre
    int pos_libre = (l->start + l->size ) % MAX_LENGTH;
    l->a[pos_libre] = e;
    l->size++;

    return l;
}

int length(list l) {
    return l->size;
}

list concat(list l, list l0){
    assert(l->size + l0->size <= MAX_LENGTH);

    for(int i = 0; i < l0->size; i++) { //addr e index ya hacen la matematica
        l = addr(l, index(l0, i));
    }

    return l;
} 

elem index(list l, int n) {
    assert(n < l->size);

    //me muevo n pasos a la derecha desde start en circulo
    return l->a[(l->start + n) % MAX_LENGTH];
}

list take(list l, int n) {

    //si pide mas vagones que size, no hacemos nada, si son menos, ahora el tamaño de la lista es menor
    if (n < l->size) {
        l->size = n;
    }

    return l;
}

list drop(list l, int n) {

    //si me piden dropear mas que el size, dejo la lista vacia
    if (n > l-> size) {
        l->size = 0;
        return l;
    }

    //como es circular, simplemente avanzamos start n lugares a la derecha, O(n)
    l->start = (l->start + n) % MAX_LENGTH;
    l->size = l->size + n;

    return l;
}

list copy_list(list l) {
    list copy = empty();

    //uso funciones ya conocidas para evitar matematica
    for(int i = 0; i < length(l); i++) {
        copy = addr(copy, index(l, i));
    }

    return copy;
}

void destroy_list(list l) {
    //como solo hice un malloc, necesito solo 1 free
    free(l);
}
