/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 19:02:13 by twalton           #+#    #+#             */
/*   Updated: 2017/08/20 19:02:13 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	complex_sum(t_coor *a, t_coor *b, t_coor *result)
{
	double x1;
	double x2;
	double y1;
	double y2;

	x1 = a->x;
	x2 = b->x;
	y1 = a->y;
	y2 = b->y;
	result->x = x1 + x2;
	result->y = y1 + y2;
}
