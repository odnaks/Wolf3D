/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 21:27:55 by cmelara-          #+#    #+#             */
/*   Updated: 2019/01/28 18:51:46 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		set_player(t_engine *engine)
{
	if (!(engine->player = ft_memalloc(sizeof(t_player))))
		return (free_engine(engine));
	engine->player->x = 2.0f;
	engine->player->y = 2.0f;
	engine->player->dir_x = -1.0f;
	engine->player->dir_y = 0.0f;
	engine->player->plane_x = 0.0f;
	engine->player->plane_y = 0.66f;
	return (0);
}

void	init_engine(t_engine *engine)
{
	engine->quit = 0;
	set_player(engine);
	parser(engine, "maps/level0");
	engine->mouse->x = 0;
	engine->mouse->y = 0;
	SDL_ShowCursor(SDL_DISABLE);
}
