/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 21:23:07 by twalton           #+#    #+#             */
/*   Updated: 2017/08/20 21:23:07 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static int	no_fracts_left(t_info *info)
{
	if (info->julia)
		return (0);
	if (info->mand)
		return (0);
	if (info->theo)
		return (0);
	if (info->forth)
		return (0);
	if (info->five)
		return (0);
	if (info->cool)
		return (0);
	return (1);
}

static void	remove_fract_wind(t_fract *fract)
{
	t_info *info;

	info = (t_info*)fract->info;
	if (fract->type == JULIA)
		info->julia = 0;
	if (fract->type == MAND)
		info->mand = 0;
	if (fract->type == THEO)
		info->theo = 0;
	if (fract->type == FORTH)
		info->forth = 0;
	if (fract->type == FIVE)
		info->five = 0;
	if (fract->type == COOL)
		info->cool = 0;
	mlx_destroy_window(fract->mlx, fract->win);
	if (no_fracts_left(info))
		exit(1);
}

int			key_press_hook(int keynum, t_fract *fract)
{
	if (keynum == KEY_Q)
		fract->keytog->q = 1;
	else if (keynum == KEY_E)
		fract->keytog->e = 1;
	else if (keynum == KEY_SPACE)
		fract->keytog->space = 1;
	else if (keynum == KEY_W)
		fract->keytog->w = 1;
	else if (keynum == KEY_A)
		fract->keytog->a = 1;
	else if (keynum == KEY_S)
		fract->keytog->s = 1;
	else if (keynum == KEY_D)
		fract->keytog->d = 1;
	else if (keynum == KEY_ESC)
		remove_fract_wind(fract);
	else if (keynum == KEY_Z)
		fract->keytog->z = 1;
	else if (keynum == KEY_X)
		fract->keytog->x = 1;
	return (0);
}
