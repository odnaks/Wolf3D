/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:15:03 by drestles          #+#    #+#             */
/*   Updated: 2019/01/24 22:11:20 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	parser(t_map *wo, char *a)
{
	int		fd;
	char	*line;
	int		i;
	int		j;

	fd = open(a, O_RDONLY);
	get_next_line(fd, &line);
	wo->mapWidth = ft_atoi(&line[0]);
	wo->mapHeight = ft_atoi(&line[2]);
	wo->map = ft_memalloc(sizeof(int*) * (wo->mapHeight + 1));
	i = 0;
	while (i < wo->mapHeight)
	{
		get_next_line(fd, &line);
		wo->map[i] = malloc(sizeof(int) * wo->mapWidth);
		j = 0;
		while (j < wo->mapWidth)
		{
			wo->map[i][j] = ft_atoi(&line[j * 2]);
			j++;
		}
		i++;
	}
}
