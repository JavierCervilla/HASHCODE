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

typedef struct  s_library {

    int         nbooks;             // número libros en una librería
    int         nbooks_available;   // número de libros que dan puntuación
    int         ndays;              // número de días para registrarse
    int         *books_types;       // tipos de libros de la librería
    int         sum_score;          // puntuacion de libros
    float       books_day;          // número de libros que puedes enviar por día
    float       days_to_scan;       // días
    float       score;              // ratio de importancia

} library;

typedef struct s_file {

    int         books;              // número de libros máximo
    int         libraries;          // número de librerías
    int         days;               // número máx de días para escanear
    int         *indiv_books;       // id de los diferentes libros disponibles
    library     *info_libraries;    // info de las diferentes librerías
    int         *scanned;           // libros escaneados
}               file;

void            calculate_scores(file *f);
void            calculate_day2scan(file *f);
void            score_calculation(file *f);
void            ft_sort_tab(file *f);
void            check_books(file *f);

#endif
