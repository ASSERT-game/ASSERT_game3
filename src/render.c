/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 02:38:19 by home              #+#    #+#             */
/*   Updated: 2020/07/07 01:23:42 by home             ###   ########.fr       */
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

	dest.h = 54;
	dest.w = 54;
	dest.x = (game_state->player.loc_x);
	dest.y = (game_state->player.loc_y);
	player_animation = game_state->player.animation_id;

	if (game_state->player.facing == -1)
		SDL_RenderCopyEx(display->renderer, game_state->texture, &(game_state->src_rect[player_animation]), &dest, 180, NULL, SDL_FLIP_VERTICAL);
	else
		SDL_RenderCopy(display->renderer, game_state->texture, &(game_state->src_rect[player_animation]), &dest);
}
