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
    
    //iniciacion logica -> debo buscar un contraejemplo para mis banderas
    res.is_upperbound = true;
    res.is_lowerbound = true;
    res.exists = false;
    res.where = 0;

    for (unsigned int i = 0; i < length; i++) {

        if (value == arr[i]) {
            res.exists = true;
            res.where = i;
        }

        //value es cota superior? si es menor a algun elemento, ya no lo es. Si es mayor o igual, sigue siendo
        if (value < arr[i]) {
            res.is_upperbound = false;
        }

        //value es cota inferior? si es mayor a algun elemento, ya no lo es. Si es menor o igual, sigue siendo
        if (value > arr[i]) {
            res.is_lowerbound = false;
        }   
    }
    return res;
}

int main(void) {
    unsigned int length;
    
    printf("Cuantos elementos vas a ingresar? El tamanio maximo definido del arreglo es: %u \n", (unsigned int)ARRAY_SIZE);

    if (scanf("%u", &length) != 1 || length == 0) { //scanf devuelve 1 si se leyo un valor con exito 
        printf("Error: Tamanio del arreglo invalido!\n");
        return 1;
    }

    int a[length];
    for (unsigned int i = 0; i < length; i++) {
        printf("Ingrese el valor del arreglo en la posicion [%u:]\n", i);
        scanf("%d", &a[i]);
    }

    int value;
    printf("Ingrese el valor a verificar: \n");
    scanf("%d", &value);

    struct bound_data result = check_bound(value, a, length);

    //Salida
    printf("--------Resultados--------\n");

    bool none = true;
    if (result.is_upperbound) {
        printf("El valor ingresado %d es cota superior de todos los elementos del arreglo!\n", value);
        none = false;
    }

    if (result.is_lowerbound) {
        printf("El valor ingresado %d es cota inferior de todos los elementos del arreglo!\n", value);
        none = false;        
    }
    //Si existe en el arreglo && es minimo o maximo, mostrar la pos donde se encuentra
    if (result.exists){
        if (result.is_upperbound) {
            printf("El valor ingresado %d existe en el arreglo, es maximo y se encuentra en la posicion [%u]", value, result.where);
            none = false;
        }
        if (result.is_lowerbound) {
            printf("El valor ingresado %d existe en el arreglo, es minimo y se encuentra en la posicion [%u]", value, result.where);
            none = false;
        }
    }

    if (none == true) {
        printf("\nTu valor ingresado no es cota ni max/min :(");
    }
    return EXIT_SUCCESS;
}
