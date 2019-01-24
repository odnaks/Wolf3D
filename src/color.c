/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 21:38:09 by cmelara-          #+#    #+#             */
/*   Updated: 2019/01/23 21:50:09 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	set_map_color(t_engine *engine, Uint32 *color, int block)
{
	if (block == 1)
		*color = SDL_MapRGBA(engine->surface->format, 153, 97, 45, 255);
	if (block == 2)
		*color = SDL_MapRGBA(engine->surface->format, 153, 63, 45, 255);
	else
		*color = SDL_MapRGBA(engine->surface->format, 193, 153, 145, 255);
}
