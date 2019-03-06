/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 17:49:27 by cmelara-          #+#    #+#             */
/*   Updated: 2019/01/29 12:47:33 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	load_resources(t_engine *engine)
{
	engine->gun = load_image(engine, "resources/gun0.png");
	engine->map->texture = load_image(engine, "resources/walls.png");
}

int		main(void)
{
	t_engine *engine;

	if (!(engine = initialize("Maze")))
		return (0);
	load_resources(engine);
	render(engine);
	game_loop(engine);
	free_engine(engine);
	return (0);
}
