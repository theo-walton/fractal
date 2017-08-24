/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   are_arguments_valid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 15:40:58 by twalton           #+#    #+#             */
/*   Updated: 2017/08/20 15:40:58 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static int	valid_fract(t_info *info, char *str)
{
	if (!ft_strcmp(str, "julia"))
		return ((info->julia = 1));
	if (!ft_strcmp(str, "mandel"))
		return ((info->mand = 1));
	if (!ft_strcmp(str, "evolve"))
		return ((info->theo = 1));
	if (!ft_strcmp(str, "star"))
		return ((info->forth = 1));
	if (!ft_strcmp(str, "person"))
		return ((info->five = 1));
	if (!ft_strcmp(str, "swirl"))
		return ((info->cool = 1));
	return (0);
}

static int	give_usage(void)
{
	ft_putstr("\n\x1b[33m./fractol \x1b[37m[julia] [mandel] [evolve] [star] \
[person] [swirl]\n");
	ft_putstr("\n\x1b[33mkeys:\x1b[37m\n\tw a s d - move\n\tq e / mouse scroll - zoom\n\
\tr - sharpen image\n\tf - reset veiw\n\tz x - change iterations\n\ttab - \
change colour scheme\n\tspace - mutate fractal (while holding)\n\n");
	exit(1);
}

int			are_arguments_valid(t_info *info, int ac, char **av)
{
	int i;

	i = 1;
	if (ac == 1)
		give_usage();
	while (i < ac)
	{
		if (!valid_fract(info, av[i]))
			return (0);
		++i;
	}
	return (1);
}
