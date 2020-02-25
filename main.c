#include "includes/include_file.h"

file initialize(void)
{
    file f;
    f.books = 0;
    f.libraries = 0;
    f.days = 0;
    f.indiv_books = NULL;
    f.info_libraries->nbooks = 0;
    f.info_libraries->ndays = 0;
    f.info_libraries->books_day = 0.0;
    f.info_libraries->books_types = NULL;
    f.info_libraries->score = 0.0;
    f.info_libraries->sum_score = 0;
    f.info_libraries->days_to_scan = 0.0;
    return (f);
}

void read_library(FILE *fd, library *l)
{
    fscanf(fd, "%d %d %f\n", &l->nbooks, &l->ndays, &l->books_day);
    l->books_types = malloc(sizeof(int) * l->nbooks);
    for (int i = 0; i < l->nbooks; i++)
        fscanf(fd, "%d", &l->books_types[i]);
    fscanf(fd, "\n");
}

int read_file(char *file_name, file *f)
{
    FILE *fd;
    if (!(fd = fopen(file_name, "r")))
        return (-1);
    else
    {
        fscanf(fd, "%d %d %d", &f->books, &f->libraries, &f->days);
        f->indiv_books = malloc(sizeof(int) * f->books);
        for (int i = 0; i < f->books; i++)
            fscanf(fd, "%d", &f->indiv_books[i]);
        fscanf(fd, "\n");
        int i;
        f->info_libraries = malloc(f->libraries * sizeof(library));
        for (i = 0; i < f->libraries; i++)
        {

            read_library(fd, &f->info_libraries[i]);
        }
    }
    return (0);
}

int main (int argc, char *argv[])
{
    file f;
    argc++;
    int i = 0;
    int j = 0;
    bzero(&f, sizeof(file));
    read_file(argv[1], &f);
    calculate_scores(&f);
    calculate_day2scan(&f);
    score_calculation(&f);
    while (i < f.libraries)
    {
        printf("libreria: %d numero de libros: %d\n", i, f.info_libraries[i].nbooks);
        while (j < f.info_libraries[i].nbooks)
        {
            printf("libreria: %d id_libros:%d puntuacion del libro: %d\n", i, f.info_libraries[i].books_types[j], f.indiv_books[f.info_libraries[i].books_types[j]]);
            
            j++;
        }
        j = 0;
        printf("libreria:%d numero de dias: %d\n", i, f.info_libraries[i].ndays);
        printf("libreria:%d libros/dia: %f\n", i, f.info_libraries[i].books_day);
        printf("libreria:%d score: %f\n", i, f.info_libraries[i].score);
        printf("libreria:%d sum_scores: %d\n", i, f.info_libraries[i].sum_score);
        printf("libreria:%d days2scan: %f\n", i, f.info_libraries[i].days_to_scan);
        i++;
    }
    return (0);
}
