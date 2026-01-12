#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s) {
    unsigned int cont = 0;
    while (s[cont] != '\0') {
        cont ++;
    }
    return cont;
}

bool fstring_eq(fixstring s1, fixstring s2) { // No llamo a otras funciones y recorro la memoria solo una vez de izq a der, no uso variables extras
    unsigned int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]){
        i++;
    }
    return (s1[i] == s2[i]);
}

bool fstring_less_eq(fixstring s1, fixstring s2) { // No llamo a otras funciones y escaneo los bytes de la memoria de izq a der solo una vez
    unsigned int i = 0;
    while (s1[i] != '\0' && s1[i] == s2[i]){ //rompe cuando son diferentes
        i++;
    }
    // Si s1[i] es menor o igual al de s2[i] en la posición de la diferencia,
    // entonces s1 <= s2 alfabéticamente.
    return (s1[i] <= s2[i]);
}
