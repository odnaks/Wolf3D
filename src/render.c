/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 20:20:39 by cmelara-          #+#    #+#             */
/*   Updated: 2019/01/25 22:18:52 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	render_background(t_engine *engine)
{
	int x;
	int y;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			if (y < WINDOW_HEIGHT / 2)
				put_pixel(engine, x, y, 0xB0AEAE);
			else
				put_pixel(engine, x, y, 0x696969);
			x++;
		}
		y++;
	}
}

void	text_calc(int lineHeight, double perpWallDist, t_engine *engine)
{
	engine->text->lineHeight = lineHeight;
	engine->text->perpWallDist = perpWallDist;

	if (engine->text->side == 0)
		engine->text->wallX = engine->text->posY + engine->text->perpWallDist * engine->text->rayDirY;
	else
		engine->text->wallX = engine->text->posX + engine->text->perpWallDist * engine->text->rayDirX;
	engine->text->wallX -= (floor)(engine->text->wallX);
	engine->text->texX = (int)(engine->text->wallX * (double)64);
	if (engine->text->side == 0 && engine->text->rayDirX > 0)
		engine->text->texX = 64 - engine->text->texX - 1;
	if (engine->text->side == 1 && engine->text->rayDirY < 0)
		engine->text->texX = 64 - engine->text->texX - 1;
}

void	render(t_engine *engine)
{
	int		x;
	double	wall_dist;
	int		line_height;
	Uint32	color = 0;
	t_col	col;

	clear_screen(engine, 0x000000);
	render_background(engine);
	init_texture(engine);
	x = 0;
	while (x < WINDOW_WIDTH)
	{
		wall_dist = raycast(engine, engine->player, x, &color);
		line_height = (int)(WINDOW_HEIGHT / wall_dist);
		col.start = (int)(WINDOW_HEIGHT / 2 - line_height / 2);
		col.start = (col.start < 0) ? 0 : col.start;
		col.end = (int)(WINDOW_HEIGHT / 2 + line_height / 2);
		col.end = (col.end >= WINDOW_HEIGHT) ? WINDOW_HEIGHT - 1 : col.end;
		text_calc(line_height, wall_dist, engine);
		draw_column(engine, x, col, color);
		x++;
	}
	update_screen(engine);
}
