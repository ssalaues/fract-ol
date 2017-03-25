/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 15:09:37 by ssalaues          #+#    #+#             */
/*   Updated: 2017/03/24 18:16:11 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	b_draw(t_fdf fdf, t_line l)
{
	while (l.x <= fdf.x1)
	{
		if (l.stp)
			mlx_pixel_put(fdf.mlx, fdf.win, l.y + X_OFF, l.x + Y_OFF, C_3);
		else if (fdf.h)
			mlx_pixel_put(fdf.mlx, fdf.win, l.x + X_OFF, l.y + Y_OFF, C_2);
		else if (!fdf.h)
			mlx_pixel_put(fdf.mlx, fdf.win, l.x + X_OFF, l.y + Y_OFF, C_1);
		l.err += l.derr;
		if (l.err > l.dx)
		{
			l.y += (fdf.y1 > fdf.y0 ? 1 : -1);
			l.err -= l.dx << 1;
		}
		l.x++;
	}
}

void	b_line(t_fdf fdf)
{
	t_line l;

	l.stp = 0;
	if (ft_abs(fdf.x0 - fdf.x1) < ft_abs(fdf.y0 - fdf.y1))
	{
		ft_swap(&fdf.x0, &fdf.y0);
		ft_swap(&fdf.x1, &fdf.y1);
		l.stp = 1;
	}
	if (fdf.x0 > fdf.x1)
	{
		ft_swap(&fdf.x0, &fdf.x1);
		ft_swap(&fdf.y0, &fdf.y1);
	}
	l.dx = fdf.x1 - fdf.x0;
	l.dy = fdf.y1 - fdf.y0;
	l.derr = ft_abs(l.dy) << 1;
	l.err = 0;
	l.y = fdf.y0;
	l.x = fdf.x0;
	b_draw(fdf, l);
}

void	calc_xy(t_fdf fdf)
{
	fdf.x0 = ((fdf.i * T_W) + (fdf.j * T_H));
	fdf.y0 = ((fdf.j * T_H) >> 1) - (((fdf.i * T_W) + (T_W * fdf.h)) >> 1);
	if (fdf.i < fdf.x - 1)
	{
		fdf.x1 = ((fdf.i + 1) * T_W) + (fdf.j * T_H);
		fdf.y1 = ((fdf.j * T_H) >> 1) - ((((fdf.i + 1) * T_W)
		+ (T_W * fdf.ary[fdf.j][fdf.i + 1])) >> 1);
		b_line(fdf);
	}
	if (fdf.j < fdf.y - 1)
	{
		fdf.x1 = (fdf.i * T_W) + ((fdf.j + 1) * T_H);
		fdf.y1 = (((fdf.j + 1) * T_H) >> 1) - (((fdf.i * T_W)
		+ (T_H * fdf.ary[fdf.j + 1][fdf.i])) >> 1);
		b_line(fdf);
	}
}

int		graphics(t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx, fdf->win);
	mlx_string_put(fdf->mlx, fdf->win, 125, 30, C_1, fdf->file);
	mlx_string_put(fdf->mlx, fdf->win, 15, 30, C_2, "Wireframe:");
	mlx_string_put(fdf->mlx, fdf->win, 35, 45, C_3, "Zoom in: Z key");
	if (fdf->t_s == 36)
		mlx_string_put(fdf->mlx, fdf->win, 915, 45, C_4, "MAX SIZE REACHED");
	if (fdf->t_s == 4)
		mlx_string_put(fdf->mlx, fdf->win, 915, 45, C_4, "MIN SIZE REACHED");
	mlx_string_put(fdf->mlx, fdf->win, 25, 60, C_3, "Zoom out: O key");
	mlx_string_put(fdf->mlx, fdf->win, 65, 75, C_3, "Move: Arrow Keys");
	mlx_string_put(fdf->mlx, fdf->win, 65, 90, C_3, "Quit: ESC");
	fdf->j = 0;
	while (fdf->j < fdf->y)
	{
		fdf->i = 1;
		while (fdf->i < fdf->x)
		{
			fdf->h = fdf->ary[fdf->j][fdf->i];
			calc_xy(*fdf);
			fdf->i++;
		}
		fdf->j++;
	}
	return (0);
}
