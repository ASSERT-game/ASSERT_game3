/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 21:04:18 by home              #+#    #+#             */
/*   Updated: 2020/07/10 21:11:34 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	init_board(char ***dest, int *width, int *height)
{
	int		i;
	int		size;
	char	**board;

	i = 0;
	size = 10;
	board = malloc(sizeof(*board) * (size));
	while (i < (size))
	{
		board[i] = malloc(sizeof(**board) * (20));
		i++;
	}
	*width = 10;
	*height = 10;
	*dest = board;
}
