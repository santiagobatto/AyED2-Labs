#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void absolute(int x, int *y) {
    // Completar aquí
    if (x<0) *y = -x;
    else *y = x;
}

int main(void) {
    int a=0, res=0;  // No modificar esta declaración
    // --- No se deben declarar variables nuevas ---
    
    // Completar aquí
    int *p = &a;
    *p = -10; //ya modifique el valor de a, paso por parametro la dir de memoria de res
    
    absolute(a, &res);
    printf("Resultado: %d\n", res);
    
    assert(res >= 0 && (res == a || res == -a));
    return EXIT_SUCCESS;
    
    //int *y es de tipo out, no me importa su valor de entrada (0) sino de salida
    //C solo tiene parametros tipo in en funciones, para que sea de salida debo usar punteros
}

