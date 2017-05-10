#include "frat.h"

t_frac *structdup(t_frac *fr)
{
    t_fract new;

    new.row = fr->row;
    new.col = fr->h;
    new.w = fr->row;
    new.iter = fr->iter;
    new.min = fr->min;
    new.max = fr->max;
    new.rgb = fr->rgb;
    new.x = fr->x;
    new.zx2 = fr->zx2;
    new.x0 = fr->x0;
    new.y = fr->y;
    new.zy = fr->zy;
    new.zy2 = fr->zy2;
    new.y0 = fr->y0;
    new.c_re = fr->c_re;
    new.c_im = fr->c_im;
    new.scale = fr->scale;
    new.sx = fr->sx;
    new.sy = fr->sy;
    new.mlx = fr->mlx;
    new.win = fr->win;

    return(&new);
}
