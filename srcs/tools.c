/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <ssalaues@student.42.us.org       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 14:14:11 by ssalaues          #+#    #+#             */
/*   Updated: 2017/06/24 14:14:13 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	error(int err)
{
	if (err == 3)
	{
		ft_putstr("Error 3: Failed to create a device group\n");
		exit(3);
	}
}

void	fractInit(void)
{
	cl_device_id device id;
	if (!(clGetDeviceIDs(NULL, 1, 1, &device_id, NULL))
		{
			
		}
}

t_frac	*imageinit(t_frac *fr)
{
	return(fr);
}

t_frac	*storeval(t_frac *fr)
{
	return (fr);
}

t_frac *structdup(t_frac *fr, int max_row, int max_col)
{
    t_frac *new;
	
	new = (t_frac*)ft_memalloc(sizeof(t_frac));
    new->row = max_row - 200;
	new->max_row = max_row;
	new->max_col = max_col;
    new->col = fr->col;
	new->h = fr->h;
    new->w = fr->w;
    new->iter = fr->iter;
    new->min = fr->min;
    new->max = fr->max;
    new->rgb = fr->rgb;
    new->x = fr->x;
	new->zx = fr->zx;
    new->zx2 = fr->zx2;
    new->x0 = fr->x0;
    new->y = fr->y;
    new->zy = fr->zy;
    new->zy2 = fr->zy2;
    new->y0 = fr->y0;
    new->c_re = fr->c_re;
    new->c_im = fr->c_im;
    new->scale = fr->scale;
    new->sx = fr->sx;
    new->sy = fr->sy;
	new->rend = fr->rend;
//    new->mlx = fr->mlx;
//    new->win = fr->win;

    return(new);
}
