/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcervill <jcervill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 04:18:53 by mpernia-          #+#    #+#             */
/*   Updated: 2020/02/25 09:00:07 by jcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include_file.h"

void score_calculation(file *f) // Calculate score
{
	for (int i = 0; i < f->libraries; i++)
	{
		f->info_libraries[i].score = f->info_libraries[i].sum_score /
											 f->info_libraries[i].days_to_scan;
	}
}

void check_books(file *f)
{
	int i = 0;
	int j;
	int k;

	while (i < f->libraries)
	{
		j = 0;
		while (j < f->info_libraries[i].nbooks && f->info_libraries[i].books_types[j] >= 0)
		{
			k = j + 1;
			while (k < f->info_libraries[i].nbooks && f->info_libraries[i].books_types[k] >= 0)
			{
				if (f->indiv_books[f->info_libraries[i].books_types[k]] == 0 ||
	f->info_libraries[i].books_types[j] == f->info_libraries[i].books_types[k])
				{
					f->info_libraries[i].books_types[k] = -1;
					f->info_libraries[i].nbooks_available--;
				}
				k++;
			}
			j++;
		}
		i++;
	}
}
