/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 21:38:25 by cmelara-          #+#    #+#             */
/*   Updated: 2019/01/29 12:19:18 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	move_towards(t_engine *engine, int i)
{
	int		mapx;
	int		mapy;
	double	mspd;

	mspd = engine->frame_time * 10.0f;
	mapx = (int)(engine->player->x + engine->player->dir_x * mspd);
	mapy = (int)(engine->player->y + engine->player->dir_y * mspd);
	if (!engine->map->map[mapx][(int)(engine->player->y)])
		engine->player->x += i * engine->player->dir_x * mspd;
	if (!engine->map->map[(int)(engine->player->x)][mapy])
		engine->player->y += i * engine->player->dir_y * mspd;
}

void	move_side(t_engine *engine, int i)
{
	int		mapx;
	int		mapy;
	double	mspd;

	mspd = engine->frame_time * 10.0f;
	mapx = (int)(engine->player->x + engine->player->dir_x * mspd);
	mapy = (int)(engine->player->y + engine->player->dir_y * mspd);
	if (!engine->map->map[mapx][(int)(engine->player->y)])
		engine->player->x += i * engine->player->plane_x * mspd;
	if (!engine->map->map[(int)(engine->player->x)][mapy])
		engine->player->y += i * engine->player->plane_y * mspd;
}
