/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_open.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plima <plima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:55:39 by pecavalc          #+#    #+#             */
/*   Updated: 2025/09/26 12:47:41 by plima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "fdf.h"

int	try_open(char *filepath, t_app *app)
{
	int	fd;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
	{
		perror("try_open failed.");
		destroy_app(app, EXIT_FAILURE);
	}
	return (fd);
}
