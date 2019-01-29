/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drestles <drestles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 21:24:04 by cmelara-          #+#    #+#             */
/*   Updated: 2019/01/29 14:11:18 by drestles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	turn_player(t_player *player, double angle)
{
	double tmp_dir;
	double tmp_plane;
	double c;
	double s;

	c = cos(angle);
	s = sin(angle);
	tmp_dir = player->dir_x;
	tmp_plane = player->plane_x;
	player->dir_x = tmp_dir * c - player->dir_y * s;
	player->dir_y = tmp_dir * s + player->dir_y * c;
	player->plane_x = tmp_plane * c - player->plane_y * s;
	player->plane_y = tmp_plane * s + player->plane_y * c;
}

void	mouse_move(t_engine *engine, SDL_Event *e)
{
	double deltax;

	engine->mouse->prev_x = engine->mouse->x;
	engine->mouse->x = e->motion.x;
	deltax = (engine->mouse->prev_x - engine->mouse->x) * engine->frame_time
			* 0.5f;
	turn_player(engine->player, deltax);
}

void	handle_events(t_engine *engine, SDL_Event *e)
{
	while (SDL_PollEvent(e))
	{
		if (e->type == SDL_QUIT)
			engine->quit = 1;
		if (e->type == SDL_KEYUP && e->key.keysym.sym == SDLK_ESCAPE)
			engine->quit = 1;
		if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_w)
			move_towards(engine, 1);
		else if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_s)
			move_towards(engine, -1);
		if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_d)
			move_side(engine, 1);
		else if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_a)
			move_side(engine, -1);
		if (e->type == SDL_MOUSEMOTION)
			mouse_move(engine, e);
		if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_1)
			parser(engine, "maps/level0");
		if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_2)
			parser(engine, "maps/level1");
		if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_3)
			parser(engine, "maps/level2");
		if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_4)
			parser(engine, "maps/level3");
	}
}

void	fps_count(t_engine *engine, double *time, double *old_time, double *ft)
{
	*old_time = *time;
	*time = SDL_GetTicks();
	*ft = (*time - *old_time) / 1000.0f;
	engine->frame_time = *ft;
}

void	game_loop(t_engine *engine)
{
	SDL_Event	e;
	double		time;
	double		old_time;
	double		frame_time;

	time = 0;
	old_time = 0;
	while (!engine->quit)
	{
		fps_count(engine, &time, &old_time, &frame_time);
		render(engine);
		handle_events(engine, &e);
	}
}
