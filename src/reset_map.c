/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 00:38:56 by twalton           #+#    #+#             */
/*   Updated: 2017/08/23 00:38:56 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	reset_map(t_map *map)
{
	int i;
	int total_size;

	total_size = X_DIM * Y_DIM;
	i = 0;
	while (i < total_size)
	{
		map->coor[i].x = (double)(i % X_DIM - X_DIM / 2) / ZOOM_START;
		map->coor[i].y = (double)(i / X_DIM - Y_DIM / 2) / ZOOM_START;
		++i;
	}
}
