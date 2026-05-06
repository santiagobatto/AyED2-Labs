/*
  @file main.c
  @brief Defines main program function
*/

/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "weather_table.h"
#include "weather_utils.h"

/**
 * @brief print usage help
 * @param[in] program_name Executable name
 */
void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Load climate data from a given file in disk.\n"
           "\n"
           "The input file must exist in disk and every line in it must have the following format:\n\n"
           "<year> <month> <day> <temperature> <high> <low> <pressure> <moisture> <precipitations>\n\n"
           "Those elements must be integers and will be copied into the multidimensional integer array 'a'.\n"
           "\n\n",
           program_name);
}

/**
 * @brief reads file path from command line
 *
 * @param[in] argc amount of command line arguments
 * @param[in] argv command line arguments
 *
 * @return An string containing read filepath
 */
char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return (result);
}

/**
 * @brief Main program function
 *
 * @param[in] argc amount of command line arguments
 * @param[in] argv command line arguments
 *
 * @return EXIT_SUCCESS when programs executes correctly, EXIT_FAILURE otherwise
 */
int main(int argc, char *argv[]) {
    char *filepath = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);

    /* create a table variable */
    WeatherTable table;

    /* parse the file to fill the table */
    table_from_file(table, filepath);

    /* show the table in the screen */
    table_dump(table);

//salida por main

    // Ejercicio 1: Menor temperatura mínima histórica
    int min_historica = historic_min_temp(table);
    printf("Menor temperatura mínima histórica: %d\n\n", min_historica);

    // Ejercicio 2: Mayores máximas anuales
    int max_temps[YEARS];
    yearly_max_temp(table, max_temps);

    // Ejercicio 3: Meses de máxima lluvia
    month_t max_rain_months[YEARS];
    monthly_most_precipitations(table, max_rain_months);

    printf("Año\tMáx Temp\tMes Máx Lluvia\n");
    printf("--------------------------------------\n");
    
    for (unsigned int i = 0; i < YEARS; i++) {
        unsigned int year = i + 1980; // Los datos van de 1980 a 2016
        
        /* Importante: El enum month_t empieza en 0 (january). 
           Para que enero se vea como "1" en la salida, sumamos 1. 
        */
        
       printf("%u\t%d\t\t%d\n", year, max_temps[i], max_rain_months[i] + 1);
    }

    return EXIT_SUCCESS;
}
