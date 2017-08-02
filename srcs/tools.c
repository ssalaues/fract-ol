/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalaues <ssalaues@student.42.us.org       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 14:14:11 by ssalaues          #+#    #+#             */
/*   Updated: 2017/06/24 14:14:13 by ssalaues         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void	ft_error(int err)
{
	if (err == 3)
		ft_putstr("Error 3: Failed to create a device group!\n");
	if (err == 4)
		ft_putstr("Error 4: Failed to create a compute context!\n");
	if (err == 5)
		ft_putstr("Error 5: Failed to create a command commands!\n");
	if (err == 6)
		ft_putstr("Error 6: Failed to create the computer program!\n");
	if (err == 7)
		ft_putstr("Error 7: Failed to build program executable!\n");
	if (err == 8)
		ft_putstr("Error 8: Failed to allocate device memory!\n");
	if (err == 9)
		ft_putstr("Error 9: Failed to write to source array!\n");
	if (err == 10)
		ft_putstr("Error 10: Failed to set kernel arguments!\n");
	exit(err);
}

t_gpu	*devInit(t_gpu *gpu)
{
	const char *KernelSource = mandy_str();
	int test = 0;
	if (CL_SUCCESS != (gpu->err = clGetDeviceIDs(NULL, 1, 1, &gpu->device_id, NULL))) // connect compute device
		ft_error(3);
	if (!(gpu->context = clCreateContext(0, 1, &(gpu->device_id), NULL, NULL, &gpu->err))) // create a compute context
		ft_error(4);
	if (!(gpu->commands = clCreateCommandQueue(gpu->context, gpu->device_id, 0, &gpu->err))) // create a command comands
		ft_error(5);
	if (!(gpu->program = clCreateProgramWithSource(gpu->context, 1, &KernelSource, NULL, &gpu->err))) // create the compute porgram from the source buffer
		ft_error(6);
	if (CL_SUCCESS != (test = clBuildProgram(gpu->program, 0, NULL, NULL, NULL, NULL))) // create the compute kernel in the program we want to run
	{    // Determine the size of the log
		size_t log_size;
		clGetProgramBuildInfo(gpu->program, gpu->device_id, CL_PROGRAM_BUILD_LOG, 0, NULL, &log_size);
		
		// Allocate memory for the log
		char *log = (char *) malloc(log_size);
		
		// Get the log
		clGetProgramBuildInfo(gpu->program, gpu->device_id, CL_PROGRAM_BUILD_LOG, log_size, log, NULL);
		
		// Print the log
		printf("%s\n", log);
		ft_error(7);
	}
	gpu->input = clCreateBuffer(gpu->context, CL_MEM_READ_ONLY, T_W * T_H, NULL, NULL); // create input output array in device memory for calc
	gpu->output = clCreateBuffer(gpu->context, CL_MEM_WRITE_ONLY, T_W * T_H, NULL, NULL); //
	if (!gpu->input || !gpu->output)
		ft_error(8);
	gpu->dq = gcl_create_dispatch_queue(CL_DEVICE_TYPE_USE_ID, gpu->device_id);
	if (!gpu->dq)
	{
		fprintf(stdout, "Unable to create a GPU-based dispatch queue.\n");
		exit(1);
	}
	return (gpu);
}

void	fractInit(t_frac *fr, t_gpu *gpu)

{
	int err;
	
	err = clEnqueueWriteBuffer(gpu->commands, gpu->input, CL_TRUE, 0, gpu->count, fr->rend->image, 0, NULL, NULL);
	if (err != CL_SUCCESS)
		ft_error(9);
	err = 0;
	err = clSetKernelArg(gpu->kernel, 0, sizeof(cl_mem), &gpu->input);
	err	|= clSetKernelArg(gpu->kernel, 1, sizeof(cl_mem), &gpu->output);
	err	|= clSetKernelArg(gpu->kernel, 2, sizeof(unsigned int), &gpu->count);
	if (err != CL_SUCCESS)
		ft_error(10);
}

t_frac	*imageinit(t_frac *fr)
{
	return(fr);
}

t_frac	*storeval(t_frac *fr)
{
	return (fr);
}

t_frac *structdup(t_frac *fr, int max_row, int max_col)
{
    t_frac *new;
	
	new = (t_frac*)ft_memalloc(sizeof(t_frac));
    new->row = max_row - 200;
	new->max_row = max_row;
	new->max_col = max_col;
    new->col = fr->col;
	new->h = fr->h;
    new->w = fr->w;
    new->iter = fr->iter;
    new->min = fr->min;
    new->max = fr->max;
    new->rgb = fr->rgb;
    new->x = fr->x;
	new->zx = fr->zx;
    new->zx2 = fr->zx2;
    new->x0 = fr->x0;
    new->y = fr->y;
    new->zy = fr->zy;
    new->zy2 = fr->zy2;
    new->y0 = fr->y0;
    new->c_re = fr->c_re;
    new->c_im = fr->c_im;
    new->scale = fr->scale;
    new->sx = fr->sx;
    new->sy = fr->sy;
	new->rend = fr->rend;
//    new->mlx = fr->mlx;
//    new->win = fr->win;

    return(new);
}
