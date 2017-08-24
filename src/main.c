/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 22:39:57 by twalton           #+#    #+#             */
/*   Updated: 2017/08/19 22:39:57 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static void	error_out(int x)
{
	if (x == 1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

int			main(int ac, char **av)
{
	t_info info;

	ft_memset(&info, 0, sizeof(info));
	if (!are_arguments_valid(&info, ac, av))
		error_out(1);
	info.mlx = mlx_init();
	if (!(add_initial_state(&info)))
		error_out(1);
	open_windows(&info);
	draw_all_fractals(&info);
	set_hooks(&info);
	mlx_loop(info.mlx);
}
