/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 20:52:34 by home              #+#    #+#             */
/*   Updated: 2020/07/08 18:22:18 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void		update_game_state(t_game_context *game_state)
{
	int		i;

	i = 0;
	update_player(game_state);
	while (i < game_state->zombie_capacity)
	{
		if (game_state->zombies[i].active == true)
			update_zombie(game_state, &(game_state->zombies[i]));
		i++;
	}
	game_state->ticks++;
}
