/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 02:38:19 by home              #+#    #+#             */
/*   Updated: 2020/07/10 20:14:09 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	draw_tri_wall(t_game_context *game_state, t_display *display, int x, int y)
{
	SDL_Rect	dest;

	dest.h = TILE_SIZE;
	dest.w = TILE_SIZE;
	dest.x = x * TILE_SIZE;
	dest.y = y * TILE_SIZE;
	SDL_RenderCopy(display->renderer, game_state->texture, &(game_state->src_rect[WALL_TRI_BODY]), &dest);
	dest.y -= TILE_SIZE;
	SDL_RenderCopy(display->renderer, game_state->texture, &(game_state->src_rect[WALL_TRI_TOP]), &dest);
}

void	draw_reg_wall(t_game_context *game_state, t_display *display, int x, int y)
{
	SDL_Rect	dest;

	dest.h = TILE_SIZE;
	dest.w = TILE_SIZE;
	dest.x = x * TILE_SIZE;
	dest.y = y * TILE_SIZE;
	SDL_RenderCopy(display->renderer, game_state->texture, &(game_state->src_rect[WALL_BODY]), &dest);
	dest.y -= TILE_SIZE;
	SDL_RenderCopy(display->renderer, game_state->texture, &(game_state->src_rect[WALL_TOP]), &dest);
}

void	draw_player(t_game_context *game_state, t_display *display)
{
	int			player_animation;
	SDL_Rect	dest;

	dest.h = 70;
	dest.w = 70;
	dest.x = (game_state->player.loc_x);
	dest.y = (game_state->player.loc_y);
	player_animation = game_state->player.facing + game_state->player.animation_id;

	SDL_RenderCopy(display->renderer, game_state->texture, &(game_state->src_rect[player_animation]), &dest);
}

void	draw_zombie(t_game_context *game_state, t_display *display, t_zombie *zombie)
{
	SDL_Rect	dest;

	dest.h = 70;
	dest.w = 70;
	dest.x = zombie->loc_x;
	dest.y = zombie->loc_y;
	SDL_RenderCopy(display->renderer, game_state->texture, &(game_state->src_rect[zombie->animation_id]), &dest);
}

void	draw_horde(t_game_context *game_state, t_display *display)
{
	int	i;

	i = 0;
	while (i < game_state->zombie_capacity)
	{
		if (game_state->zombies[i].active == true)
			draw_zombie(game_state, display, &(game_state->zombies[i]));
		i++;
	}
}

void	draw_hp(t_game_context *game_state, t_display *display)
{
	SDL_Rect	dest;
	SDL_Rect	src;

	dest.h = 5;
	dest.w = 32;
	dest.x = game_state->player.loc_x + 16;
	dest.y = game_state->player.loc_y;

	src = game_state->src_rect[UTILS];
	src.h = 5;
	src.w = 32;
	SDL_RenderCopy(display->renderer, game_state->texture, &(src), &dest);

	dest.x++;
	dest.y++;
	dest.h = 3;
	dest.w = (game_state->player.hp * 30) / 100;

	src.x++;
	src.y += 6;
	src.h = 3;
	src.w = 30;

	if (game_state->player.hp < 60)
		src.y += 4;
	if (game_state->player.hp < 35)
		src.y += 4;

	SDL_RenderCopy(display->renderer, game_state->texture, &(src), &dest);
}
