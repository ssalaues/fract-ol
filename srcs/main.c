#include "fract.h"

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
