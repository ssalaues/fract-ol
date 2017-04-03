#include "fract.h"

void	mand_init(t_frac fr)
{
	fr.row = 0;
	while (fr.row < fr.h)
	{
		fr.col = 0;
		while (fr.col < fr.w)
		{
			fr.c_re = (fr.col - fr.w/2.) * 4. / fr.w * .3; //mandel width
			fr.c_im = (fr.row - fr.h/2.) * 4. / fr.w * .37; //mandel height
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
}

void    mandy_broad(t_frac f)
{
	f.i = 0;
	f.min = MAX;
	f.max = 0;
	f.sx = 25;
	f.sy = 500;
	f.scale = 1;
	while (f.i < f.h)
	{
		f.j = 0;
		f.y = (f.row - f.h/2) * f.scale + f.sy;
		while (f.j < f.w)
		{
			f.x = (f.col - f.w  / 2) * f.scale + f.sx;
			f.zx = hypot(f.x - .25, f.y);
			if (f.x < f.zx - 2 * f.zx * f.zx + .25)
				f.iter = MAX;
			if ((f.x + 1) * (f.x + 1) + f.y * f.y < 1/16)
				f.iter = MAX;
			f.zx = f.zy = f.zx2 = f.zy2 = 0;
			while (f.zx2 + f.zy2 < 4 && f.iter < MAX)
			{
				f.zy = 2 * f.zx * f.zy + f.y;
				f.zx = f.zx2 - f.zy2 + f.x;
				f.zx2 = f.zx * f.zx;
				f.zy2 = f.zy * f.zy;
				f.iter++;
			}
			if (f.iter < f.min)
				f.min = f.iter;
			if (f.iter > f.max)
				f.max = f.iter;
		}
		mand_colors(f);
		f.j++;
	}
	f.i++;
}
