/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcervill <jcervill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 03:01:49 by jcervill          #+#    #+#             */
/*   Updated: 2020/02/25 05:13:14 by jcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include_file.h"

void calculate_scores(file *f)                  // calcula el sumatorio de la puntuacion de la libreria
{
    int i = 0;
    int j = 0;
    
    while (i < f->libraries)
    {
        while (j < f->info_libraries[i].nbooks)
            f->info_libraries[i].sum_score = f->info_libraries[i].sum_score + (f->indiv_books[f->info_libraries[i].books_types[j++]]);
        j = 0;
        i++;
    }
}

void calculate_day2scan(file *f)            //Calcula los días que le toma escanera sus libros
{
    int i = 0;
    float ratio = 0.0;
    while (i < f->libraries)
    {
        ratio = (f->info_libraries[i].nbooks_available / f->info_libraries[i].books_day);
        f->info_libraries[i].days_to_scan = f->info_libraries[i].ndays + ratio;
        i++;
    }
}

void	ft_sort_tab(file *f)
{
	library swap;
	int i = 0;
    int j = 1;
    while (j <  f->libraries)
    {
       if (f->info_libraries[j].score > f->info_libraries[i].score)
       {
           swap = f->info_libraries[j];
           f->info_libraries[j] = f->info_libraries[i];
           f->info_libraries[i] = swap;
       }
       i++;
       j++;
    }
}