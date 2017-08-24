/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 12:45:54 by twalton           #+#    #+#             */
/*   Updated: 2017/08/24 13:23:31 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	fract_2(int iter_max, t_coor *coor, t_coor *constant)
{
	t_coor	result;
	double	xtemp;
	int		i;

	result.x = constant->x;
	result.y = constant->y;
	i = 0;
	while (i < iter_max && result.x * result.x + result.y * result.y < 100)
	{
		xtemp = result.x * result.x - result.y * result.y + coor->x;
		result.y = 2 * result.x * result.y + coor->y;
		result.x = xtemp;
		++i;
	}
	return (i);
}
