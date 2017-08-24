/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_fract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 17:33:32 by twalton           #+#    #+#             */
/*   Updated: 2017/08/22 17:33:32 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static int	is_on_screen(int x, int y)
{
	if (x > X_DIM || x < 0)
		return (0);
	if (y > Y_DIM || y < 0)
		return (0);
	return (1);
}

void		zoom_fract(t_fract *fract, char sign)
{
	t_coor center;

	center.x = fract->map->coor[fract->xmouse + fract->ymouse * X_DIM].x;
	center.y = fract->map->coor[fract->xmouse + fract->ymouse * X_DIM].y;
	if (!is_on_screen(fract->xmouse, fract->ymouse))
		return ;
	zoom_map(&center, fract->map, sign);
	redraw_fract(fract);
}
