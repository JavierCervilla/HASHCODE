#ifndef INCLUDE_FILE_H
#define INCLUDE_FILE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdarg.h>

typedef struct s_library {

    int nbooks;         // número libros en una librería
    int ndays;          // número de días para registrarse
    int books_day;      // número de libros que puedes enviar por día
    int *books_types;   // tipos de libros de la librería
    float score;        // ratio de importancia

} library;

typedef struct s_file {

    int books;          // número de libros máximo
    int libraries;      // número de librerías
    int days;           // número máx de días para escanear
    int *indiv_books;   // id de los diferentes libros disponibles
    library *info_libraries;    // info de las diferentes librerías

} file;

#endif