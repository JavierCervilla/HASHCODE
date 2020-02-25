/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcervill <jcervill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 04:18:53 by mpernia-          #+#    #+#             */
/*   Updated: 2020/02/25 05:46:33 by jcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include_file.h"

void	score_calculation(file *f) // Calculate score
{
	for(int i = 0; i < f->libraries; i++)
	{
		f->info_libraries[i].score = f->info_libraries[i].sum_score /
											f->info_libraries[i].days_to_scan;
	}
}

void	check_books(file *f)
{
	int i = 0;
	int j = 0;
	
	while (f->info_libraries[i].nbooks)
	{
		while (f->info_libraries[i].books_types[j])
		{
			if (f->info_libraries[i].books_types[j] == f->info_libraries[i].books_types[j + 1])
			{
				f->info_libraries[i].books_types[j + 1] = -1;
				f->info_libraries[i].nbooks_available--;
				j++;
			}
		}
		i++;
	}
}