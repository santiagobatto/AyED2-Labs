#include "pair.h"
#include <stdlib.h> //provide malloc

/*Ahora uso un tipo generico elem, si en el futuro quiero usar otro tipo, solo
 * debo cambiarlo en la especificacion*/
struct s_pair_t {
  elem fst;
  elem snd;
};

pair_t pair_new(elem x, elem y) {
  pair_t pair;
  pair = malloc(sizeof(struct s_pair_t));

  pair->fst = x;
  pair->snd = y;

  return pair;
}

elem pair_first(pair_t p) { return p->fst; }

elem pair_second(pair_t p) { return p->snd; }

pair_t pair_swapped(pair_t pair) { return (pair_new(pair->snd, pair->fst)); }

void pair_destroy(pair_t p) {
  free(p);
  p = NULL;
}