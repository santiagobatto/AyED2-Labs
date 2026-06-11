#include "flag_sort.h"

void swap(color_t a[], int i, int j);

/**
 * @brief Ordenar un arreglo de tres colores RED, WHITE y BLUE.
 *
 * Dado un arreglo cuyos elementos son tres colores posibles RED, WHITE y BLUE,
 * ordenarlos de manera que queden todos los RED primero, después todos los 
 * WHITE y al final todos los BLUE, formando la bandera de Córdoba.
 * 
 * @param a Arreglo de colores.
 * @param length Largo del arreglo.
 */
void flag_sort(color_t a[], int length) {
    
    unsigned int u_length = (unsigned int) length;
    unsigned int i,j,k;
    i = 0u;
    j = 0u;
    k = length - 1u;
    
    /*
    [0,i) Rojo -> si a[j] Rojo, debe ir al inicio e intercambio con elem en pos i, i++ y j++
    [i,j) Blanco -> si a[j] Blanco, esta ordenado, solo incremento j++
    [j,k] esta desordenado!
    [k+1,length) Azul -> si a[j] Azul, debe ir al final e intercambio con elem en pos k, k-- pero j se queda igual porque no se que color es el elemento que traje de la pos k
    */
    
    //como j solo aumenta y k solo decrementa y su limite es length - 1, con j<=k evito overflow
    while (j <= k && u_length > 0u) { 
      if (a[j] == red) { //rojo al inicio
        swap(a,i,j);
        i++;
        j++;
      }
      else if (a[j] == white) { //blanco ya acomodado
        j++;
      }
      else if (a[j] == blue) { //azul va al limite actual de la zona azul (pos k)
        swap(a,j,k);
        
        //como k decrementa despues de que el colo azul en a[j] va al final, debo controlar que no sea > 0
        if (k > 0u){
          k--;
        }
        else j++; //fuerzo la cota para que se rompa y se cumpla el bucle;
      }
    }
}

void swap(color_t a[], int i, int j) {
    color_t tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}
