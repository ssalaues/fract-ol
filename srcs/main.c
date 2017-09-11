/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <ssalaues>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 14:11:19 by ssalaues          #+#    #+#             */
/*   Updated: 2017/06/24 14:13:08 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"


int key_h(int kc, t_frac *fr)
{
	if (kc == KEY_ESCAPE)
		exit(0);
	if (kc == KEY_LEFT)
		jules(*fr);
	//mandy(*fr);
	//fr_tp(fr);
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
		//mandy(*fr);
		//fr_tp(fr);
	}
	return (0);
}



int	main(void)
{
	t_frac	fr;
	t_gpu	gpu;
	
	fr.h = T_H;
	fr.w = T_W;
	fr.zx = T_W;
	fr.zy = T_H;
	gpu.count = T_H * T_W * sizeof(unsigned int);
	fr.rend = (t_img*)ft_memalloc(sizeof(t_img));
//	fr.rend->image = (unsigned int *)ft_memalloc(gpu.count);
	fr.gpu = (t_gpu*)ft_memalloc(sizeof(t_gpu));
	fr.gpu = devInit(&gpu);
	fr.scale = 1.;
	fr.rend->mlx = mlx_init();
	fr.rend->win = mlx_new_window(fr.rend->mlx, fr.w, fr.h, "Fract'ol");
	fr.rend->image = mlx_new_image(fr.rend->mlx, 1920, 1080);
	for (int i = 0; i < gpu.count; i++)
	{
		ft_putnbr(fr.rend->image[i]);
		ft_putchar('\n');
	}
	mlx_mouse_hook(fr.rend->win, &mouse_h, &fr);
	mlx_key_hook(fr.rend->win, &key_h, &fr);
	mlx_put_image_to_window(fr.rend->mlx, fr.rend->win, fr.rend->image, 0, 0);
	
	//mlx_expose_hook(fr.win, &mandy, &fr);
	//mandy(fr);
	mlx_loop(fr.rend->mlx);
}
