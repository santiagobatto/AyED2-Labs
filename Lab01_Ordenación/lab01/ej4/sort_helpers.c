#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "sort_helpers.h"

/* Variables globales privadas (solo visibles en este archivo) */
static unsigned int comparisons_counter = 0;
static unsigned int swaps_counter = 0;
static clock_t start_time;

bool goes_before(int x, int y) {
    comparisons_counter++; // Cada vez que comparamos, sumamos uno
    return x <= y;
}

bool array_is_sorted(int a[], unsigned int length) {
    bool sorted = true;
    for (unsigned int i = 0; i < length - 1; i++) {
        // Ojo: acá usamos <= directo para no ensuciar las estadísticas del sort
        sorted = sorted && (a[i] <= a[i+1]);
    }
    return sorted;
}

void swap(int a[], unsigned int i, unsigned int j) {
    if (i != j) {
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
        swaps_counter++; // Solo contamos si realmente hubo intercambio
    }
}

/* Manejo de contadores */
void reset_comparisons_counter() {
    comparisons_counter = 0;
}

unsigned int comparisons_number() {
    return comparisons_counter;
}

void reset_swaps_counter() {
    swaps_counter = 0;
}

unsigned int swaps_number() {
    return swaps_counter;
}

/* Manejo del tiempo */
void set_current_time() {
    start_time = clock();
}

double calculate_elapsed_time() {
    clock_t end_time = clock();
    // Calculamos la diferencia y la pasamos a milisegundos
    return ((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000.0;
}