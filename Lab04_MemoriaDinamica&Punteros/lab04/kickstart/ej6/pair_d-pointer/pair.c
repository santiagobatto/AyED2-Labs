#include "pair.h"
#include <stdlib.h> //provide malloc

/*AGREGO LA ESTRUCTURA DE PAIR: Ahora solo se puede acceder o modificar el
 * estado del par a traves de las operaciones provistas(funciones del TAD) Eso
 * es la definicion de encapsulamiento */
struct s_pair_t {
  int fst;
  int snd;
};

pair_t pair_new(int x, int y) {
  pair_t pair;
  pair = malloc(sizeof(struct s_pair_t));

  pair->fst = x;
  pair->snd = y;

  return pair;
}

int pair_first(pair_t p) { return p->fst; }

int pair_second(pair_t p) { return p->snd; }

pair_t pair_swapped(pair_t pair) { return (pair_new(pair->snd, pair->fst)); }

void pair_destroy(pair_t p) {
  free(p);
  p = NULL;
}