/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 15:06:04 by twalton           #+#    #+#             */
/*   Updated: 2017/08/22 15:06:04 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static void	change_iter(t_fract *fract, char sign)
{
	struct timespec tim;

	tim.tv_sec = 0;
	tim.tv_nsec = 50000000;
	if (sign == '-')
	{
		if (fract->max_it > 1)
			--fract->max_it;
	}
	else
	{
		if (fract->max_it < 199)
			++fract->max_it;
	}
	redraw_fract(fract);
	nanosleep(&tim, NULL);
}

static void	fractal_loop(t_fract *fract)
{
	if (fract->keytog->q)
		zoom_fract(fract, '+');
	if (fract->keytog->e)
		zoom_fract(fract, '-');
	if (fract->keytog->w)
		move_fract(fract, '+', '\0');
	if (fract->keytog->s)
		move_fract(fract, '-', '\0');
	if (fract->keytog->a)
		move_fract(fract, '\0', '+');
	if (fract->keytog->d)
		move_fract(fract, '\0', '-');
	if (fract->keytog->z)
		change_iter(fract, '-');
	if (fract->keytog->x)
		change_iter(fract, '+');
}

int			loop_hook(t_info *info)
{
	if (info->julia)
		fractal_loop(info->fjulia);
	if (info->mand)
		fractal_loop(info->fmand);
	if (info->theo)
		fractal_loop(info->ftheo);
	if (info->forth)
		fractal_loop(info->fforth);
	if (info->five)
		fractal_loop(info->ffive);
	if (info->cool)
		fractal_loop(info->fcool);
	return (0);
}
