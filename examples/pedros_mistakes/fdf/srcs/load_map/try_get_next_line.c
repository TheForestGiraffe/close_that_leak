/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_get_next_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plima <plima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/26 12:47:08 by plima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "load_map.h"
#include "fdf.h"

char	*try_get_next_line(int fd, t_app *app)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
	{
		perror("get_next_line: returned null.\n");
		destroy_app(app, EXIT_FAILURE);
	}
	return (line);
}
