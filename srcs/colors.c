/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <ssalaues@student.42.us.org       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 14:13:18 by ssalaues          #+#    #+#             */
/*   Updated: 2017/06/24 14:13:20 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"
//
// #include "mlx_rgb.c"
// mlx_col[(int)floor(fr.iter)].color



float	lip(float v0, float v1, float t)
{
	return (v0 + t * (v1 - v0));
}

void	colors2(t_frac fr)
{
	double log_zn;
	double nu;
	#include "mlx_rgb.c"
	if (fr.iter < MAX)
	{
		log_zn = log(pow(fr.x, 2) + pow(fr.y, 2)) / 2;
		nu = log(log_zn / log(2)) / log(2);
		fr.iter = fr.iter + 1 - nu;
		mlx_pixel_put(fr.rend->mlx, fr.rend->win, fr.col, fr.row, lip(mlx_col[(int)floor(fr.iter)].color, mlx_col[(int)floor(fr.iter) + 1].color, fr.iter % 1));
	}
	else
		mlx_pixel_put(fr.rend->mlx, fr.rend->win, fr.col, fr.row, C_1);
}

void	colors(t_frac fr, int col, int row)
{
#include "mlx_rgb.c"
    if (fr.iter < MAX)
    {
        fr.rend->image[col + row] = mlx_col[fr.iter].color;
    }
    else
		fr.rend->image[col + row] = C_1;
}
