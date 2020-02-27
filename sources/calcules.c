/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <mpernia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 03:01:49 by jcervill          #+#    #+#             */
/*   Updated: 2020/02/27 05:10:30 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include_file.h"

static void check_books(file *f) // Pasa por librerias anulando libros usados
{
	int i = 0;
	int j;
	int k;

	while (i < f->libraries)
	{
		j = 0;
		while (j < f->info_libraries[i].nbooks &&
									f->info_libraries[i].books_types[j] >= 0)
		{
			k = j + 1;
			while (k < f->info_libraries[i].nbooks &&
									f->info_libraries[i].books_types[k] >= 0)
			{
				if (f->indiv_books[f->info_libraries[i].books_types[k]] == 0 ||
	f->info_libraries[i].books_types[j] == f->info_libraries[i].books_types[k])
				{
					f->info_libraries[i].books_types[k] = -1;
					if (f->info_libraries[i].nbooks_available > 0)
                        f->info_libraries[i].nbooks_available--;
				}
				k++;
			}
			j++;
		}
		i++;
	}
}

static void calculate_day2scan(file *f)    // Días que toma escanear sus libros
{
    int i = 0;
    float ratio = 0;

    while (i < f->libraries)
    {
        ratio = (f->info_libraries[i].nbooks_available / f->info_libraries[i].books_day);
        f->info_libraries[i].days_to_scan = f->info_libraries[i].ndays + ratio;
        if (f->info_libraries[i].nbooks_available % f->info_libraries[i].books_day > 1)
            f->info_libraries[i].days_to_scan++;
        i++;
    }
}

static void calculate_sum(file *f)      // Sumatoria de la puntuacion de la libreria
{
    int i = 0;
    int j = 0;

    while (i < f->libraries)
    {
        f->info_libraries[i].sum_score = 0;
        while (j < f->info_libraries[i].nbooks)
        {
            if (f->info_libraries[i].books_types[j] > -1)
                f->info_libraries[i].sum_score = f->info_libraries[i].sum_score
                    + (f->indiv_books[f->info_libraries[i].books_types[j]]);
            j++;
        }
        j = 0;
        i++;
    }
}

static void score_calculation(file *f) // Calculate score
{
	for (int i = 0; i < f->libraries; i++)
	{
		f->info_libraries[i].score = f->info_libraries[i].sum_score /
											 f->info_libraries[i].days_to_scan;
	}
}

static void	ft_sort_tab(file *f)        // Ordena librerias por score
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

void calculate(file *f)
{
    check_books(f);
    calculate_day2scan(f);
    calculate_sum(f);
    score_calculation(f);
    ft_sort_tab(f);
}
