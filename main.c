/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 15:23:10 by abodnar           #+#    #+#             */
/*   Updated: 2018/09/23 15:23:13 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		exit_x(void *par);
int		ft_fractol_hooks(int key, t_fractol *params);
int		ft_mandelbrot_iterations(double x, double y);
int		ft_julia_iterations(double x, double y, t_fractol *params);
int		ft_mouse_zoom(int key, int x, int y, t_fractol *params);
int		ft_mouse(int x, int y, t_fractol *params);
void	thread_operation(t_calc *thread_info);
void	ft_make_threads(t_fractol *params);
void	init_fractol(t_fractol *params, char *str);
bool	ft_incorrect_arg(char *str);
void	apply_zoom(double x, double y, t_fractol *params, double zoom_factor);

int		exit_x(void *par)
{
	par = NULL;
	exit(1);
	return (0);
}

int		ft_fractol_hooks(int key, t_fractol *params)
{
	(void)params;
	if (key == 53)
		exit(1);
	return (0);
}

int		ft_mandelbrot_iterations(double x, double y)
{
	int		i;
	double	x_new;
	double	y_new;
	double	x_saved;
	double	y_saved;

	i = -1;
	x_saved = x;
	y_saved = y;
	while (++i < MAX_ITER)
	{
		x_new = x * x;
		y_new = y * y;
		if (x_new + y_new > 4)
			return ((int)(((double)i / 50) * 255));
		y = 2 * x * y + y_saved;
		x = x_new - y_new + x_saved;
	}
	return (255);
}

int		ft_julia_iterations(double x, double y, t_fractol *params)
{
	int		i;
	double	x_new;
	double	y_new;

	i = -1;
	while (++i < MAX_ITER)
	{
		x_new = x * x;
		y_new = y * y;
		if (x_new + y_new > 4)
			return ((int)(((double)i / 50) * 255));
		y = 2 * x * y + params->d_img_julia;
		x = x_new - y_new + params->d_real_julia;
	}
	return (255);
}

void	apply_zoom(double x, double y, t_fractol *params, double zoom_factor)
{
	zoom_factor = 1.0 / zoom_factor;
	params->min_real = x + ((params->min_real - x) * zoom_factor);
	params->max_real = x + ((params->max_real - x) * zoom_factor);
	params->min_img = y + ((params->min_img - y) * zoom_factor);
	params->max_img = y + ((params->max_img - y) * zoom_factor);
}

int		ft_mouse_zoom(int key, int x, int y, t_fractol *params)
{
	double real_position;
	double img_position;

	real_position = params->min_real + (double)x * params->step_real;
	img_position = params->min_img + (double)y * params->step_img;
	if (key == ZOOM_IN)
		apply_zoom(real_position, img_position, params, 1.1);
	else if (key == ZOOM_OUT)
		apply_zoom(real_position, img_position, params, 1 / 1.1);
	mlx_clear_window(params->mlx, params->win);
	ft_make_threads(params);
	mlx_put_image_to_window(params->mlx, params->win, params->image, 0, 0);
	return (0);
}

int		ft_mouse(int x, int y, t_fractol *params)
{
	if (params->is_julia == 1 && x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		params->d_real_julia = -1.8 + (double)x / WIDTH * 2.4;
		params->d_img_julia = -0.4 + (double)y / WIDTH * 2.0;
		mlx_clear_window(params->mlx, params->win);
		ft_make_threads(params);
		mlx_put_image_to_window(params->mlx, params->win, params->image, 0, 0);
	}
	return (0);
}

void	thread_operation(t_calc *thread_info)
{
	int		i;
	int		j;
	int		channel;
	int		image_index;

	thread_info->params->step_real =
			(thread_info->params->max_real - thread_info->params->min_real) / (WIDTH - 1);
	thread_info->params->step_img =
			(thread_info->params->max_img - thread_info->params->min_img) / (HEIGHT - 1);
	i = -1;
	channel = 0;
	image_index = thread_info->start_line * WIDTH;
	while (++i < HEIGHT / THREADS)
	{
		j = -1;
		while (++j < WIDTH)
		{
			if (thread_info->params->type == mand)
				channel = ft_mandelbrot_iterations(thread_info->params->min_real + thread_info->params->step_real * j,
				thread_info->params->min_img + thread_info->params->step_img * (i + thread_info->start_line));
			else if (thread_info->params->type == julia)
				channel = ft_julia_iterations(thread_info->params->min_real + thread_info->params->step_real * j,
				thread_info->params->min_img + thread_info->params->step_img * (i + thread_info->start_line),
				thread_info->params);
			thread_info->params->image_src[image_index++] =
					((channel << 16) | (channel << 8) | channel);
		}
	}
}

void	ft_make_threads(t_fractol *params)
{
	pthread_t	threads[THREADS];
	t_calc		calculations[THREADS];
	int			i;

	i = -1;
	while (++i < THREADS)
	{
		calculations[i].params = params;
		calculations[i].start_line = (HEIGHT / THREADS) * i;
		pthread_create(&threads[i], NULL, (void *(*)(void *))thread_operation, (void *)&calculations[i]);
	}
	while (--i >= 0)
		pthread_join(threads[i], (void **)&params->for_threads);
}

void	init_fractol(t_fractol *params, char *str)
{
	ft_bzero(params, sizeof(t_fractol));
	params->mlx = mlx_init();
	params->win = mlx_new_window(params->mlx, WIDTH, HEIGHT, "Fract'ol");
	params->image = mlx_new_image(params->mlx, WIDTH, HEIGHT);
	params->image_src = (int*)mlx_get_data_addr(params->image, &params->bpp,
												&params->size_line, &params->endian);
	params->d_real_julia = -0.4;
	params->d_img_julia = 0.6;
	params->min_img = -1.5;
	params->max_img = 1.5;
	params->zoom = 1.0;
	if (ft_strcmp(str, "m") == 0)
	{
		params->type = mand;
		params->min_real = -2;
		params->max_real = 1;
	}
	else if (ft_strcmp(str, "j") == 0)
	{
		params->type = julia;
		params->min_real = -1.5;
		params->max_real = 1.5;
		params->is_julia = 1;
	}
}

bool	ft_incorrect_arg(char *str)
{
	if (ft_strcmp(str, "m") && ft_strcmp(str, "j"))
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	t_fractol	all_params;

	if ((ac < 2 && ft_printf("No args, sorry\n"))
		|| (ft_incorrect_arg(av[1]) && ft_printf("Incorrect arg!\n")))
		return (0);
	init_fractol(&all_params, av[1]);
	ft_make_threads(&all_params);
	mlx_put_image_to_window(all_params.mlx, all_params.win, all_params.image, 0, 0);
	mlx_mouse_hook(all_params.win, ft_mouse_zoom, &all_params);
	mlx_hook(all_params.win, 2, 5, ft_fractol_hooks, &all_params);
	mlx_hook(all_params.win, 6, 5, ft_mouse, &all_params);
	mlx_hook(all_params.win, 17, 1L << 17, exit_x, &all_params);
	mlx_loop(all_params.mlx);
}
