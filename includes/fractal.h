/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 20:44:40 by twalton           #+#    #+#             */
/*   Updated: 2017/08/24 14:12:10 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "fract_structs.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "keys.h"
# include <time.h>

# define INFIN 9999999999
# define X_DIM 501
# define Y_DIM 501
# define ZOOM_CONST1 0.9
# define ZOOM_CONST2 1.111111
# define PIX_PER_SHIFT 10
# define ZOOM_START 100
# define INITIAL_SENSITIVITY 25

# define JULIA 1
# define MAND 2
# define THEO 3
# define FORTH 4
# define FIVE 5
# define COOL 6

int		fract_1(int iter_max, t_coor *coor, t_coor *constant);
int		fract_2(int iter_max, t_coor *coor, t_coor *constant);
int		fract_3(int iter_max, t_coor *coor, t_coor *constant);
int		fract_4(int iter_max, t_coor *coor, t_coor *constant);
int		fract_5(int iter_max, t_coor *coor, t_coor *constant);
int		fract_6(int iter_max, t_coor *coor, t_coor *constant);

int		mouse_press_hook(int keynum, int x, int y, t_fract *fract);
void	draw_all_fractals(t_info *info);
void	redraw_fract(t_fract *fract);
void	reset_map(t_map *map);
void	move_fract(t_fract *fract, char col_move, char row_move);
void	move_map(t_map *map, char col_move, char row_move);
void	correct_map(t_map *map);
int		loop_hook(t_info *info);
void	zoom_fract(t_fract *fract, char sign);
void	zoom_map(t_coor *center, t_map *map, char sign);
int		key_release_hook(int keynum, t_fract *fract);
int		key_press_hook(int keynum, t_fract *fract);
int		motion_hook(int x, int y, t_fract *fract);
int		add_initial_state(t_info *info);
int		are_arguments_valid(t_info *info, int ac, char **av);
void	open_windows(t_info *info);
void	set_hooks(t_info *info);
int		turn_iter_to_col(int iter, int colour_var);
void	complex_multiply(t_coor *a, t_coor *b, t_coor *result);
void	complex_sum(t_coor *a, t_coor *b, t_coor *result);
void	complex_divide(t_coor *a, t_coor *b, t_coor *result);

#endif
