/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 19:54:25 by abodnar           #+#    #+#             */
/*   Updated: 2018/10/21 19:54:26 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mandelbrot(t_fractol *params)
{
	params->min_r = -2.3;
	params->max_r = 1.2;
	params->min_i = -1.5;
	params->max_i = 1.5;
}

void	init_julia(t_fractol *params)
{
	params->is_julia = 1;
	params->min_r = -1.5;
	params->max_r = 1.5;
	params->min_i = -1.5;
	params->max_i = 1.5;
	params->d_real_julia = -0.4;
	params->d_img_julia = 0.6;
}

void	init_tricorn(t_fractol *params)
{
	params->min_r = -2.3;
	params->max_r = 1.7;
	params->min_i = -2;
	params->max_i = 2;
}

void	init_celtic(t_fractol *params)
{
	params->min_r = -2.7;
	params->max_r = 1.3;
	params->min_i = -2;
	params->max_i = 2;
}

void	init_ship(t_fractol *params)
{
	params->min_r = -2.2;
	params->max_r = 1.6;
	params->min_i = -1.5;
	params->max_i = 1.5;
}
