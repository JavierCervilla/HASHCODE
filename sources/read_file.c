/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <mpernia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 04:18:53 by mpernia-          #+#    #+#             */
/*   Updated: 2020/02/27 04:35:11 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include_file.h"

static void read_library(FILE *fd, library *l, int i)
{
    fscanf(fd, "%d %d %d\n", &l->nbooks, &l->ndays, &l->books_day);
    l->nbooks_available = l->nbooks;
    l->books_types = malloc(sizeof(int) * l->nbooks);
    for (int i = 0; i < l->nbooks; i++)
        fscanf(fd, "%d", &l->books_types[i]);
    fscanf(fd, "\n");
    l->scanned = false;
    l->lib_id = i;
}

int read_file(char *file_name, file *f)
{
    int i = 0;
    FILE *fd;
    if (!(fd = fopen(file_name, "r")))
        return (-1);
    else
    {
        fscanf(fd, "%d %d %d", &f->books, &f->libraries, &f->days);
        f->days_remaining = f->days;
        f->indiv_books = malloc(sizeof(int) * f->books);
        while (f->indiv_books[i])
        {
            f->indiv_books[i] = 0;
            i++;
        }
        for (int i = 0; i < f->books; i++)
            fscanf(fd, "%d", &f->indiv_books[i]);
        fscanf(fd, "\n");
        int i;
        f->info_libraries = ft_calloc(f->libraries , sizeof(library));
        for (i = 0; i < f->libraries; i++)
            read_library(fd, &f->info_libraries[i], i);
    }
    return (0);
}
