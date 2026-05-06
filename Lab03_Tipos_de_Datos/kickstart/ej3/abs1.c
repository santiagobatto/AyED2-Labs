#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int y) {
    if (x < 0) y = x * -1;
    else y = x;
    
}

int main(void) {
    int a=-10, res=0;
    
    absolute(a,res); 
    //Cuando llamo a abs, esta crea una copia local de las variables en su propio stack, cuando finaliza, este se destruye y la copia desaparece
    printf("Resultado: %d\n", res);
    
    return EXIT_SUCCESS;
}

