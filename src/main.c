/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 02:31:10 by home              #+#    #+#             */
/*   Updated: 2020/07/08 04:22:50 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	game_context_initialize(t_game_context *game_state, t_display *display)
{
	game_state->active = true;

	game_state->texture = IMG_LoadTexture(display->renderer, "resources/ASSERT_game3_texture.png");
	game_state->src_rect = carve_g3_texture();

	game_state->ticks = 0;
	game_state->game_over = false;

	init_player(&(game_state->player), 2, 90);

	// srand(time(NULL));
	(void)display;
}

int	main(void)
{
	t_display		display;
	t_game_context	game_state;

	int	z_x;
	int	z_y;

	z_x = 0;
	z_y = 0;

	SDLU_start(&display);
	game_context_initialize(&game_state, &display);
	while (game_state.active == true)
	{
		process_user_input(&game_state);

		update_game_state(&game_state);

		draw_tri_wall(&game_state, &display, 0, 1);
		draw_reg_wall(&game_state, &display, 1, 1);
		draw_reg_wall(&game_state, &display, 2, 1);
		draw_reg_wall(&game_state, &display, 3, 1);

		draw_tri_wall(&game_state, &display, 4, 1);
		draw_reg_wall(&game_state, &display, 5, 1);
		draw_reg_wall(&game_state, &display, 6, 1);
		draw_reg_wall(&game_state, &display, 7, 1);
		draw_tri_wall(&game_state, &display, 8, 1);

		draw_zombie(&game_state, &display, z_x, z_y + 90);
		draw_zombie(&game_state, &display, z_x, z_y + 160);
		draw_zombie(&game_state, &display, z_x, z_y + 200);
		// draw_zombie(&game_state, &display, z_x, z_y + 90);

		update_player(&(game_state));
		draw_player(&game_state, &display);

		draw_tri_wall(&game_state, &display, 0, 5);
		draw_reg_wall(&game_state, &display, 1, 5);
		draw_reg_wall(&game_state, &display, 2, 5);
		draw_reg_wall(&game_state, &display, 3, 5);

		draw_tri_wall(&game_state, &display, 4, 5);
		draw_reg_wall(&game_state, &display, 5, 5);
		draw_reg_wall(&game_state, &display, 6, 5);
		draw_reg_wall(&game_state, &display, 7, 5);
		draw_tri_wall(&game_state, &display, 8, 5);


		SDL_RenderPresent(display.renderer);
		SDL_RenderClear(display.renderer);

		// z_y++;
		z_x++;
	}
	SDLU_close(&display);
	return (0);
}
