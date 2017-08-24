/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 23:15:26 by twalton           #+#    #+#             */
/*   Updated: 2017/08/24 14:11:22 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_STRUCTS_H
# define FRACT_STRUCTS_H

typedef struct	s_coor
{
	double		x;
	double		y;
}				t_coor;

typedef struct	s_map
{
	int			width;
	int			height;
	t_coor		*coor;
}				t_map;

typedef struct	s_keytog
{
	int			q;
	int			e;
	int			space;
	int			w;
	int			a;
	int			s;
	int			d;
	int			z;
	int			x;
}				t_keytog;

typedef struct	s_fract
{
	int			type;
	int			max_it;
	double		sensitivity;
	double		zoom;
	t_coor		*constant;
	int			colour;
	void		*win;
	void		*mlx;
	t_map		*map;
	int			xmouse;
	int			ymouse;
	void		*info;
	t_keytog	*keytog;
}				t_fract;

typedef struct	s_info
{
	int			julia;
	int			mand;
	int			theo;
	int			forth;
	int			five;
	int			cool;
	t_fract		*fjulia;
	t_fract		*fmand;
	t_fract		*ftheo;
	t_fract		*fforth;
	t_fract		*ffive;
	t_fract		*fcool;
	void		*mlx;
}				t_info;

typedef struct	s_image
{
	void		*ptr;
	int			*im;
	int			bpp;
	int			line_sz;
	int			end;
}				t_image;

#endif
