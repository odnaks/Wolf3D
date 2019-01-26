/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 21:46:59 by cmelara-          #+#    #+#             */
/*   Updated: 2019/01/26 22:04:54 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

#include <stdio.h>
/* void	draw_column(t_engine *engine, int x, t_col y_col, Uint32 color)
{
	int i;

	i = y_col.start;
	while (i < y_col.end)
	{
		put_pixel(engine, x, i, color);
		i++;
	}
} */

void	draw_column(t_engine *engine, int x, t_col y_col, Uint32 color)
{
	int i;
	int	d;
	int texY;

	i = y_col.start;
	//printf("%d %d\n", engine->text->posX, engine->text->posX);
	while (i < y_col.end)
	{
		d = i * 256 - 720 * 128 + engine->text->lineHeight * 128;
		texY = ((d * 64) / engine->text->lineHeight) / 256;
		color = engine->map->tex[64 * texY + engine->text->texX];
		if (engine->text->side == 1)
			color = color >> 1;
		put_pixel(engine, x, i, color);
		i++;
	}
}
