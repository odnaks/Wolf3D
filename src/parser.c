/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 22:55:54 by cmelara-          #+#    #+#             */
/*   Updated: 2019/01/29 13:12:11 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	music(char *a)
{
	static int flag = 0;

	if (!ft_strcmp(a, "maps/level0"))
	{
		if (flag)
			system("killall -STOP afplay");
		flag = 1;
		system("afplay ./music/0.mp3 &");
	}
	if (!ft_strcmp(a, "maps/level1"))
	{
		system("killall -STOP afplay");
		system("afplay ./music/1.mp3 &");
	}
	if (!ft_strcmp(a, "maps/level2"))
	{
		system("killall -STOP afplay");
		system("afplay ./music/2.mp3 &");
	}
	if (!ft_strcmp(a, "maps/level3"))
	{
		system("killall -STOP afplay");
		system("afplay ./music/3.mp3 &");
	}
}

void	pos_player(t_engine *wo)
{
	wo->player->x = 2.0f;
	wo->player->y = 2.0f;
}

void	parser(t_engine *wo, char *a)
{
	int		fd;
	char	*line;
	int		i;
	int		j;

	fd = open(a, O_RDONLY);
	get_next_line(fd, &line);
	wo->map->map_width = ft_atoi(&line[0]);
	wo->map->map_height = ft_atoi(&line[2]);
	wo->map->map = ft_memalloc(sizeof(int*) * (wo->map->map_height + 1));
	i = 0;
	while (i < wo->map->map_height)
	{
		get_next_line(fd, &line);
		wo->map->map[i] = malloc(sizeof(int) * wo->map->map_width);
		j = 0;
		while (j < wo->map->map_width)
		{
			wo->map->map[i][j] = ft_atoi(&line[j * 2]);
			j++;
		}
		i++;
	}
	pos_player(wo);
	music(a);
}
