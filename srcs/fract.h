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
# define MAX 100
# define T_W	1920
# define T_H	1080
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
# include <pthread.h>
# include <OpenCL/opencl.h>
# include "mlx_keys_mac.h"
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../tp_lib/ft_tp.h"


typedef struct		s_img
{
	unsigned char	*image;
	void			*mlx;
	void			*win;
}					t_img;

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

typedef struct	s_gpu
{
	cl_device_id		device_id;	// compute device id
	cl_context			context;	// compute context
	cl_command_queue	commands;	// compute command queue
	cl_program			program;	// compute program
	cl_kernel			kernel;		// compute kernel
	cl_mem				input;		// device mem used for input array
	cl_mem				output;		// device mem used for output array
	int					err;		// error code return from api calls
}				t_gpu;

typedef struct		s_frac
{
	int				row;
	int				max_row;
	int				col;
	int				max_col;
	int				h;
	int				w;
	int				iter;
	int             min;
	int             max;
	int				rgb;
	unsigned char	image[T_W * T_H];
	float			x;
	float           zx;
	float           zx2;
	float			x0;
	float			y;
	float           zy;
	float           zy2;
	float			y0;
	float			c_re;
	float			c_im;
	float           scale;
	float           sx;
	float           sy;
	t_img			*rend;
	t_gpu			*gpu;
}					t_frac;


t_frac				*structdup(t_frac *fr, int max_row, int max_col);
const char			*mandy_str(void);
t_gpu				*fractInit(t_gpu *gpu);
void				ft_error(int err);
void				colors(t_frac fr, int col, int row);
void				mand_colors(t_frac fr);
int                 mand_init(int b, int x, int y, t_frac fr);
int                 mandy(t_frac fr);
int                jules(t_frac fr);

#endif
