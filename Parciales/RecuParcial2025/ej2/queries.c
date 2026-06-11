/*
  @file queries.c
  @brief Consultas sobre tablas de datos climáticos.
*/
#include <limits.h>
#include "queries.h"

/**
 * @brief Dado un año, calcula para cada mes de ese año la máxima precipitación
 * en un día.
 *
 * @param a Tabla de datos climáticos
 * @param year Año, entre FST_YEAR (1980) y LST_YEAR (2016)
 * @param output Arreglo de salida
 */
void max_daily_rainfall(WeatherTable a, int year, int output[MONTHS]) {

//el anio viene como 2003 por ej, debo convertirlo a indice de la matriz
unsigned int actual_year = year - 1980u;
  
  for (month_t month = january; month <= december; month++) {
    unsigned int cont_max_rainfall = 0u;
    for (unsigned int day = 0; day < DAYS; day++) {
    
      if (a[actual_year][month][day]._rainfall > cont_max_rainfall) {
        cont_max_rainfall = a[actual_year][month][day]._rainfall;
      }
    }
    output[month] = cont_max_rainfall;
  }

}


