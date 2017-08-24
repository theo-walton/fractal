/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 19:59:10 by twalton           #+#    #+#             */
/*   Updated: 2017/08/23 19:59:10 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	fract_4(int iter_max, t_coor *coor, t_coor *constant)
{
	double i;

	i = fabs(iter_max * tan(coor->x * coor->y + constant->x * coor->x -
		constant->y * coor->y));
	i = i * coor->x - i * coor->y;
	return ((int)i);
}
