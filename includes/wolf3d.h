/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 17:46:30 by cmelara-          #+#    #+#             */
/*   Updated: 2019/01/29 13:27:20 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define WINDOW_WIDTH	1920
# define WINDOW_HEIGHT	1080

# define TEX_W			64
# define TEX_H			64
# define VIEW_MAX		100

# include <math.h>
# include <fcntl.h>
# include <SDL2/SDL.h>
# include <SDL_image.h>
# include "../libft/libft.h"

typedef struct		s_col
{
	int				start;
	int				end;
}					t_col;

typedef struct		s_map
{
	int				**map;
	int				map_width;
	int				map_height;
	SDL_Surface		*texture;
	int				side;
}					t_map;

typedef struct		s_cast
{
	int				mapx;
	int				mapy;
	int				nextx;
	int				nexty;
	int				side;
}					t_cast;

typedef struct		s_ray
{
	double			x;
	double			y;
	double			sx;
	double			sy;
	double			dx;
	double			dy;
	double			wall_dist;
	int				wall_id;
	double			wall_x;
	int				wall_height;
	int				tex_x;
	t_cast			cast;
	t_map			*map;
}					t_ray;

typedef struct		s_mouse
{
	int				x;
	int				y;
	int				prev_x;
	int				prev_y;
}					t_mouse;

typedef struct		s_player
{
	double			x;
	double			y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
}					t_player;

typedef struct		s_engine
{
	SDL_Window		*window;
	SDL_Surface		*surface;
	SDL_Surface		*gun;
	t_player		*player;
	t_map			*map;
	t_mouse			*mouse;
	t_ray			*ray;
	double			frame_time;
	int				quit;
}					t_engine;

void				render(t_engine *engine);

t_engine			*initialize(char *title);
void				init_engine(t_engine *engine);
SDL_Surface			*load_image(t_engine *engine, char *path);
int					free_engine(t_engine *engine);

void				put_pixel(t_engine *engine, int x, int y, Uint32 color);
void				clear_screen(t_engine *engine, Uint32 color);
void				update_screen(t_engine *engine);

void				game_loop(t_engine *engine);
void				raycast(t_engine *engine, t_player *player, int x);

void				draw_column(t_engine *engine, int x, t_col y_col,
								t_ray *ray);

void				move_towards(t_engine *engine, int i);
void				move_side(t_engine *engine, int i);

void				parser(t_engine *wo, char *a);

#endif
