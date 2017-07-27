/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <ssalaues@student.42.us.org       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 14:13:48 by ssalaues          #+#    #+#             */
/*   Updated: 2017/06/24 14:13:51 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int	mandy(t_frac fr, __global unsigned char *input, __global unsigned char *output)
{
	fr.row = 0;
	while (fr.row < fr.h)
	{
		fr.col = 0;
		while (fr.col < fr.w)
		{
			fr.c_re = ((fr.col - fr.zx/*translate*/) * 4. / fr.w) * fr.scale; //mandel height
			fr.c_im = ((fr.row - fr.zy/*translate*/) * 4. / fr.w) * fr.scale; //mandel width
			fr.x = 0;
			fr.y = 0;
			fr.iter = 0;
			while ((fr.x0 = fr.x * fr.x) + (fr.y0 = fr.y * fr.y) <= 4 && fr.iter < MAX)
			{
				fr.x0 = fr.x0 - fr.y0 + fr.c_re;
				fr.y = 2 * fr.x * fr.y + fr.c_im;
				fr.x = fr.x0;
				fr.iter++;
			}
			//colors(fr); // Need to load all the values into memory and then put image
			fr.image
			fr.col++;
		}
		fr.row++;
	}
	return (0);
}
