#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "data.h"

void print_data(data_t d) {
    printf("NOMBRE: %s\n"
           "EDAD  : %d años\n"
           "ALTURA: %d cm\n\n",
           d.name, d.age, d.height);
}

int main(void) {

    data_t messi = {"Leo Messi", 36, 169};
    print_data(messi);

    printf("name-size  : %lu bytes\n"
           "age-size   : %lu bytes\n"
           "height-size: %lu bytes\n"
           "data_t-size: %lu bytes\n", /* COMPLETAR tamanio de cada miembro de la estructura data_t*/ 
           sizeof(messi.name), //devuelve la cantidad de bytes ocupados por una expresion o tipo
           sizeof(messi.age),
           sizeof(messi.height),
           sizeof(messi));

  //Mostrar la direccion de memoria de cada campo
  printf("---Direcciones de memoria de Punteros---\n");
  printf("Direccion de memoria messi.name: %p\n", (void *) &(messi.name));
  printf("Direccion de memoria messi.age: %p\n", (void *) &(messi.age));  
  printf("Direccion de memoria messi.height: %p\n", (void *) &(messi.height));
    
  printf("---Indices de memoria (uintptr_t) ---\n");
  printf("Direccion de memoria messi.name: %lu\n", (uintptr_t) &(messi.age));
  printf("Direccion de memoria messi.age: %lu\n", (uintptr_t) &(messi.age));  
  printf("Direccion de memoria messi.height: %lu\n", (uintptr_t) &(messi.height));
    
  //Guardo la estructura en memoria dinamica (heap)
  data_t *p = malloc(sizeof(data_t));
  
  if (p == NULL) {
    fprintf(stderr, "Error al asignar memoria\n");
    return EXIT_FAILURE;
  }
    
  //Inicializo
  strcpy(p->name, "Leo Messi");
  p->age = 36;
  p->height = 169;
  
  printf("Datos de la estructura en el heap:\n");
  print_data(*p);
  
  //Libero
  free(p);
  p = NULL;
  
  return EXIT_SUCCESS;
  }
