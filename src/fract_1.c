/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 12:33:53 by twalton           #+#    #+#             */
/*   Updated: 2017/08/24 13:27:17 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	fract_1(int iter_max, t_coor *coor, t_coor *constant)
{
	t_coor	result;
	t_coor	result_sq;
	int		i;

	result.x = coor->x;
	result.y = coor->y;
	result_sq.x = result.x * result.x;
	result_sq.y = result.y * result.y;
	i = 0;
	while (i < iter_max && result_sq.x + result_sq.y < 100)
	{
		result.y = 2 * result.x * result.y + constant->y;
		result.x = result_sq.x - result_sq.y + constant->x;
		result_sq.x = result.x * result.x;
		result_sq.y = result.y * result.y;
		++i;
	}
	return (i);
}
