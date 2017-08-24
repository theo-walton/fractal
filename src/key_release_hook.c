/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 17:44:26 by twalton           #+#    #+#             */
/*   Updated: 2017/08/22 17:44:26 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static int	more_release_hooks(int keynum, t_fract *fract)
{
	if (keynum == KEY_F)
	{
		reset_map(fract->map);
		redraw_fract(fract);
	}
	if (keynum == KEY_TAB)
	{
		fract->colour += 1;
		redraw_fract(fract);
	}
	if (keynum == KEY_Z)
		fract->keytog->z = 0;
	if (keynum == KEY_X)
		fract->keytog->x = 0;
	return (0);
}

int			key_release_hook(int keynum, t_fract *fract)
{
	if (keynum == KEY_Q)
		fract->keytog->q = 0;
	else if (keynum == KEY_E)
		fract->keytog->e = 0;
	else if (keynum == KEY_SPACE)
		fract->keytog->space = 0;
	else if (keynum == KEY_R)
	{
		correct_map(fract->map);
		redraw_fract(fract);
	}
	else if (keynum == KEY_W)
		fract->keytog->w = 0;
	else if (keynum == KEY_A)
		fract->keytog->a = 0;
	else if (keynum == KEY_S)
		fract->keytog->s = 0;
	else if (keynum == KEY_D)
		fract->keytog->d = 0;
	return (more_release_hooks(keynum, fract));
}
