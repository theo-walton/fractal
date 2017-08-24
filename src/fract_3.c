/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 14:48:44 by twalton           #+#    #+#             */
/*   Updated: 2017/08/24 13:27:31 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	fract_3(int iter_max, t_coor *coor, t_coor *constant)
{
	t_coor	result;
	int		i;

	result.x = coor->x;
	result.y = coor->y;
	i = 0;
	while (i < iter_max && result.x * result.x + result.y * result.y < 100)
	{
		complex_multiply(&result, &result, &result);
		complex_sum(&result, constant, &result);
		complex_multiply(&result, &result, &result);
		complex_multiply(&result, &result, &result);
		++i;
	}
	return (i);
}
