/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 22:42:15 by twalton           #+#    #+#             */
/*   Updated: 2017/08/22 22:42:15 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	correct_map(t_map *map)
{
	int		i;
	double	diff;
	double	xstart;
	double	ystart;

	xstart = map->coor[0].x;
	ystart = map->coor[0].y;
	i = 0;
	diff = (map->coor[map->width - 1].x - map->coor[0].x) / map->width;
	while (i < map->width * map->height)
	{
		map->coor[i].x = xstart + (i % map->width) * diff;
		map->coor[i].y = ystart + (i / map->width) * diff;
		++i;
	}
}
