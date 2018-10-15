/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 15:23:26 by abodnar           #+#    #+#             */
/*   Updated: 2018/09/23 15:23:27 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libftprintf/libftprintf.h"
# include "minilibx_macos/mlx.h"
# include <stdio.h>
# include <stdbool.h>

# define WIDTH		800
# define HEIGHT		800
# define MAX_ITER	50

typedef struct	s_fractol
{
	void		*mlx;
	void		*win;
	void		*image;
	int			*image_src;
	int			bpp;
	int			size_line;
	int			endian;
	double		d_real;
	double 		d_img;
}				t_fractol;

typedef struct	s_mandelbrot_calculation
{
	float		min_real;
	float		max_real;
	float		min_img;
	float		max_img;
	float		step_real;
	float		step_img;

}				t_mandelbrot_calculation;

enum			e_fractol_type
{
	mand = 0,
	julia,
	other,
};

#endif
