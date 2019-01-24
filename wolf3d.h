/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 17:46:30 by cmelara-          #+#    #+#             */
/*   Updated: 2019/01/24 21:59:10 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define WINDOW_WIDTH	1280
# define WINDOW_HEIGHT	720

# define VIEW_MAX		100

# include <math.h>
# include <fcntl.h>
# include "SDL2/SDL.h"
# include "../libft/libft.h"

typedef struct	s_col
{
	int			start;
	int			end;
}				t_col;

typedef struct	s_vec2
{
	double		x;
	double		y;
}				t_vec2;

typedef struct	s_map
{
	int			**map;
	int		mapWidth;
	int		mapHeight;
}				t_map;

typedef struct	s_ray
{
	double		x;
	double		y;
	double		sx;
	double		sy;
	double		dx;
	double		dy;
	double		wall_dist;
	t_map		*map;
}				t_ray;

typedef struct	s_cast
{
	int			mapx;
	int			mapy;
	int			nextx;
	int			nexty;
	int			side;
}				t_cast;

typedef struct	s_mouse
{
	int			x;
	int			y;
	int			prev_x;
	int			prev_y;
}				t_mouse;

typedef struct	s_player
{
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}				t_player;

typedef struct	s_engine
{
	SDL_Window	*window;
	SDL_Surface	*surface;
	t_player	*player;
	t_map		*map;
	t_mouse		*mouse;
	int			quit;
}				t_engine;

void			render(t_engine *engine);

t_engine		*initialize(char *title);
void			init_engine(t_engine *engine);
int				free_engine(t_engine *engine);

void			put_pixel(t_engine *engine, int x, int y, Uint32 color);
void			clear_screen(t_engine *engine, Uint32 color);
void			update_screen(t_engine *engine);

void			game_loop(t_engine *engine);
double			raycast(t_engine *engine, t_player *player, int x,
						Uint32 *color);

void			set_map_color(t_engine *engine, Uint32 *color, int block);

void			draw_column(t_engine *engine, int x, t_col y_col, Uint32 color);

void			benchmark(t_engine *engine);

void			parser(t_map *wo, char *a);

#endif
