/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 18:59:18 by cmelara-          #+#    #+#             */
/*   Updated: 2019/01/29 13:07:42 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

SDL_Surface	*load_image(t_engine *engine, char *path)
{
	SDL_Surface	*loaded;
	SDL_Surface	*optimized;

	IMG_Init(IMG_INIT_PNG);
	loaded = IMG_Load(path);
	optimized = NULL;
	if (loaded)
		optimized = SDL_ConvertSurface(loaded, engine->surface->format, 0);
	SDL_FreeSurface(loaded);
	return (optimized);
}

int			free_engine(t_engine *engine)
{
	system("killall -STOP afplay");
	SDL_FreeSurface(engine->gun);
	SDL_FreeSurface(engine->map->texture);
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
							WINDOW_WIDTH, WINDOW_HEIGHT,
							SDL_WINDOW_OPENGL)) ||
			!(engine->map = ft_memalloc(sizeof(t_map))))
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
