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
		mlx_pixel_put(fr.mlx, fr.win, fr.col, fr.row, lip(mlx_col[(int)floor(fr.iter)].color, mlx_col[(int)floor(fr.iter) + 1].color, fr.iter % 1));
	}
	else
		mlx_pixel_put(fr.mlx, fr.win, fr.col, fr.row, C_1);
}

void	colors(t_frac fr)
{
    double log_zn;
    double nu;
#include "mlx_rgb.c"
    if (fr.iter < MAX)
    {
        log_zn = log(pow(fr.x, 2) + pow(fr.y, 2)) / 2;
        nu = log(log_zn / log(2)) / log(2);
        fr.iter = fr.iter + 1 - nu;
        mlx_pixel_put(fr.mlx, fr.win, fr.col, fr.row, mlx_col[fr.iter].color);
    }
    else
        mlx_pixel_put(fr.mlx, fr.win, fr.col, fr.row, C_1);
}
