/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 18:59:18 by cmelara-          #+#    #+#             */
/*   Updated: 2019/01/26 21:35:11 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

#include <stdio.h>

int			free_engine(t_engine *engine)
{
	system("killall afplay");
	SDL_DestroyWindow(engine->window);
	SDL_Quit();
	return (0);
}

t_engine	*initialize(char *title)
{
	t_engine *engine;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		ft_putendl("SDL couldn't be able to initialize!");
		return (NULL);
	}
	else
	{
		if (!(engine = ft_memalloc(sizeof(t_engine))) ||
			!(engine->mouse = ft_memalloc(sizeof(t_mouse))) ||
			!(engine->window = SDL_CreateWindow(title,
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
							WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN)) ||
							!(engine->map = ft_memalloc(sizeof(t_map))) ||
							!(engine->text = ft_memalloc(sizeof(t_text))))
		{
			ft_putendl(SDL_GetError());
			return (NULL);
		}
		else
			engine->surface = SDL_GetWindowSurface(engine->window);
	}
	init_engine(engine);
	return (engine);
}
