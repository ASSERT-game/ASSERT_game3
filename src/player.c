/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 18:36:16 by home              #+#    #+#             */
/*   Updated: 2020/07/07 18:46:13 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	init_player(t_player *dest, int x, int y)
{
	dest->vel_x = 0;
	dest->vel_y = 0;

	dest->loc_x = x;
	dest->loc_y = y;

	dest->animation_id = PLAYER_ID_1;
}

void	update_player(t_game_context *game_state)
{
	t_player *player;

	player = &(game_state->player);

	player->animation_id++;
	if (player->animation_id > PLAYER_ID_2)
		player->animation_id = PLAYER_ID_1;
}
