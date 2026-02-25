/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_ft_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plima <plima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/26 12:43:32 by plima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fdf.h"
#include "load_map_internal.h"

char	**try_ft_split(char *line, t_app *app)
{
	char	**columns;

	columns = ft_split(line, ' ');
	if (!columns)
	{
		free(line);
		destroy_app(app, EXIT_FAILURE);
	}
	return (columns);
}
