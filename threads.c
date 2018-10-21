/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 20:33:17 by abodnar           #+#    #+#             */
/*   Updated: 2018/10/21 20:33:18 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					route_iterations(t_thread_info *inf, int i, int j)
{
	int				channel;

	channel = 0;
	if (inf->prm->type == mand)
		channel = ft_mandelbrot_iterations(inf->prm->min_r + inf->prm->step_r
		* j, inf->prm->min_i + inf->prm->step_i * (i + inf->strt));
	else if (inf->prm->type == julia)
		channel = ft_julia_iterations(inf->prm->min_r + inf->prm->step_r * j,
		inf->prm->min_i + inf->prm->step_i * (i + inf->strt), inf->prm);
	else if (inf->prm->type == tricorn)
		channel = ft_tricorn_iterations(inf->prm->min_r + inf->prm->step_r * j,
		inf->prm->min_i + inf->prm->step_i * (i + inf->strt));
	else if (inf->prm->type == celtic)
		channel = ft_celtic_iterations(inf->prm->min_r + inf->prm->step_r * j,
		inf->prm->min_i + inf->prm->step_i * (i + inf->strt));
	else if (inf->prm->type == ship)
		channel = ft_ship_iterations(inf->prm->min_r + inf->prm->step_r * j,
		inf->prm->min_i + inf->prm->step_i * (i + inf->strt));
	return (channel);
}

void				thread_operation(t_thread_info *inf)
{
	int				i;
	int				j;
	int				image_index;
	int				channel;

	i = -1;
	image_index = inf->strt * WIDTH;
	while (++i < HEIGHT / THREADS)
	{
		j = -1;
		while (++j < WIDTH)
		{
			channel = route_iterations(inf, i, j);
			channel = (((channel + inf->prm->red) % 255) << 16) |
					(((channel + inf->prm->green) % 255) << 8) |
					((channel + inf->prm->blue) % 255);
			inf->prm->image_src[image_index++] = channel;
		}
	}
}

void				ft_make_threads(t_fractol *params)
{
	pthread_t		threads[THREADS];
	t_thread_info	calculations[THREADS];
	int				i;

	i = -1;
	while (++i < THREADS)
	{
		calculations[i].prm = params;
		calculations[i].strt = (HEIGHT / THREADS) * i;
		pthread_create(&threads[i], NULL, (void *(*)(void *))thread_operation,
					(void *)&calculations[i]);
	}
	while (--i >= 0)
		pthread_join(threads[i], (void **)&params->for_threads);
}
