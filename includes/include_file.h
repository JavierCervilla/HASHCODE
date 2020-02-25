#ifndef INCLUDE_FILE_H
#define INCLUDE_FILE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <string.h>
#include "libft/libft.h"
#include <math.h>
#include <stdbool.h>

typedef struct  s_library {
    int         lib_id;             // id de la libreria
    int         nbooks;             // número libros en una librería
    int         nbooks_available;   // número de libros que dan puntuación
    int         ndays;              // número de días para registrarse
    int         *books_types;       // tipos de libros de la librería
    int         sum_score;          // puntuacion de libros
    float       books_day;          // número de libros que puedes enviar por día
    float       days_to_scan;       // días totales de escaneo
    float       score;              // ratio de importancia
    bool        scanned;            // utilidad / escaneada.
} library;

typedef struct s_file {

    int         books;              // número de libros máximo
    int         libraries;          // número de librerías
    int         days;               // número máx de días para escanear
    int         *indiv_books;       // id de los diferentes libros disponibles
    float       days_remaining;     // días que quedan
    char        *output_char;       // string con salida
    library     *info_libraries;    // info de las diferentes librerías
}               file;

void            calculate_scores(file *f);
void            calculate_day2scan(file *f);
void            score_calculation(file *f);
void            ft_sort_tab(file *f);
void            check_books(file *f);
void            ft_sort_int_tab(int *tab, int size);
char	        *scan(file *f, int i);

#endif
