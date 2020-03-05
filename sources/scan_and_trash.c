/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_and_trash.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpernia- <mpernia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 09:09:34 by mpernia-          #+#    #+#             */
/*   Updated: 2020/02/27 06:03:58 by mpernia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include_file.h"

void useless(library *l) // Anula librerias por falta de días
{
    l->scanned = true;
    l->score = 0;
    l->sum_score = 0;
}

char	*scan(file *f, int i) // Archivo que crea los datos de cada libreria
{
	char *ret;
	char *aux;
	int k;
	float books_to_output;

	ret = ft_strdup("");
	k = 0;
	f->days_remaining -= f->info_libraries[i].ndays;
	books_to_output = f->info_libraries[i].books_day * f->days_remaining;
	books_to_output = (books_to_output > f->info_libraries[i].nbooks_available
					? f->info_libraries[i].nbooks_available : books_to_output);
	aux = ft_strjoin(ret, ft_itoa(f->info_libraries[i].lib_id));
	free(ret);
	ret = aux;
	aux = ft_strjoin(ret, " ");
	free(ret);
	ret = aux;
	aux = ft_strjoin(ret, ft_itoa(books_to_output));
	free(ret);
	ret = aux;
	aux = ft_strjoin(ret, "\n");
	free(ret);
	ret = aux;
	for(int l = 0; l < books_to_output; l++)
	{
		k = 0;
		for(int j = 0; j < f->info_libraries[i].nbooks; j++)
		{
			if (f->info_libraries[i].books_types[j] != -1 &&
						f->indiv_books[f->info_libraries[i].books_types[j]] >
							f->indiv_books[f->info_libraries[i].books_types[k]])
				k = j;
		}
		aux = ft_strjoin(ret, ft_itoa(f->info_libraries[i].books_types[k]));
		free(ret);
		ret = aux;
		aux = ft_strjoin(ret, " ");
		free(ret);
		ret = aux;
		f->indiv_books[f->info_libraries[i].books_types[k]] = 0;
	}
	aux = ft_strjoin(ret, "\n");
	free(ret);
	ret = aux;
	return (ret);
}
