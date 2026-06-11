/*
@file array_helpers.c
@brief Array Helpers method implementation
*/
#include <stdio.h>
#include <stdlib.h>

#include "array_helpers.h"

void array_dump(RankingTable a) {
    for (unsigned int ranking = 0u; ranking < NO_PLAYERS; ranking++) {
        for (unsigned int type = road; type <= track; type++) {
            Ranking aux = a[ranking][type];
            fprintf(stdout, " %u %s %i %i %s %s %f\n",
                    ranking+1, (type==0?"road":"track"), aux.pos_prev, aux.diff, aux.name, aux.team, aux.points
            );
        }
    }
}

void array_from_file(RankingTable array, const char *filepath) {
    FILE *file = NULL;

    file = fopen(filepath, "r");
    if (file == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }

    type_t type;

    int i = 0;
    
    //feof es true despues que una lectura fallo, o es la ultima linea, entoncees cuando llega al final es true y !true = false es decir, mientras no sea el final del archivo
    
    while (!feof(file)) { // <- Completar

        //El primer dato de la linea es T, road o track, y este parte al arreglo en 2 dimensiones
        int res = fscanf(file, " @%u ", &type); // <- Completar

        if (res != 1) { 
            //si es != 1 fallo la lecturar
            //si NO es el final, error grave
            if (!feof(file)) {
            fprintf(stderr, "Invalid ranking type.\n");
            exit(EXIT_FAILURE);
          }
          
        } else {
          //res == 1  
         /* COMPLETAR: Leer Ranking */
          Ranking ranking_row = ranking_from_file(file); //leo el resto de la fila y devuelve el struct listo

          /* COMPLETAR: guardar ranking en array bidimensional*/
          array[type][ranking_row.pos -1u] = ranking_row; //El rankeado 1 va en el indice 0
          i++;      
        }
        
      } //fin del while
    
    fclose(file);
}



    /*Resumen del Flujo General:

array_from_file abre el archivo e itera.  

En cada vuelta, lee el índice de la matriz.  

Llama a ranking_from_file para que lea el resto de la línea y le devuelva un struct.  


array_from_file recibe ese struct y lo acomoda en la matriz usando los índices correspondientes.  

Se repite hasta que el archivo se termina.  

Esta estructura se repite porque separa la lógica de almacenamiento (matriz) de la lógica de interpretación (campos del archivo)
    */
