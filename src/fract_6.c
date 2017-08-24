/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 11:40:21 by twalton           #+#    #+#             */
/*   Updated: 2017/08/24 11:40:21 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	fract_6(int iter_max, t_coor *coor, t_coor *constant)
{
	int		i;
	double	x;
	double	y;
	double	temp;

	i = 0;
	x = coor->x;
	y = coor->y;
	while (i < iter_max && x * x + y * y < 100)
	{
		temp = (constant->x * x - constant->y * y) * (x - 1) -
			(constant->y * x * y + constant->x * y * y);
		y = (constant->y * x + constant->x * y) + (constant->x *
			x * y - constant->y * y * y);
		x = temp;
		++i;
	}
	return (i);
}
