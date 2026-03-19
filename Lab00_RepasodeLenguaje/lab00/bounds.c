#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 4

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

struct bound_data check_bound(int value, int arr[], unsigned int length) {
    struct bound_data res;

    /*
        Mi funcion debe:
            chequear si value es mayor o igual a todos los elementos de arr -> bool
            // si es menor o igual a todos los elementos de arr -> bool
            si value se encuentra en el array -> bool
                si se encuentra, en que pos del array

        Para esto necesito, recorrer el array de inicio al final evaluando en cada iteracion:
            guardar en una var temporal el max y min elemento
            evaluar cada iteracion si el elem en la pos [] es el mismo que value
    */

    //Recorro el array
    for (int i = 0; i++; i < length) {

        
        
    }

    return res;
}

int main(void) {
    int a[ARRAY_SIZE] = {0, -1, 9, 4};
    int value=9;
    //
    // TODO: COMPLETAR - Pedir entrada al usuario
    //
    struct bound_data result = check_bound(value, a, ARRAY_SIZE);

    // TODO: REEMPLAZAR LO SIGUIENTE LUEGO POR LA SALIDA QUE PIDE EL ENUNCIADO
    printf("%d", result.is_upperbound); // Imprime 1
    printf("%d", result.is_lowerbound); // Imprime 0
    printf("%u", result.exists);        // Imprime 1
    printf("%u", result.where);         // Imprime 2

    return EXIT_SUCCESS;
}

