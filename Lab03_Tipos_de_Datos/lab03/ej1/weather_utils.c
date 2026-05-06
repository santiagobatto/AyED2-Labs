#include <limits.h>
#include "weather_utils.h"

//Obtiene la menor temperatura minima historica registrada
int historic_min_temp(WeatherTable a){
  int res = INT_MAX;
  
  for (unsigned int year = 0u; year < YEARS; year++){
    for (month_t month = january; month <= december; month++){
      for (unsigned int day = 0u; day < DAYS; day++){
           if(a[year][month][day]._min_temp < res) res = a[year][month][day]._min_temp;
      }
    }
  }
  return res;
}

//Registra la mayor temperatura maxima registrada durante cada anio
void yearly_max_temp(WeatherTable a, int output[YEARS]){

  for (unsigned int year = 0u; year < YEARS; year++){
    int max_anual = INT_MIN;
    for (month_t month = january; month <= december; month++){
      for (unsigned int day = 0u; day < DAYS; day++){
           if(a[year][month][day]._max_temp > max_anual) max_anual = a[year][month][day]._max_temp;
      }
    }
    output[year] = max_anual;
  }
  
}

//Registra el mes del anio que hubo la mayor cdad de precipitacion

//funcion aux, dado un anio y mes, devuelve la suma de todas las precipitaciones
unsigned int sum_month_rainfall(WeatherTable a, unsigned int year, month_t month){
  unsigned int total_rainfall = 0u;
  
  for(unsigned int day = 0u; day < DAYS; day++){
    total_rainfall = a[year][month][day]._rainfall + total_rainfall;
  }
  
  return total_rainfall;
}

void monthly_most_precipitations(WeatherTable a, month_t output[YEARS]){
  
  for (unsigned int year = 0u; year < YEARS; year++){
    unsigned int total_rainfall = 0u; //contador de Prec del mejor mes
    month_t best_month = january; //inicio el mejor mes con el primero
    
    for (month_t month = january; month <= december; month++){
      unsigned int month_cont = sum_month_rainfall(a, year, month); //cantidad de Prec ese mes
      
      if(month_cont > total_rainfall) { //Si mes actual es mayor que el mejor mes temporal del anio 
        total_rainfall = month_cont;
        best_month = month;
      }
    }
    output[year] = best_month;
  }
}

