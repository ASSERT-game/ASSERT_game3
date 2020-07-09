/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 18:36:16 by home              #+#    #+#             */
/*   Updated: 2020/07/08 18:29:41 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	init_zombie(t_zombie *dest, int x, int y)
{
	dest->active = true;

	dest->loc_x = x;
	dest->loc_y = y;

	dest->animation_id = ZOMBIE_ID_1;
}

void	update_zombie(t_game_context *game_state, t_zombie *zombie)
{
	t_player *player;

	player = &(game_state->player);

	if (game_state->ticks % 20 == 0)
		zombie->animation_id += 16;
	if (zombie->animation_id > ZOMBIE_ID_2)
		zombie->animation_id = ZOMBIE_ID_1;

	if (zombie->loc_x < player->loc_x)
		zombie->loc_x++;
	else if (zombie->loc_x > player->loc_x)
		zombie->loc_x--;

	if (zombie->loc_y < player->loc_y)
		zombie->loc_y++;
	else if (zombie->loc_y > player->loc_y)
		zombie->loc_y--;
}
