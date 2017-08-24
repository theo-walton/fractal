/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 13:57:45 by twalton           #+#    #+#             */
/*   Updated: 2017/08/20 13:57:45 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	open_windows(t_info *info)
{
	if (info->julia)
		info->fjulia->win = mlx_new_window(info->mlx, X_DIM, Y_DIM, "");
	if (info->mand)
		info->fmand->win = mlx_new_window(info->mlx, X_DIM, Y_DIM, "");
	if (info->theo)
		info->ftheo->win = mlx_new_window(info->mlx, X_DIM, Y_DIM, "");
	if (info->forth)
		info->fforth->win = mlx_new_window(info->mlx, X_DIM, Y_DIM, "");
	if (info->five)
		info->ffive->win = mlx_new_window(info->mlx, X_DIM, Y_DIM, "");
	if (info->cool)
		info->fcool->win = mlx_new_window(info->mlx, X_DIM, Y_DIM, "");
}
