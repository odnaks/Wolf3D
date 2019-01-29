/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 20:20:39 by cmelara-          #+#    #+#             */
/*   Updated: 2019/01/29 14:11:28 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	render_background(t_engine *engine)
{
	SDL_Rect	rect;

	rect.w = WINDOW_WIDTH;
	rect.h = WINDOW_HEIGHT / 2;
	rect.x = 0;
	rect.y = 0;
	SDL_FillRect(engine->surface, &rect, 0x587399);
	rect.y = WINDOW_HEIGHT / 2;
	SDL_FillRect(engine->surface, &rect, 0x2c2c2c);
}

void	render_walls(t_engine *engine)
{
	int		x;
	t_col	column;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		raycast(engine, engine->player, x);
		engine->ray->wall_height = (int)(WINDOW_HEIGHT
									/ engine->ray->wall_dist);
		column.start = (int)(WINDOW_HEIGHT / 2 - engine->ray->wall_height / 2);
		column.start = (column.start < 0) ? 0 : column.start;
		column.end = (int)(WINDOW_HEIGHT / 2 + engine->ray->wall_height / 2);
		column.end = (column.end >= WINDOW_HEIGHT)
									? WINDOW_HEIGHT - 1 : column.end;
		draw_column(engine, x, column, engine->ray);
		x++;
	}
}

void	render_hud(t_engine *engine)
{
	SDL_Rect rect;

	rect.w = 512;
	rect.h = 512;
	rect.x = (int)(WINDOW_WIDTH / 2) - rect.w / 2;
	rect.y = WINDOW_HEIGHT - rect.h;
	SDL_BlitScaled(engine->gun, NULL, engine->surface, &rect);
}

void	render(t_engine *engine)
{
	render_background(engine);
	render_walls(engine);
	render_hud(engine);
	update_screen(engine);
}
