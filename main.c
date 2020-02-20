#include "include_file.h"

void initialize(file f)
{
    f.books = 0;
    f.libraries = 0;
    f.days = 0;
    f.indiv_books = NULL;
    f.info_libraries->nbooks = 0;
    f.info_libraries->ndays = 0;
    f.info_libraries->books_day = 0;
    f.info_libraries->books_types = NULL;
    f.info_libraries->score = 0.0;
}

char *swap(char *s1, char *s2)
{
    char *aux = ft_strjoin(s1, s2);
    free(s1);
    s1 = strdup(aux);
    free(aux);
    return (s1);
}

void read_library(FILE *fd, library lib)
{
    fscanf(fd, "%d %d %d", &lib.nbooks, &lib.ndays, &lib.books_day);
    char *aux = strdup("%d ");
    for (int i = 0; i < lib.nbooks; i++)
        aux = swap(aux, aux);
    fscanf(fd, aux, lib.books_types);
}

void read_file(char *file_name, file f)
{
    FILE *fd;
    if (!(fd = fopen(file_name, "r")))
        return (-1);
    else
    {
        fscanf(fd, "%d %d %d ", &f.books, &f.libraries, &f.days);
        char *aux = strdup("%d ");
        for (int i = 0; i < f.books; i++)
            aux = swap(aux, aux);
        fscanf(fd, aux, f.indiv_books);
        // fin de array ??
        int i;
        for (i = 0; i < f.libraries; i++)
            f.info_libraries[i] = read_library(fd, f.info_libraries);
        f.info_libraries[i] = NULL;
    }
}

int main (int argc, char *argv[])
{
    file *f;
    initialize(&f);

    read_file(argv[1], &f);

    return (0);
}
