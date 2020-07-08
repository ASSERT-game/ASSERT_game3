/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 11:30:10 by home              #+#    #+#             */
/*   Updated: 2020/07/07 01:24:51 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

# define PLAYER_SPEED (3)

void	process_user_input(t_game_context *game_state)
{
	SDL_Event		e;
	const Uint8		*keystate;

	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT)
		{
			game_state->active = false;
			break ;
		}
	}
	keystate = SDL_GetKeyboardState(NULL);

	if (keystate[SDL_SCANCODE_W] || keystate[SDL_SCANCODE_UP])
		game_state->player.loc_y -= PLAYER_SPEED;
	if (keystate[SDL_SCANCODE_S] || keystate[SDL_SCANCODE_DOWN])
		game_state->player.loc_y += PLAYER_SPEED;
	if (keystate[SDL_SCANCODE_A] || keystate[SDL_SCANCODE_LEFT])
	{
		game_state->player.facing = -1;
		game_state->player.loc_x -= PLAYER_SPEED;
	}
	if (keystate[SDL_SCANCODE_D] || keystate[SDL_SCANCODE_RIGHT])
	{
		game_state->player.facing = 1;
		game_state->player.loc_x += PLAYER_SPEED;
	}
}
