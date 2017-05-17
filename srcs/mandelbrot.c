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
			colors(fr); // Need to load all the values into memory and then put image
			fr.col++;
		}
		fr.row++;
	}
	return (0);
}

void	*mandy1(void *data)
{
	t_frac	*fr;
	
	fr = data;
	//fr->row = fr->max_row - 200;
	while (fr->row < fr->max_row)
	{
		fr->col = 0;
		while (fr->col < fr->max_col)
		{
			fr->c_re = ((fr->col - fr->zx/*translate*/) * 4. / fr->w) * fr->scale; //mandel height
			fr->c_im = ((fr->row - fr->zy/*translate*/) * 4. / fr->w) * fr->scale; //mandel width
			fr->x = 0;
			fr->y = 0;
			fr->iter = 0;
			while ((fr->x0 = fr->x * fr->x) + (fr->y0 = fr->y * fr->y) <= 4 && fr->iter < MAX)
			{
				fr->x0 = fr->x0 - fr->y0 + fr->c_re;
				fr->y = 2 * fr->x * fr->y + fr->c_im;
				fr->x = fr->x0;
				fr->iter++;
			}
			colors(*fr);// Need to load all the values into memory and then put image
			fr->col++;
		}
		fr->row++;
	}
	return (NULL);
}

void	*mandy2(void *data)
{
	t_frac	*fr;
	
	fr = data;
	fr->row = 200;
	while (fr->row < 400)
	{
		fr->col = 400;
		while (fr->col < 800)
		{
			fr->c_re = ((fr->col - fr->zx/*translate*/) * 4. / fr->w) * fr->scale; //mandel height
			fr->c_im = ((fr->row - fr->zy/*translate*/) * 4. / fr->w) * fr->scale; //mandel width
			fr->x = 0;
			fr->y = 0;
			fr->iter = 0;
			while ((fr->x0 = fr->x * fr->x) + (fr->y0 = fr->y * fr->y) <= 4 && fr->iter < MAX)
			{
				fr->x0 = fr->x0 - fr->y0 + fr->c_re;
				fr->y = 2 * fr->x * fr->y + fr->c_im;
				fr->x = fr->x0;
				fr->iter++;
			}
			colors(*fr); // Need to load all the values into memory and then put image
			fr->col++;
		}
		fr->row++;
	}
	return (NULL);
}

void	*mandy3(void *data)
{
	t_frac	*fr;
	
	fr = data;
	fr->row = 400;
	while (fr->row < 600)
	{
		fr->col = 800;
		while (fr->col < 1200)
		{
			fr->c_re = ((fr->col - fr->zx/*translate*/) * 4. / fr->w) * fr->scale; //mandel height
			fr->c_im = ((fr->row - fr->zy/*translate*/) * 4. / fr->w) * fr->scale; //mandel width
			fr->x = 0;
			fr->y = 0;
			fr->iter = 0;
			while ((fr->x0 = fr->x * fr->x) + (fr->y0 = fr->y * fr->y) <= 4 && fr->iter < MAX)
			{
				fr->x0 = fr->x0 - fr->y0 + fr->c_re;
				fr->y = 2 * fr->x * fr->y + fr->c_im;
				fr->x = fr->x0;
				fr->iter++;
			}
			colors(*fr);// Need to load all the values into memory and then put image
			fr->col++;
		}
		fr->row++;
	}
	return (NULL);
}

void	*mandy4(void *data)
{
	t_frac	*fr;
	
	fr = data;
	fr->row = 600;
	while (fr->row < fr->h)
	{
		fr->col = 1200;
		while (fr->col < fr->w)
		{
			fr->c_re = ((fr->col - fr->zx/*translate*/) * 4. / fr->w) * fr->scale; //mandel height
			fr->c_im = ((fr->row - fr->zy/*translate*/) * 4. / fr->w) * fr->scale; //mandel width
			fr->x = 0;
			fr->y = 0;
			fr->iter = 0;
			while ((fr->x0 = fr->x * fr->x) + (fr->y0 = fr->y * fr->y) <= 4 && fr->iter < MAX)
			{
				fr->x0 = fr->x0 - fr->y0 + fr->c_re;
				fr->y = 2 * fr->x * fr->y + fr->c_im;
				fr->x = fr->x0;
				fr->iter++;
			}
			colors(*fr);// Need to load all the values into memory and then put image
			fr->col++;
		}
		fr->row++;
	}
	return (NULL);
}
