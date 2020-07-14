/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 02:38:32 by home              #+#    #+#             */
/*   Updated: 2020/07/10 21:11:15 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MASTER_H
# define MASTER_H

# include <stdio.h>

# include <SDL_image.h>

# include "structs.h"
# include "window_config.h"
# include "texture_id.h"

void		SDLU_start(t_display *dest);
void		SDLU_close(t_display *display);

SDL_Rect	*carve_g3_texture(void);

void		init_board(char ***dest, int *width, int *height);

void		process_user_input(t_game_context *game_state);
void		update_game_state(t_game_context *game_state);

void		draw_tri_wall(t_game_context *game_state, t_display *display, int x, int y);
void		draw_reg_wall(t_game_context *game_state, t_display *display, int x, int y);
void		draw_zombie(t_game_context *game_state, t_display *display, t_zombie * zombie);
void		draw_hp(t_game_context *game_state, t_display *display);

void		draw_player(t_game_context *game_state, t_display *display);
void		draw_horde(t_game_context *game_state, t_display *display);

void		update_player(t_game_context *game_state);
void		init_player(t_player *dest, int x, int y);

void		update_zombie(t_game_context *game_state, t_zombie *zombie);
void		init_zombie(t_zombie *dest, int x, int y);

// void		itow(int n, SDL_Rect dest, t_display *dislay);

#endif
