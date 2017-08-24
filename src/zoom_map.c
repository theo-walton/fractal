/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 20:39:25 by twalton           #+#    #+#             */
/*   Updated: 2017/08/20 20:39:25 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static void	translate_coor(t_coor *coor, t_coor *center, char sign)
{
	if (sign == '+')
	{
		coor->x = coor->x * ZOOM_CONST1 - center->x * ZOOM_CONST1 + center->x;
		coor->y = coor->y * ZOOM_CONST1 - center->y * ZOOM_CONST1 + center->y;
	}
	else
	{
		coor->x = coor->x * ZOOM_CONST2 - center->x * ZOOM_CONST2 + center->x;
		coor->y = coor->y * ZOOM_CONST2 - center->y * ZOOM_CONST2 + center->y;
	}
}

void		zoom_map(t_coor *center, t_map *map, char sign)
{
	int total_coor;
	int i;

	total_coor = map->width * map->height;
	i = 0;
	while (i < total_coor)
	{
		translate_coor(&map->coor[i], center, sign);
		++i;
	}
}
