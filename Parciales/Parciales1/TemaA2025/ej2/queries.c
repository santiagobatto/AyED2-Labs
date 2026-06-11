/*
  @file queries.c
  @brief Consultas sobre tablas de datos climáticos.
*/

#include "queries.h"

/**
 * @brief Total de lluvias de un año dado.
 *
 * @param a Tabla de datos climáticos.
 * @param year Año, entre FST_YEAR (1980) y LST_YEAR (2016).
 */
int year_rainfall(WeatherTable a, int year) {
    // COMPLETAR
    unsigned int u_year = (unsigned int) (year - 1980);
    unsigned int cont = 0u;
    
    for(month_t month = january; month <= december; month++){
      for(unsigned int day = 0u; day < DAYS; day++){
        cont = a[u_year][month][day]._rainfall + cont;
      }
    }

    return cont;
}
