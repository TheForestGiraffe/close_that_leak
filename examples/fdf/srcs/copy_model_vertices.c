/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_model_vertices.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecavalc <pecavalc@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:02:15 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/25 14:07:45 by pecavalc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	copy_model_vertices(t_model *src, t_model *dst)
{
	int	i;
	int	j;

	j = 0;
	while (j < src->rows)
	{
		i = 0;
		while (i < src->columns)
		{
			dst->vertices[j][i] = src->vertices[j][i];
			i++;
		}
		j++;
	}
}
