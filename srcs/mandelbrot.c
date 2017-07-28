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

int	mandy(t_frac fr)
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
			//fr.image;
			fr.col++;
		}
		fr.row++;
	}
	return (0);
}

const char	*mandy_str(void)
{
	return ("const sampler_t sampler = CLK_NORMALIZED_COORDS_FLASE | CLK_FILTER_NEAREST;\n" \
			"kernel void mandelbrot(write_only image2d_t output, float width, float height, int iter) {\n" \
				"size_t x = get_global_id(0);\n" \
				"size_t y = get_global_id(1);\n" \
				"\n" \
				"float2 z, c;\n" \
				"\n" \
				"c.x = (float)width / (float)height * ((float)x / width - 0.5) * 2.2 - 0.7;\n" \
				"c.y = ((float)y / height - 0.5) * 2.2 - 0.0;\n" \
				"\n" \
				"int i;\n" \
				"z = c;\n" \
				"for(i = 0; i < iter; i++) {\n" \
				"	float x = (z.x * z.x - z.y * z.y) + c.x;\n" \
				"	float y = (z.y * z.x + z.x * z.y) + c.y;\n" \
				"\n" \
				"	if((x * x + y * y) > 4.0) break;\n" \
				"	z.x = x;\n" \
				"	z.y = y;\n" \
				"}\n" \
				"\n" \
				"float p = (float)i / (float)iter;\n" \
				"float so = sin(p * 3.141592653) * 255.0;\n" \
				"float co = (1 - cos(p * 3.141592653)) * 255.0;\n" \
				"\n" \
				"write_imageui(output, (int2)(x,y), (uint4)((uint)co, co, (uint)(co + so), 255));\n" \
			"}\n");
}
