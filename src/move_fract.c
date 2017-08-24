/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_fract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 23:23:56 by twalton           #+#    #+#             */
/*   Updated: 2017/08/22 23:23:56 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	move_fract(t_fract *fract, char col_move, char row_move)
{
	move_map(fract->map, col_move, row_move);
	redraw_fract(fract);
}
