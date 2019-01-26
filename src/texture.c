/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 20:15:10 by drestles          #+#    #+#             */
/*   Updated: 2019/01/26 22:22:46 by drestles         ###   ########.fr       */
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