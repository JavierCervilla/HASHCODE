/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcervill <jcervill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 03:01:49 by jcervill          #+#    #+#             */
/*   Updated: 2020/02/25 03:55:57 by jcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include_file.h"

void calculate_scores(file *f)
{
    int i = 0;
    int j = 0;
    f->info_libraries[i].sum_score = 0;
    while (i < f->libraries)
    {
        f->info_libraries[i].days_to_scan = ((f->info_libraries[i].nbooks / f->info_libraries[i].books_day) + f->info_libraries[i].ndays);
        //printf("sum_score: %d\n", f->info_libraries[i].sum_score);
        while (j < f->info_libraries[i].nbooks)
        {
            f->info_libraries[i].sum_score = f->info_libraries[i].sum_score + (f->indiv_books[f->info_libraries[i].books_types[j]]);
            printf("book_types: %d\n", f->indiv_books[f->info_libraries[i].books_types[j]]);
            printf("sum_score: %d\n", f->info_libraries[i].sum_score);
            j++;
        }
        j = 0;
        i++;
    }
}