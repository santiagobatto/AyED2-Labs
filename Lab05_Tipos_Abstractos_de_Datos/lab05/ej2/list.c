#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct _list {
    elem data;
    struct _list *next; //puntero a la estructura _list
};

list empty() { //En ej4 lab04 explicado
    return NULL;
}

list addl(elem e, list l) {
    list aux = malloc(sizeof(struct _list)); //Reservo espacio en la memoria para el nuevo vagon con el primer elem
    aux->data = e;
    aux->next = l; //Apunto a lo que sigue de la lista  

    return aux; 
}

bool is_empty(list l) {
    return (l == NULL);
}

elem head(list l) {
    assert(!is_empty(l));

    elem e = l->data;
    return e;
}

list tail(list l) { //devuelve la lista sin el primer elemento
    assert(!is_empty(l));

    list aux = l;
    l = l->next; //ahora apunta al segundo elemento
    free(aux); //destruyo el primer elem

    return l;
}

list addr(list l, elem e) { //Agrega e al final de l
    list aux = malloc(sizeof(struct _list)); //Mi nuevo ultimo vagon
    aux->data = e;
    aux->next = NULL;
    
    if (l == NULL) { //Si la lista esta vacio, el nuevo vagon es el primero
        return aux;
    }
        
    list q = l; //q apunta a la dir de memoria de l, por lo tanto puede modificarla
    while (q->next != NULL) { //Termina cuando q llego al ultimo vagon
        q = q->next;
    }
    
    q->next = aux; //agrega desdepues del ultimo vagon el vagon nuevo con el elemento
    
    return l;
}

int length(list l) {
    int cont = 0;
    list aux = l;

    while (aux != NULL) { //si l = NULL, si hago aux->next hace que el programa explote 
        cont++;
        aux = aux->next;
    }
    return cont;
}

list concat(list l, list l0) {
    
    if (l == NULL) {
        return l0; //Y si ambas estan vacias retorno la 2da que es lo mismo q la primera
    
    } else {
        list aux = l;

        while (aux->next != NULL) {
            aux = aux->next;
        }
        //ahora aux ya esta en la ultima pos de la lista
        aux->next = l0;
    }
    return l;
}

elem index (list l, int n) { //Devuelve el n-esimo elemento de l (tengo que pensarlo a n como cdad de saltos siempre a partir del primero)
    assert(n < length(l)); 

   list aux = l; //Empiezo parado en el primer vagon
   int i = 0;

   /* si me piden el elem 0, 0<0? false y retorno el primero vagon (0 saltos)
      si me piden n=2, 0<2? true y avanzo 1 vagon (ahora estoy parado en el segundo vagon)
                        1<2? true y avanzo un vagon (ahora estoy parado en el tercer vagon)
                         2<2? false y retorno el tercer vagon
   */
   while (i < n) {  
    aux = aux->next;
    i++;
   }

   return aux->data;
} 

list take(list l, int n) { //toma los primeros n vagones y destruyo los demas

    if (n == 0) { 
        destroy_list(l); 
        return NULL; //antes seguia ejecutando e intentaba acceder a memoria de l que ya no existe;
    } //No toma ninguno y borra la lista

    list aux = l;
    int i = 0;

    //pedir mas vagones de los que tengo, antes llegaba al final (aux=null y hacia aux=aux->next! SEGMENTATION FAULT)
    if (n >= length(l)) {
        return l; //Devuelvo la lista tal cual
    }

    //Debo ir hasta el vagon (n-1) que sera el nuevo ultimo, y desenganchar y destruir todo lo que le sigue    
    //while(i < n) { //ej n=3, freno en i=2 pq ya hice i= 0,1,2; estaba en el vagon 0 y salte 3 veces entonces estoy en el 4to

    while(i < n-1) {
        aux = aux->next;
        i++;
    }

    //aux ahora esta en el ultimo vagon
    list list_a_destruir = aux->next;
    aux->next = NULL; //Corto el enganche y aux es el final de la lista

    destroy_list(list_a_destruir); //Destruye el resto
    return l;
}

list drop (list l, int n) { //elimina n vagones de l

    int i = 0; //la posicion 0 es el primer vagon de l

    while (i < n) {
        // 0<0? False, no elimino nada; 
        // 0<1? True, elimino el primero, i = 1 ; 1<1? False, no elimino nada
        // 0<2? True, elimino el primero, i = 1 ; 1<2? True, elimino el segundo, i = 2 ; 2<2? False, no elimino nada
        l = tail(l);
        i++;
    }

    return l;
}

list copy_list(list l) {
    //Para crear un tren nuevo, voy vagon por vagon del viejo y creando nuevos para el nuevo tren y enganchando

    list copy = empty(); //nueva lista
    list aux = l; //recorre el tren viejo

    while(aux != NULL) { //mientras haya vagones en el tren original
        copy = addr(copy, aux->data); //agg a copia el elem del tren original
        aux = aux->next; //voy al sig vagon del original
    }

    return copy;
}

void destroy_list(list l) {
    list aux;

    while(l != NULL) {
        aux = l;
        l = l->next;
        free(aux);
        aux = NULL;
    }
}
