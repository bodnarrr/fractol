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

double	ft_mandelbrot_iterations(double x, double y)
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
			return ((double)i / 50);
		y = 2 * x * y + y_saved;
		x = x_new - y_new + x_saved;
	}
	return (1.0);
}

double	ft_julia_iterations(double x, double y, t_fractol *params)
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
			return ((double)i / 50);
		y = 2 * x * y + params->d_img_julia;
		x = x_new - y_new + params->d_real_julia;
	}
	return (1.0);
}

void	init_base_mandelbrot(t_mandelbrot_calculation *calc, t_fractol_type type)
{
	ft_bzero(calc, sizeof(t_mandelbrot_calculation));
	calc->min_img = -1.5;
	calc->max_img = 1.5;
	if (type == 0)
	{
		calc->min_real = -2;
		calc->max_real = 1;
	}
	else if (type == 1)
	{
		calc->min_real = -1.5;
		calc->max_real = 1.5;
	}
	calc->step_real = (calc->max_real - calc->min_real) / (WIDTH - 1);
	calc->step_img = (calc->max_img - calc->min_img) / (HEIGHT - 1);
}

void	calc_mandelbrot(t_fractol *params, t_fractol_type type)
{
	int							i;
	int							j;
	int							k;
	int							color;
	t_mandelbrot_calculation	calc;

	init_base_mandelbrot(&calc, type);
	i = -1;
	k = 0;
	color = 0;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
		{
			if (type == 0)
				color = (int)(ft_mandelbrot_iterations(calc.min_real +
					j * calc.step_real, calc.min_img +
					i * calc.step_img) * 255);
			else if (type == 1)
				color = (int)(ft_julia_iterations(calc.min_real +
					j * calc.step_real, calc.min_img +
					i * calc.step_img, params) * 255);
			params->image_src[k++] = ((color / 6) << 16) | (((color * 5) % 255) << 8) | ((color * 8) % 255);
		}
	}
}

int 	ft_mouse_zoom(int key, int x, int y, t_fractol *params)
{
	(void)key;
	(void)x;
	(void)y;
	(void)params;
	ft_printf("Click!\n");
	return (0);
}

int 	ft_mouse(int x, int y, t_fractol *params)
{
	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		params->d_real_julia = -1.8 + (double)x / WIDTH * 2.4;
		params->d_img_julia = -0.4 + (double)y / WIDTH * 2.0;
		mlx_clear_window(params->mlx, params->win);
		calc_mandelbrot(params, julia);
		mlx_put_image_to_window(params->mlx, params->win, params->image, 0, 0);
	}
	return (0);
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
	if (ft_strcmp(str, "m") == 0)
		params->type = mand;
	else if (ft_strcmp(str, "j") == 0)
		params->type = julia;
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


	if (ft_strcmp(av[1], "m") == 0)
		calc_mandelbrot(&all_params, mand);
	else if (ft_strcmp(av[1], "j") == 0)
		calc_mandelbrot(&all_params, julia);
	mlx_put_image_to_window(all_params.mlx, all_params.win, all_params.image, 0, 0);
	mlx_mouse_hook(all_params.win, ft_mouse_zoom, &all_params);
	mlx_hook(all_params.win, 2, 5, ft_fractol_hooks, &all_params);
	mlx_hook(all_params.win, 6, 5, ft_mouse, &all_params);
	mlx_hook(all_params.win, 17, 1L << 17, exit_x, &all_params);
	mlx_loop(all_params.mlx);
}


