#include "fract.h"
int key_h(int kc, t_frac *fr)
{
        if (kc == KEY_ESCAPE)
            exit(0);
	mandy(*fr);
    printf("keycode:%d\n", kc);
    return (0);
}

int	mouse_h(int b, int x, int y, t_frac *fr)
{
	fr->zx = 1;
	fr->zy = 1;
	if (b)
		printf("button: %d X: %d Y: %d\n", b, x, y);
	if (x || y)
	{
		fr->zx = x;
		fr->zx = y;
		fr->scale /= 2.;
	}
	mlx_clear_window(fr->mlx, fr->win);
	mandy(*fr);
	return (0);
}

int	main(void)
{
	t_frac fr;

	fr.h = 1000;
	fr.w = 2500;
	fr.scale = 1.;
	fr.mlx = mlx_init();
	fr.win = mlx_new_window(fr.mlx, fr.w, fr.h, "Fract'ol");
//    mand_init(fr);
//    mlx_loop_hook(fr.mlx, &mand_init, &fr);
	mlx_mouse_hook(fr.win, &mouse_h, &fr);
	mlx_key_hook(fr.win, &key_h, &fr);
	//mlx_expose_hook(fr.win, &mandy, &fr);
	mandy(fr);
	mlx_loop(fr.mlx);
}
