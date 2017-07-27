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

int	fr_tp(t_frac *fr)
{
	t_tp_thread *tp;
	t_job_type	*j1;
	t_job_type	*j2;
	t_job_type	*j3;
	t_job_type	*j4;
	
	tp = ft_tp_create(4);
	j1 = (t_job_type*)malloc(sizeof(*j1));
	j1->data = (void*)structdup(fr, 200, 400);
	j2 = (t_job_type*)malloc(sizeof(*j2));
	j2->data = (void*)structdup(fr, 400, 800);
	j3 = (t_job_type*)malloc(sizeof(*j3));
	j3->data = (void*)structdup(fr, 600, 1200);
	j4 = (t_job_type*)malloc(sizeof(*j4));
	j4->data = (void*)structdup(fr, 800, 1600);
	
	ft_tp_add_task(tp, &mandy1, j1);
	ft_tp_add_task(tp, &mandy1, j2);
	ft_tp_add_task(tp, &mandy1, j3);
	ft_tp_add_task(tp, &mandy1, j4);
	
	ft_tp_wait_for_queue(tp);
	mlx_put_image_to_window(fr->rend->win, fr->rend->mlx, fr->rend->image, 0, 0);
	return (0);
}

int key_h(int kc, t_frac *fr)
{
	if (kc == KEY_ESCAPE)
		exit(0);
	if (kc == KEY_LEFT)
		jules(*fr);
	//mandy(*fr);
	fr_tp(fr);
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
		fr_tp(fr);
	}
	return (0);
}

int	main(void)
{
	t_frac fr;
	
	fr.rend = (t_img*)ft_memalloc(sizeof(t_img));
	fr.h = T_H;
	fr.w = T_W;
    fr.zx = T_W;
    fr.zy = T_H;
	fr.scale = 1.;
	fr.rend->mlx = mlx_init();
	fr.rend->win = mlx_new_window(fr.rend->mlx, fr.w, fr.h, "Fract'ol");
	mlx_mouse_hook(fr.rend->win, &mouse_h, &fr);
	mlx_key_hook(fr.rend->win, &key_h, &fr);
	//mlx_expose_hook(fr.win, &mandy, &fr);
	//mandy(fr);
	fr_tp(&fr);
	mlx_loop(fr.rend->mlx);
}
