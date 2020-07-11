/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 18:36:16 by home              #+#    #+#             */
/*   Updated: 2020/07/10 20:57:45 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	init_player(t_player *dest, int x, int y)
{
	dest->loc_x = x;
	dest->loc_y = y;

	dest->facing = 0;
	dest->animation_id = PLAYER_ID_RIGHT;
	dest->moving = false;

	dest->hp = 1;
}

void	update_player(t_game_context *game_state)
{
	t_player *player;

	player = &(game_state->player);

	if (game_state->ticks % 15 == 0 && player->moving == true)
		player->animation_id += 16;
	if (player->animation_id >= PLAYER_ID_RIGHT + 32)
		player->animation_id -= 32;

	if (player->animation_id >= PLAYER_ID_RIGHT + 16 && player->moving == false)
		player->animation_id -= 16;

	if (game_state->ticks % 20 == 0)
		player->hp++;

	if (player->hp > 100)
		player->hp = 100;
}
