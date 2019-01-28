/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 20:15:10 by drestles          #+#    #+#             */
/*   Updated: 2019/01/28 18:56:14 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/* void	init_texture(t_engine *en)
{
	int x;
	int y;

	x = 0;
	while (x < 64)
	{
		y = 0;
		while (y < 64)
		{
			en->map->tex[64 * y + x] = 65536 * 254 * (x != y && x != 64 - y);
			y++;
		}
		x++;
	}
} */


void	init_texture(t_engine *en)
{
	int x;
	int y;
	int	xorcolor;

	x = 0;
	while (x < 64)
	{
		y = 0;
		while (y < 64)
		{
			xorcolor = (x * 256 / 64) ^ (y * 256 / 64);
			en->map->tex[64 * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor;
			y++;
		}
		x++;
	}
}

/* void	init_texture(t_engine *en)
{
	int x;
	int y;
	int xycolor;

	x = 0;
	while (x < 64)
	{
		y = 0;
		while (y < 64)
		{
			xycolor = y * 128 / 64 + x * 128 / 64;
			en->map->tex[64 * y + x] = xycolor + 256 * xycolor + 65536 * xycolor;;
			y++;
		}
		x++;
	}
} */

/* void	init_texture(t_engine *en)
{
	int x;
	int y;

	x = 0;
	while (x < 64)
	{
		y = 0;
		while (y < 64)
		{
			en->map->tex[64 * y + x] = 65536 * 192 * (x% 16 && y% 16);
			y++;
		}
		x++;
	}
} */