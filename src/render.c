/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 02:38:19 by home              #+#    #+#             */
/*   Updated: 2020/07/06 22:45:34 by home             ###   ########.fr       */
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
