/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 21:46:59 by cmelara-          #+#    #+#             */
/*   Updated: 2019/01/29 14:11:33 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_column(t_engine *engine, int x, t_col y_column, t_ray *ray)
{
	SDL_Rect	tex_rect;
	SDL_Rect	win_rect;
	int			top_offset;

	top_offset = (int)((1.0f - (y_column.end - y_column.start)
						/ (double)ray->wall_height) * (double)TEX_H);
	tex_rect.w = 1;
	tex_rect.h = TEX_H - top_offset;
	tex_rect.x = TEX_W * (ray->wall_id - 1) + ray->tex_x;
	if (engine->map->side == 0)
		tex_rect.x = TEX_W * (ray->wall_id - 2) + ray->tex_x;
	tex_rect.y = top_offset - top_offset / 2;
	win_rect.w = 1;
	win_rect.h = y_column.end - y_column.start;
	win_rect.x = x;
	win_rect.y = y_column.start;
	SDL_BlitScaled(engine->map->texture, &tex_rect, engine->surface, &win_rect);
}
