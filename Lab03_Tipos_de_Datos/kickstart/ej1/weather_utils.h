#ifndef _WEATHER_UTILS_H
#define _WEATHER_UTILS_H

#include "weather_table.h"

//Obtiene la menor temperatura minima historica registrada
int historic_min_temp(WeatherTable a);

//Registra la mayor temperatura maxima registrada durante cada anio
void yearly_max_temp(WeatherTable a, int output[YEARS]);

//Registra el mes del anio que hubo la mayor cdad de precipitacion
void monthly_most_precipitations(WeatherTable a, month_t output[YEARS]);

#endif
