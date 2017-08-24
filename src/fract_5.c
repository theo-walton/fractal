/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 23:08:36 by twalton           #+#    #+#             */
/*   Updated: 2017/08/23 23:08:36 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	fract_5(int iter_max, t_coor *coor, t_coor *constant)
{
	double	x;
	double	y;
	double	temp;
	int		i;

	i = 0;
	x = coor->x;
	y = coor->y;
	temp = x * y;
	while (i < iter_max && x * x + y * y < 100)
	{
		x += constant->x * fmod(x, y);
		y += constant->y * fmod(y, x);
		y = x * x - y * constant->y;
		x = y * constant->x - y * y;
		++i;
	}
	return (i);
}
