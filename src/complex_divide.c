/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_divide.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 20:01:08 by twalton           #+#    #+#             */
/*   Updated: 2017/08/23 20:01:08 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	complex_divide(t_coor *a, t_coor *b, t_coor *result)
{
	double x1;
	double x2;
	double y1;
	double y2;

	x1 = a->x;
	x2 = b->x;
	y1 = a->y;
	y2 = b->y;
	if (!x2 && !y2)
	{
		result->x = INFIN;
		result->y = INFIN;
		return ;
	}
	result->x = (x1 * x2 + y1 * y2) / (x2 * x2 + y2 * y2);
	result->y = (y1 * x2 - x1 * y2) / (x2 * x2 + y2 * y2);
}
