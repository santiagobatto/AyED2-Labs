#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "intercalated_sort.h"

/**
 * @brief Ordena las posiciones pares del arreglo (0-based)
 * usando el algoritmo de ordenación por inserción.
 */
 
//Declaro mis funciones auxiliares
void swap (int *x, int *y) { //recibe 2 direcciones de memoria y modifica su valor
  int aux = *x;
  *x = *y;
  *y = aux;
}

void insert(int a[], unsigned int i) {
 unsigned int j = i;
 
 while (j >= 2u && a[j] < a[j-2u]) { //Solo ordena las pos pares, si el indice es < 2 -> segmentation Fault
  swap(&a[j-2u], &a[j]); //direccion de memoria de esas posiciones para que otro proc lo modifique
  j = j-2u; //casilla par anterior
 }
}
 
void intercalated_sort(int a[], int length) {

  unsigned int u_length = (unsigned int) length; //Casteo de tipos -> convierto el limite a unsigned int para comparar

  //Ordenar solamente las posiciones pares del arreglo: 0,2,4,6,...
  for (unsigned int i = 2u; i < u_length; i = i+2u) {
    insert(a, i);
  }
}



