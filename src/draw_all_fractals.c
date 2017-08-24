/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_all_fractals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 01:07:25 by twalton           #+#    #+#             */
/*   Updated: 2017/08/24 01:07:25 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	draw_all_fractals(t_info *info)
{
	if (info->julia)
		redraw_fract(info->fjulia);
	if (info->mand)
		redraw_fract(info->fmand);
	if (info->theo)
		redraw_fract(info->ftheo);
	if (info->forth)
		redraw_fract(info->fforth);
	if (info->five)
		redraw_fract(info->ffive);
	if (info->cool)
		redraw_fract(info->fcool);
}
