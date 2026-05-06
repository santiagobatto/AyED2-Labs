/*
  @file weather.c
  @brief Implements weather mesuarement structure and methods
*/
#include <stdlib.h>
#include "weather.h"

Weather weather_from_file(FILE* file)
{
    Weather weather;

    // Completar acá, debo leer los 6 datos restantes del file
    unsigned int res;
    res = fscanf(file, " %d %d %d %u %u %u ", &weather._average_temp, &weather._max_temp, &weather._min_temp, &weather._pressure, &weather._moisture, &weather._rainfall); //res guarda la cantidad e & guarda la indo dentro de la estructura weather
 
  if (res != 6){
    fprintf(stderr, "Lectura incompleta.\n");
    exit(EXIT_FAILURE);
  }

  return weather;
}

void weather_to_file(FILE* file, Weather weather)
{
    fprintf(file, "%d %d %d %u %u %u", weather._average_temp,
            weather._max_temp, weather._min_temp, weather._pressure, weather._moisture, weather._rainfall);
}
