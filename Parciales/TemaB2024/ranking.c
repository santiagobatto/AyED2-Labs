/*
  @file ranking.c
  @brief Implements store structure and methods
*/
#include <stdlib.h>
#include "ranking.h"
#include <string.h>

static const int NUMBER_OF_RANKING_VARS = 6;

Ranking ranking_from_file(FILE *file) {

    Ranking ranking;
    int a,b,c;
    char d[20], e[20];
    float f;

    int res = fscanf(file, " %d %d %d %s %s %f ", &a, &b, &c, d, e, &f); //completar, arreglos no lleva &
    // o tmb fscanf(file, EXPECTED_RANKING_FILE_FORMAT, &a, &b, &c, d, e, &f);

    /* COMPLETAR: se leyo correctamente? */
    if (res != NUMBER_OF_RANKING_VARS){
      fprintf(stderr, "Lectura incompleta.\n");
      exit (EXIT_FAILURE);
    }

    strcpy(ranking.name,d);
    strcpy(ranking.team,e);

    /* COMPLETAR: campos de ranking */
    ranking.pos = (unsigned int)a;
    ranking.pos_prev = (unsigned int)b;
    ranking.diff = c; //diferencia entre pos actual y previa
    ranking.points = f; //puntos totales
    
    return ranking;
}

//suma total de puntaje  de todos los ciclistas pertenecientes a ese equipo 
float total_track_points_per_team(RankingTable a, char *team_name) {
    float sum = 0.0f; //uso float para no perder decimales
    /* COMPLETAR, el tipo de carrera track es 1 */
    
    for(unsigned int i = 0u; i < 100u; i++){
      Ranking ciclista = a[1][i]; //a[1] pq es bidimencional parte de track y [i] por la posicion
      
      if(strcmp(ciclista.team, team_name) == 0) { //si ambos son iguales
        sum = ciclista.points + sum;
      }
    }
    
    return sum;
}
