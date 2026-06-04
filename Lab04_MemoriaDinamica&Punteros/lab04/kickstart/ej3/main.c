#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef Node *List;

/**
 * @brief Construye y devuelve una lista de ejemplo de 3 elementos
 */
List setup_example() {
  // COMPLETAR ACÁ!
  int i = 3; // Es porque quiero una lista de 3 elementos (pseudocodigo)
  List my_list = malloc(sizeof(Node));
  Node *a_node; // Declaro mi puntero con *

  a_node = my_list; // Apunta a la direccion de memoria de mi lista y la va
                    // construyendo
  i--; // Para el primer elemento de mi lista, ya cree el primero con malloc,
       // entonces resto 1 porque me quedan 2 en el bucle. i=2;

  while (i > 0) {
    a_node->data = i * 10; // 20, 10
    a_node->next = malloc(
        sizeof(Node)); // Reservo memoria para el sig elemento de la lista
    a_node = a_node->next;
    i--;
  }
  a_node->data = 0;
  a_node->next = NULL;
  a_node =
      NULL; // Borro el puntero que contruyo la lista porque ya no lo necesito

  return my_list;
}

void show_list(List xs) {
  printf("[ ");
  while (xs != NULL) {
    printf("%i, ", xs->data);
    xs = xs->next;
  }
  printf("]\n");
}

int main(void) {
  List my_list;

  my_list = setup_example();

  show_list(my_list);

  return 0;
}
