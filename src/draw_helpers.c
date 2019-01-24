/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 21:46:59 by cmelara-          #+#    #+#             */
/*   Updated: 2019/01/23 18:56:23 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_column(t_engine *engine, int x, t_col y_col, Uint32 color)
{
	int i;

	i = y_col.start;
	while (i < y_col.end)
	{
		put_pixel(engine, x, i, color);
		i++;
	}
}
