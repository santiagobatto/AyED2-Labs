#include "pair.h"

pair_t pair_new(int x, int y) {
  pair_t pair;
  pair.fst = x;
  pair.snd = y;

  return pair;
}

int pair_first(pair_t p) { return p.fst; }

int pair_second(pair_t p) { return p.snd; }

pair_t pair_swapped(pair_t p) {
  int aux;
  aux = p.fst;
  p.fst = p.snd;
  p.snd = aux;

  return p;
}

void pair_destroy(pair_t p) {
  p.fst = p.fst;
  p.snd = p.snd;
}