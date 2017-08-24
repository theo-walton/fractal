/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 14:58:25 by twalton           #+#    #+#             */
/*   Updated: 2017/08/24 14:58:25 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	mouse_press_hook(int keynum, int x, int y, t_fract *fract)
{
	(void)x;
	(void)y;
	if (keynum == MOUSE_SCROLL_UP)
		zoom_fract(fract, '+');
	if (keynum == MOUSE_SCROLL_DOWN)
		zoom_fract(fract, '-');
	return (1);
}
