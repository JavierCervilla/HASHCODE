/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcervill <jcervill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 04:18:53 by mpernia-          #+#    #+#             */
/*   Updated: 2020/02/25 05:23:27 by jcervill         ###   ########.fr       */
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

