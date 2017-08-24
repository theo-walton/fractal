/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 12:41:49 by twalton           #+#    #+#             */
/*   Updated: 2017/08/22 12:41:49 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static void	shift_row(t_map *map, int row_num, char sign)
{
	int		a;
	int		b;
	double	diff;

	a = row_num * map->width;
	b = 0;
	diff = map->coor[a + PIX_PER_SHIFT].x - map->coor[a].x;
	if (sign == '-')
		diff = -diff;
	while (b < map->width)
		map->coor[a + b++].x += diff;
}

static void	shift_col(t_map *map, int col_num, char sign)
{
	int		a;
	int		b;
	double	diff;

	a = col_num;
	b = 0;
	diff = map->coor[a + PIX_PER_SHIFT * map->width].y - map->coor[a].y;
	if (sign == '-')
		diff = -diff;
	while (b < map->height)
		map->coor[a + b++ * map->width].y += diff;
}

void		move_map(t_map *map, char col_move, char row_move)
{
	int i;

	if (row_move)
	{
		i = 0;
		while (i < map->height)
			shift_row(map, i++, row_move);
	}
	if (col_move)
	{
		i = 0;
		while (i < map->width)
			shift_col(map, i++, col_move);
	}
}
