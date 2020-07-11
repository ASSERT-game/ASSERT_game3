/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 03:05:42 by home              #+#    #+#             */
/*   Updated: 2020/07/09 19:32:45 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

#include <SDL2/SDL.h>
#include <stdbool.h>

typedef struct	s_display
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
}				t_display;

typedef struct	s_zombie
{
	bool		active;

	int			loc_x;
	int			loc_y;

	int			animation_id;
}				t_zombie;

typedef struct	s_player
{
	int			facing;

	int			loc_x;
	int			loc_y;

	int			animation_id;

	int			hp;
}				t_player;

typedef struct	s_game_context
{
	bool		active;

	SDL_Texture	*texture;
	SDL_Rect	*src_rect;

	int			ticks;

	bool		game_over;

	t_player	player;

	int			zombie_capacity;
	t_zombie	*zombies;

}				t_game_context;

#endif
