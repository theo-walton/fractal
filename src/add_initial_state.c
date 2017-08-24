/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_initial_state.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 14:07:48 by twalton           #+#    #+#             */
/*   Updated: 2017/08/24 13:30:09 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static t_map	*add_new_map(void)
{
	t_map	*new;
	int		i;
	int		total_size;

	total_size = X_DIM * Y_DIM;
	i = 0;
	if (!(new = malloc(sizeof(t_map))))
		return (NULL);
	new->width = X_DIM;
	new->height = Y_DIM;
	if (!(new->coor = malloc(sizeof(t_coor) * X_DIM * Y_DIM)))
		return (NULL);
	while (i < total_size)
	{
		new->coor[i].x = (double)(i % X_DIM - X_DIM / 2) / ZOOM_START;
		new->coor[i].y = (double)(i / X_DIM - Y_DIM / 2) / ZOOM_START;
		++i;
	}
	return (new);
}

static t_coor	*add_initial_const(void)
{
	t_coor *new;

	if (!(new = ft_memalloc(sizeof(t_coor))))
		return (NULL);
	new->x = 0;
	new->y = 0;
	return (new);
}

static t_fract	*add_new_fract(t_info *info, int type)
{
	t_fract *new;

	if (!(new = ft_memalloc(sizeof(t_fract))))
		return (NULL);
	new->max_it = 50;
	new->zoom = 1;
	if (!(new->constant = add_initial_const()))
		return (NULL);
	new->colour = 1;
	new->mlx = info->mlx;
	if (!(new->map = add_new_map()))
		return (NULL);
	if (!(new->keytog = ft_memalloc(sizeof(t_keytog))))
		return (NULL);
	new->xmouse = 0;
	new->ymouse = 0;
	new->type = type;
	new->info = info;
	new->sensitivity = INITIAL_SENSITIVITY;
	return (new);
}

int				add_initial_state(t_info *info)
{
	if (info->julia)
		if (!(info->fjulia = add_new_fract(info, 1)))
			return (0);
	if (info->mand)
		if (!(info->fmand = add_new_fract(info, 2)))
			return (0);
	if (info->theo)
		if (!(info->ftheo = add_new_fract(info, 3)))
			return (0);
	if (info->forth)
		if (!(info->fforth = add_new_fract(info, 4)))
			return (0);
	if (info->five)
		if (!(info->ffive = add_new_fract(info, 5)))
			return (0);
	if (info->cool)
		if (!(info->fcool = add_new_fract(info, 6)))
			return (0);
	return (1);
}
