/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:15:03 by drestles          #+#    #+#             */
/*   Updated: 2019/01/28 18:55:10 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	parser(t_engine *wo, char *a)
{
	int		fd;
	char	*line;
	int		i;
	int		j;

	fd = open(a, O_RDONLY);
	get_next_line(fd, &line);
	wo->map->mapWidth = ft_atoi(&line[0]);
	wo->map->mapHeight = ft_atoi(&line[2]);
	wo->map->map = ft_memalloc(sizeof(int*) * (wo->map->mapHeight + 1));
	i = 0;
	while (i < wo->map->mapHeight)
	{
		get_next_line(fd, &line);
		wo->map->map[i] = malloc(sizeof(int) * wo->map->mapWidth);
		j = 0;
		while (j < wo->map->mapWidth)
		{
			wo->map->map[i][j] = ft_atoi(&line[j * 2]);
			j++;
		}
		i++;
	}
	wo->player->x = 2.0f;
	wo->player->y = 2.0f;
}
