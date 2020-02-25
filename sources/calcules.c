/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcervill <jcervill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 03:01:49 by jcervill          #+#    #+#             */
/*   Updated: 2020/02/25 04:27:07 by jcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include_file.h"

void calculate_scores(file *f)                  // calcula el sumatorio de la puntuacion de la libreria 
{
    int i = 0;
    int j = 0;
    while (i < f->libraries)
    {
        f->info_libraries[i].sum_score = 0;
        f->info_libraries[i].days_to_scan = ((f->info_libraries[i].nbooks / f->info_libraries[i].books_day) + f->info_libraries[i].ndays);
        while (j < f->info_libraries[i].nbooks)
            f->info_libraries[i].sum_score = f->info_libraries[i].sum_score + (f->indiv_books[f->info_libraries[i].books_types[j++]]);
        j = 0;
        i++;
    }
}

void calculate_day2scan(file *f)
{
    int i = 0;
    float ratio = 0.0;
    while (i < f->libraries)
    {
        ratio = (f->info_libraries[i].nbooks / f->info_libraries[i].books_day);
        f->info_libraries[i].days_to_scan = f->info_libraries[i].ndays + ratio;
        i++;
    }
}