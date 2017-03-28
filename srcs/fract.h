/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 20:47:08 by ssalaues          #+#    #+#             */
/*   Updated: 2017/03/23 16:34:43 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H
# define MAX 1000
# define T_W	fdf.t_s
# define T_H	fdf.t_s
# define X_OFF	fdf.t_w
# define Y_OFF	fdf.t_h
# define C_1 0xfffd4
# define C_2 0xff34b3
# define C_3 0xcc9ca
# define C_4 0xff3030
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "mlx_keys_mac.h"
# include "../libft/libft.h"
# include "../mlx/mlx.h"


typedef struct		s_frac
{
	int				row;
	int				col;
	int				h;
	int				w;
	int				iter;
	int				rgb;
	float			x;
	float			x0;
	float			y;
	float			y0;
	float			c_re;
	float			c_im;
	void			*mlx;
	void			*win;
}					t_frac;

typedef struct		s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_rgb;

struct				s_colors
{
	char			*name;
	int				color;
};


void				colors(t_frac fr);
void				mand_init(t_frac fr);

#endif
