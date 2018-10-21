/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteration_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 19:58:06 by abodnar           #+#    #+#             */
/*   Updated: 2018/10/21 19:58:07 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_ship_iterations(double x, double y)
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
			return ((int)(((double)i / 50) * MAX_COLOR));
		y = -2 * x * fabs(y) + y_saved;
		x = x_new - y_new + x_saved;
	}
	return (MAX_COLOR);
}

int		ft_celtic_iterations(double x, double y)
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
			return ((int)(((double)i / 50) * MAX_COLOR));
		y = 2 * x * y + y_saved;
		x = fabs(x_new - y_new) + x_saved;
	}
	return (MAX_COLOR);
}

int		ft_tricorn_iterations(double x, double y)
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
			return ((int)(((double)i / 50) * MAX_COLOR));
		y = -2 * x * y + y_saved;
		x = x_new - y_new + x_saved;
	}
	return (MAX_COLOR);
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
			return ((int)(((double)i / 50) * MAX_COLOR));
		y = 2 * x * y + params->d_img_julia;
		x = x_new - y_new + params->d_real_julia;
	}
	return (MAX_COLOR);
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
			return ((int)(((double)i / 50) * MAX_COLOR));
		y = 2 * x * y + y_saved;
		x = x_new - y_new + x_saved;
	}
	return (MAX_COLOR);
}
