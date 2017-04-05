#include "fract.h"
/*
int	mand_init(int b, int x, int y, t_frac fr)
{
	fr.row = 0;
	while (fr.row < fr.h)
	{
		fr.col = 0;
		b = 0;
		while (fr.col < fr.w)
		{*/
		//	fr.c_re = (fr.col - fr.w/2. /* move around*/) * 4. / fr.w * fr.scale; //mandel height
		//	fr.c_im = (fr.row - fr.h/2. /* move around*/) * 4. / fr.w * fr.scale; //mandel width
		/*	fr.x = 0;
			fr.y = 0;
			fr.iter = 0;
			while ((fr.x0 = fr.x * fr.x) + (fr.y0 = fr.y * fr.y) <= 4 && fr.iter < MAX)
			{
				fr.x0 = fr.x0 - fr.y0 + fr.c_re;
				fr.y = 2 * fr.x * fr.y + fr.c_im;
				fr.x = fr.x0;
				fr.iter++;
			}
			colors(fr);
			fr.col++;
		}
		fr.row++;
	}
    return (0);
}
*/


int	mandy(t_frac fr)
{
	fr.row = 0;
	while (fr.row < fr.h)
	{
		fr.col = 0;
		while (fr.col < fr.w)
		{
			fr.c_re = ((fr.col - 1250/* - fr.zy move around*/) * 4. / fr.w) * fr.scale; //mandel height
			fr.c_im = ((fr.row - 500/* - fr.zx move around*/) * 4. / fr.w) * fr.scale; //mandel width
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
			colors(fr);
			fr.col++;
		}
		fr.row++;
	}
	return (0);
}
