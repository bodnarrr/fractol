/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 23:11:51 by abodnar           #+#    #+#             */
/*   Updated: 2018/10/21 23:11:53 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	hook_left(t_fractol *params)
{
	params->min_r += 0.05;
	params->max_r += 0.05;
	mlx_clear_window(params->mlx, params->win);
	ft_make_threads(params);
	mlx_put_image_to_window(params->mlx, params->win, params->image, 0, 0);
}

void	hook_right(t_fractol *params)
{
	params->min_r -= 0.05;
	params->max_r -= 0.05;
	mlx_clear_window(params->mlx, params->win);
	ft_make_threads(params);
	mlx_put_image_to_window(params->mlx, params->win, params->image, 0, 0);
}

void	hook_up(t_fractol *params)
{
	params->min_i += 0.05;
	params->max_i += 0.05;
	mlx_clear_window(params->mlx, params->win);
	ft_make_threads(params);
	mlx_put_image_to_window(params->mlx, params->win, params->image, 0, 0);
}

void	hook_down(t_fractol *params)
{
	params->min_i -= 0.05;
	params->max_i -= 0.05;
	mlx_clear_window(params->mlx, params->win);
	ft_make_threads(params);
	mlx_put_image_to_window(params->mlx, params->win, params->image, 0, 0);
}

void	hook_disco(t_fractol *params)
{
	params->red = rand();
	params->green = rand();
	params->blue = rand();
	mlx_clear_window(params->mlx, params->win);
	ft_make_threads(params);
	mlx_put_image_to_window(params->mlx, params->win, params->image, 0, 0);
}
