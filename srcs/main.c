#include "fract.h"
int key_h(int kc, t_frac *fr)
{
	if (kc == KEY_ESCAPE)
		exit(0);
	if (kc == KEY_LEFT)
		jules(*fr);
	mandy(*fr);
    printf("keycode:%d\n", kc);
    return (0);
}

int	mouse_h(int b, int x, int y, t_frac *fr)
{
	if (b)
		printf("button: %d X: %d Y: %d\n", b, x, y);
	if (b == 1 || b == 2)
	{
		fr->zy += 500 - y; //working one
		fr->zx += 1250 - x;
		if (b == 1)
			fr->scale /= 1.1;
		if (b == 2)
			fr->scale *= 1.1;
		printf("move: %i X: %f Y: %f\n", b, fr->zx, fr->zy);
		mandy(*fr);
	}
	return (0);
}

int	main(void)
{
	t_frac fr;

	fr.h = 500;
	fr.w = 1250;
    fr.zx = 1250;
    fr.zy = 500;
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
