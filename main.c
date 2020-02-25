#include "include_file.h"
#include <stdio.h>

file initialize(void)
{
    file f;
    f.books = 0;
    f.libraries = 0;
    f.days = 0;
    f.indiv_books = NULL;
    f.info_libraries->nbooks = 0;
    f.info_libraries->ndays = 0;
    f.info_libraries->books_day = 0;
    f.info_libraries->books_types = NULL;
    f.info_libraries->score = 0.0;
    return (f);
}

/*char *swap(char *s1, char *s2)
{
    char *aux = ft_strjoin(s1, s2);
    free(s1);
    s1 = strdup(aux);
    free(aux);
    return (s1);
}
*/
void read_library(FILE *fd, library *l)
{
    fscanf(fd, "%d %d %d\n", &l->nbooks, &l->ndays, &l->books_day);
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
    bzero(&f, sizeof(file));
    read_file(argv[1], &f);
    printf("%d\n", f.info_libraries[0].nbooks);
    printf("%d\n", f.info_libraries[999].books_types[793]);
    printf("%d\n", f.info_libraries[999].ndays);
    printf("%d\n", f.info_libraries[999].books_day);
    printf("%f", f.info_libraries[0].score);


    return (0);
}
