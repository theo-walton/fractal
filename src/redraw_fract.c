/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw_fract.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 01:35:02 by twalton           #+#    #+#             */
/*   Updated: 2017/08/23 01:35:02 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static void	calculate_fract_pt3(t_fract *fract, t_map *map,
				t_image *im, int total_size)
{
	int i;
	int temp;

	i = 0;
	if (fract->type == 5)
	{
		while (i < total_size)
		{
			temp = fract_5(fract->max_it, &map->coor[i], fract->constant);
			im->im[i] = turn_iter_to_col(temp, fract->colour);
			++i;
		}
	}
	else if (fract->type == 6)
	{
		while (i < total_size)
		{
			temp = fract_6(fract->max_it, &map->coor[i], fract->constant);
			im->im[i] = turn_iter_to_col(temp, fract->colour);
			++i;
		}
	}
}

static void	calculate_fract_p2(t_fract *fract, t_map *map,
					t_image *im, int total_size)
{
	int i;
	int temp;

	i = 0;
	if (fract->type == 3)
	{
		while (i < total_size)
		{
			temp = fract_3(fract->max_it, &map->coor[i], fract->constant);
			im->im[i] = turn_iter_to_col(temp, fract->colour);
			++i;
		}
	}
	else if (fract->type == 4)
	{
		while (i < total_size)
		{
			temp = fract_4(fract->max_it, &map->coor[i], fract->constant);
			im->im[i] = turn_iter_to_col(temp, fract->colour);
			++i;
		}
	}
	else
		calculate_fract_pt3(fract, map, im, total_size);
}

static void	calculate_fract(t_fract *fract, t_map *map, t_image *im)
{
	int i;
	int total_size;
	int temp;

	total_size = map->width * map->height;
	i = 0;
	if (fract->type == 1)
	{
		while (i < total_size)
		{
			temp = fract_1(fract->max_it, &map->coor[i], fract->constant);
			im->im[i] = turn_iter_to_col(temp, fract->colour);
			++i;
		}
	}
	else if (fract->type == 2)
	{
		while (i < total_size)
		{
			temp = fract_2(fract->max_it, &map->coor[i], fract->constant);
			im->im[i] = turn_iter_to_col(temp, fract->colour);
			++i;
		}
	}
	calculate_fract_p2(fract, map, im, total_size);
}

void		redraw_fract(t_fract *fract)
{
	t_image im;

	im.ptr = mlx_new_image(fract->mlx, X_DIM, Y_DIM);
	im.im = (int*)mlx_get_data_addr(im.ptr, &im.bpp, &im.line_sz, &im.end);
	calculate_fract(fract, fract->map, &im);
	mlx_clear_window(fract->mlx, fract->win);
	mlx_put_image_to_window(fract->mlx, fract->win, im.ptr, 0, 0);
	mlx_destroy_image(fract->mlx, im.ptr);
}
