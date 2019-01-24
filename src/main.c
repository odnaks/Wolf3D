/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 17:49:27 by cmelara-          #+#    #+#             */
/*   Updated: 2019/01/24 22:22:04 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

int		main(void)
{
	t_engine *engine;

	if (!(engine = initialize("Maze")))
		return (0);
	render(engine);
	system("afplay ./bgm.mp3 &");
	game_loop(engine);
	free_engine(engine);
	return (0);
}
