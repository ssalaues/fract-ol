#include "fract.h"
int key_h(int kc, t_frac *fr)
{
        if (kc == KEY_ESCAPE)
            exit(0);
    printf("keycode:%d\n", kc);
    return (0);
}

int	main(void)
{
	t_frac fr;

	fr.h = 1000;
	fr.w = 2000;
	fr.mlx = mlx_init();
	fr.win = mlx_new_window(fr.mlx, fr.w, fr.h, "Fract'ol");
    mand_init(fr);
	mlx_loop(fr.mlx);
}
