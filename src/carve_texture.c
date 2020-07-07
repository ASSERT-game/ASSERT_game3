/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carve_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 19:51:55 by home              #+#    #+#             */
/*   Updated: 2020/07/06 22:41:24 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

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
			result[row * 16 + col].h = TILE_SIZE;
			result[row * 16 + col].w = TILE_SIZE;
			result[row * 16 + col].x = (col * TILE_SIZE);
			result[row * 16 + col].y = (row * TILE_SIZE);
			col++;
		}
		row++;
	}
	return (result);
}
