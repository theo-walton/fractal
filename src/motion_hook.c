/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 20:27:35 by twalton           #+#    #+#             */
/*   Updated: 2017/08/20 20:27:35 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static int	is_in_window(int x, int y)
{
	if (x > X_DIM || x < 0)
		return (0);
	if (y > Y_DIM || y < 0)
		return (0);
	return (1);
}

static int	valid_toggles(t_fract *fract)
{
	if (fract->keytog->q == 1)
		return (0);
	if (fract->keytog->e == 1)
		return (0);
	if (fract->keytog->w == 1)
		return (0);
	if (fract->keytog->a == 1)
		return (0);
	if (fract->keytog->s == 1)
		return (0);
	if (fract->keytog->d == 1)
		return (0);
	if (fract->keytog->space != 1)
		return (0);
	return (1);
}

int			motion_hook(int x, int y, t_fract *fract)
{
	fract->xmouse = x;
	fract->ymouse = y;
	if (is_in_window(x, y) && valid_toggles(fract))
	{
		fract->constant->x = (double)(x - X_DIM / 2) / fract->sensitivity;
		fract->constant->y = (double)(y - Y_DIM / 2) / fract->sensitivity;
		redraw_fract(fract);
	}
	return (1);
}
