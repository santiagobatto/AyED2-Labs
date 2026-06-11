#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "tape.h"

struct _s_node {
    tape_elem elem;
    struct _s_node *next;
};

typedef struct _s_node * node_t;

struct _s_tape {
    unsigned int size;
    node_t cursor;  // Puntero al elemento actual
    node_t start;   // Puntero al primer nodo de la cinta
};

/* es una simple lista enlazada con un cursor para ver donde estamos parados, el nodo enlazado solo es next asi que si
quiero agregar por izq o eliminar el actual, NECESITO CONOCER EL ANTERIOR. como no tengo flecha hacia atras, tengo que recorrerlo
desde start hasta que el siguiente del cursor sea start! 

Empeza x mas faciles, create, length, empty
*/
static bool invrep(tape_t tape) {
    // 1. La cinta en sí no puede ser NULL
    if (tape == NULL) {
        return false;
    }

    // 2. Control de la cinta vacía (size 0 implica punteros NULL)
    if (tape->size == 0) {
        return (tape->start == NULL && tape->cursor == NULL);
    }

    // 3. Si el size es mayor a 0, start no puede ser NULL
    if (tape->start == NULL) {
        return false;
    }

    // 4. Recorremos la cinta para contar los nodos reales y buscar el cursor
    unsigned int count = 0;
    node_t current = tape->start;
    bool cursor_found = false;

    while (current != NULL) {
        if (current == tape->cursor) {
            cursor_found = true; // Confirmamos que el cursor está en la cinta
        }
        count++;
        current = current->next;
    }

    // 5. Verificamos que el cursor sea válido:
    // O bien es NULL (estado stop) o bien lo encontramos en nuestro recorrido
    bool cursor_valid = (tape->cursor == NULL) || cursor_found;

    // La cinta es consistente solo si la cantidad de nodos coincide con 'size' 
    // y el cursor está apuntando a un lugar legal.
    return (count == tape->size) && cursor_valid;
}

static node_t create_node(tape_elem e) {
    node_t node = malloc(sizeof(struct _s_node));
    node->elem = e;
    node->next = NULL;

    return node;
}

static node_t destroy_node(node_t node) {
    free(node);
    return NULL;
}

tape_t tape_create(void) {
    tape_t tape=NULL;
    /* COMPLETAR */
    tape = malloc(sizeof(struct _s_tape));
    tape->size = 0;
    tape->start = NULL;
    tape->cursor = NULL;

    assert(invrep(tape) && tape_is_empty(tape) && tape_at_start(tape));
    return tape;
}

tape_t tape_rewind(tape_t tape) { //posiciona el cursor al inicio
    
    tape->cursor = tape->start;
    assert(tape_at_start(tape)); //pre y post
    
    return tape;
}


bool tape_at_start(tape_t tape) {
    return (tape->cursor == tape->start);
}

bool tape_at_stop(tape_t tape) { //Indica si el cursor esta apuntando fuera de la lista
    return (tape->cursor == NULL);
}

bool tape_is_empty(tape_t tape) {
    return (tape->size == 0);
}

unsigned int tape_length(tape_t tape) {
    return tape->size;
}

tape_t tape_step(tape_t tape) { //Avanza el cursos al sig elem
    
    if (tape_at_stop(tape)) { //si ya esta en posicion stop no hago nada
        return tape;
    }
    tape->cursor = tape->cursor->next; 

    return tape;
}

tape_t tape_insertl(tape_t tape, tape_elem e) { //como no puedo desplazarme a la izq, tengo que conocer el nodo anterior
    
    node_t node = new_node(e); 
    node_t aux->cursor = tape->cursor->next; //Puntero aux para recorrer la lista

    while(aux->cursor->next != tape->cursor) { //avanzo el cursor hasta que el siguiente sea el cursor original  
        aux = tape_step(aux); //avanzo el cursor hasta que quede en la pos a la izq de cursor
    }
    
    aux->cursor = node;
    return tape;
}

tape_t tape_insertr(tape_t tape, tape_elem e) { //ya estaba hecho
    assert(invrep(tape) && (!tape_at_stop(tape) || tape_is_empty(tape)));
    node_t new_node=create_node(e);
    if (tape->start!= NULL) {
        new_node->next = tape->cursor->next;
        tape->cursor->next = new_node;
        tape->cursor = new_node;
    } else {
        tape->start = new_node;
        tape->cursor = new_node;
    }
    tape->size++;
    assert(invrep(tape) && !tape_is_empty(tape) && !tape_at_stop(tape) && e == tape_read(tape));
    return tape;
}

tape_t tape_erase(tape_t tape) { //Elimina el elemento apuntado por el cursor
    assert(!tape_is_empty(tape) && !tape_at_stop(tape) && tape != NULL); //que sigfica en la pre y en la post tape --> tape_t?

    node_t node_to_delete = tape->cursor;

    //si el nodo a borrar es el primero
    if (tape_at_start(tape)) {
        tape->start = tape->start->next; //el nuevo inicio es el 2do
        tape->cursor = tape->start; //cursor pasa al nuevo inicio
    
    } else { //si el cursor esta al medio o al final
        node_t prev = tape->start;

        //recorro hasta el anterior al cursor
        while(prev->next != tape->cursor && prev != NULL) {
            prev = prev->next;
        }

        //Desengancho el nodo actual(prev->nex esta enganchado al cursor a borrar) y lo engancho al siguiente a este
        prev->next = tape->cursor->next;
        //El cursor avanza al siguiente elemento
        tape->cursor = tape->cursor->next; 
    }

    free(node_to_delete); //libero la memoria del nodo que saque
    tape->size--;

    return tape;
}

tape_elem tape_read(tape_t tape) { //Lee el elemento en la pos del cursor
    assert(!tape_is_empty(tape) && !tape_at_stop(tape));
    
    return tape->cursor->elem;
}

void tape_dump(tape_t tape) { //ya estaba hecho
    assert(invrep(tape));
    node_t node=tape->start;
    printf("#");
    while (node != NULL) {
        if (node != tape->cursor) {
            printf("-%c-", node->elem);
        } else {
            printf("-[%c]-", node->elem);
        }
        node = node->next;
    }
    if (tape->cursor==NULL) {
        printf("-[]-");
    }
    printf("#\n");
}

tape_t tape_copy(tape_t tape) {
    //y las pre?  PRE: {tape --> tape_t}

    tape_t copy = tape_create();
    node_t aux = tape->start; //Puntero para recorrer la cinta original 
    
    while(aux != NULL) { //Mientras no sea el fin de la cinta
        copy = tape_insertr(copy, aux->elem); //inserto en la copia lo que mira el aux del original
        aux->next; //avanzo el aux al sig nodo
    }
    copy = tape_at_start(copy); //y todas las otras postcondiciones?  * POS: {copy --> tape_t && copy != tape && tape_at_start(copy) && tape_length(tape) == tape_length(copy)}

    return copy;
}

tape_t tape_destroy(tape_t tape) {
    assert(tape != NULL);

    node_t current_node = tape->start;
    node_t next_node;

    //Recorro toda la cinta liberando vagon por vagon
    while (current_node != NULL) {
        next_node = current_node->next; //guardo dir del siguiente antes de borrar el actual
        free(current_node); //lo destruyo
        current_node = next_node;
    }

    free(tape); //Destruyo toda la estructura principal
    return NULL; //Postcondicion
}


