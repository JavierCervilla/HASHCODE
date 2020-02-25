/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcervill <jcervill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 03:01:49 by jcervill          #+#    #+#             */
/*   Updated: 2020/02/26 00:23:58 by jcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include_file.h"

void calculate_scores(file *f)      // Sumatoria de la puntuacion de la libreria
{
    int i = 0;
    int j = 0;

    while (i < f->libraries)
    {
        f->info_libraries[i].sum_score = 0;
        while (j < f->info_libraries[i].nbooks)
        {
            if (f->info_libraries[i].books_types[j] != -1)
                f->info_libraries[i].sum_score = f->info_libraries[i].sum_score
                    + (f->indiv_books[f->info_libraries[i].books_types[j]]);
            j++;
        }
        j = 0;
        i++;
    }
}

void calculate_day2scan(file *f)    // Días que toma escanear sus libros
{
    int i = 0;
    int ratio = 0;
    while (i < f->libraries)
    {
        ratio = (f->info_libraries[i].nbooks_available / f->info_libraries[i].books_day);
        f->info_libraries[i].days_to_scan = f->info_libraries[i].ndays + ratio;
        if (f->info_libraries[i].nbooks_available % f->info_libraries[i].books_day >= 5)
            f->info_libraries[i].days_to_scan++;
        i++;
    }
}

void	ft_sort_tab(file *f)        // Ordena librerias por score
{
    library swap;
	for(int i = 0; i < f->libraries - 1; i++)
    {
        for(int j = 0; j < f->libraries - i - 1; j++)
        {
            if (f->info_libraries[j].score < f->info_libraries[j + 1].score)
            {
                swap = f->info_libraries[j];
                f->info_libraries[j] = f->info_libraries[j + 1];
                f->info_libraries[j + 1] = swap;
            }
        }
    }
}

void	ft_sort_int_tab(int *tab, int size)
{
	int swap;
	int csw;
	int counter;

	size--;
	csw = 1;
	while (csw != 0)
	{
		counter = 0;
		csw = 0;
		while (size > counter)
		{
			if (tab[counter] > tab[counter + 1])
			{
				swap = tab[counter];
				tab[counter] = tab[counter + 1];
				tab[counter + 1] = swap;
				csw++;
			}
			counter++;
		}
	}
}
