/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 20:20:52 by abodnar           #+#    #+#             */
/*   Updated: 2018/10/21 20:20:53 by abodnar          ###   ########.fr       */
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
	if (key == ESC)
		exit(1);
	else if (key == LEFT)
		hook_left(params);
	else if (key == RIGHT)
		hook_right(params);
	else if (key == UP)
		hook_up(params);
	else if (key == DOWN)
		hook_down(params);
	else if (key == SPACE)
		hook_disco(params);
	return (0);
}

void	apply_zoom(double x, double y, t_fractol *params, double zoom_factor)
{
	zoom_factor = 1.0 / zoom_factor;
	params->min_r = x + ((params->min_r - x) * zoom_factor);
	params->max_r = x + ((params->max_r - x) * zoom_factor);
	params->min_i = y + ((params->min_i - y) * zoom_factor);
	params->max_i = y + ((params->max_i - y) * zoom_factor);
}

int		ft_mouse_zoom(int key, int x, int y, t_fractol *params)
{
	double real_position;
	double img_position;

	real_position = params->min_r + (double)x * params->step_r;
	img_position = params->min_i + (double)y * params->step_i;
	if (key == ZOOM_IN)
		apply_zoom(real_position, img_position, params, 1.1);
	else if (key == ZOOM_OUT)
		apply_zoom(real_position, img_position, params, 1 / 1.1);
	params->step_r = (params->max_r - params->min_r) / (WIDTH - 1);
	params->step_i = (params->max_i - params->min_i) / (WIDTH - 1);
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
