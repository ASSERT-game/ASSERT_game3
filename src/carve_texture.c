/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carve_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 19:51:55 by home              #+#    #+#             */
/*   Updated: 2020/07/07 21:32:18 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

#define TEXT_TILE_SIZE (32)

SDL_Rect	*carve_g3_texture(void)
{
	int			row;
	int			col;
	SDL_Rect	*result;

	row = 0;
	result = malloc(sizeof(*result) * (16 * 16));
	while (row < 16)
	{
		col = 0;
		while (col < 16)
		{
			result[row * 16 + col].h = (TEXT_TILE_SIZE);
			result[row * 16 + col].w = (TEXT_TILE_SIZE);
			result[row * 16 + col].x = (col * (TEXT_TILE_SIZE));
			result[row * 16 + col].y = (row * (TEXT_TILE_SIZE));
			col++;
		}
		row++;
	}
	return (result);
}
