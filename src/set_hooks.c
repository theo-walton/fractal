/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 13:38:09 by twalton           #+#    #+#             */
/*   Updated: 2017/08/20 13:38:09 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static int	expose(t_fract *fract)
{
	if (fract->type == JULIA)
		redraw_fract(fract);
	if (fract->type == MAND)
		redraw_fract(fract);
	if (fract->type == THEO)
		redraw_fract(fract);
	if (fract->type == FORTH)
		redraw_fract(fract);
	if (fract->type == FIVE)
		redraw_fract(fract);
	if (fract->type == COOL)
		redraw_fract(fract);
	return (0);
}

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

static int	exit_hook(t_fract *fract)
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
	return (1);
}

static void	set_fract_hooks(t_fract *fract)
{
	mlx_expose_hook(fract->win, expose, fract);
	mlx_hook(fract->win, 6, 0, motion_hook, fract);
	mlx_hook(fract->win, 2, 0, key_press_hook, fract);
	mlx_hook(fract->win, 3, 0, key_release_hook, fract);
	mlx_hook(fract->win, 4, 0, mouse_press_hook, fract);
	mlx_hook(fract->win, 17, 0, exit_hook, fract);
}

void		set_hooks(t_info *info)
{
	mlx_loop_hook(info->mlx, loop_hook, info);
	if (info->julia)
		set_fract_hooks(info->fjulia);
	if (info->mand)
		set_fract_hooks(info->fmand);
	if (info->theo)
		set_fract_hooks(info->ftheo);
	if (info->forth)
		set_fract_hooks(info->fforth);
	if (info->five)
		set_fract_hooks(info->ffive);
	if (info->cool)
		set_fract_hooks(info->fcool);
}
