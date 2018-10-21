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

void	init_fractol(t_fractol *params)
{
	params->mlx = mlx_init();
	params->win = mlx_new_window(params->mlx, WIDTH, HEIGHT, "Fract'ol");
	params->image = mlx_new_image(params->mlx, WIDTH, HEIGHT);
	params->image_src = (int*)mlx_get_data_addr(params->image, &params->bpp,
										&params->size_line, &params->endian);
	if (params->type == mand)
		init_mandelbrot(params);
	else if (params->type == julia)
		init_julia(params);
	else if (params->type == tricorn)
		init_tricorn(params);
	else if (params->type == celtic)
		init_celtic(params);
	else if (params->type == ship)
		init_ship(params);
	params->step_r = (params->max_r - params->min_r) / (WIDTH - 1);
	params->step_i = (params->max_i - params->min_i) / (WIDTH - 1);
}

int		ft_check_arg(char *str, t_fractol *params)
{
	if (ft_strcmp(str, "mandelbrot") == 0)
		params->type = mand;
	else if (ft_strcmp(str, "julia") == 0)
		params->type = julia;
	else if (ft_strcmp(str, "tricorn") == 0)
		params->type = tricorn;
	else if (ft_strcmp(str, "celtic") == 0)
		params->type = celtic;
	else if (ft_strcmp(str, "ship") == 0)
		params->type = ship;
	else
		params->type = other;
	return (params->type == other ? -1 : 1);
}

int		ft_usage(void)
{
	ft_printf("Usage: ./fractol <Type>\nYou can choose one of these types:\n"
	"- mandelbrot\n- julia\n- tricorn\n- celtic\n- ship\n");
	return (1);
}

int		main(int ac, char **av)
{
	t_fractol	params;

	ft_bzero(&params, sizeof(t_fractol));
	if (ac < 2 && ft_usage())
		return (0);
	if (ft_check_arg(av[1], &params) == -1 && ft_printf("Incorrect args!\n"))
		return (0);
	init_fractol(&params);
	srand(time(NULL));
	ft_make_threads(&params);
	mlx_put_image_to_window(params.mlx, params.win, params.image, 0, 0);
	mlx_mouse_hook(params.win, ft_mouse_zoom, &params);
	mlx_hook(params.win, 2, 5, ft_fractol_hooks, &params);
	mlx_hook(params.win, 6, 5, ft_mouse, &params);
	mlx_hook(params.win, 17, 1L << 17, exit_x, &params);
	mlx_loop(params.mlx);
}
