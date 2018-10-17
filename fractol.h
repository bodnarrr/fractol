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
# include <pthread.h>

# define WIDTH		800
# define HEIGHT		800
# define MAX_ITER	50
# define THREADS 	4

typedef enum	e_fractol_type
{
	mand = 0,
	julia,
	other,
}				t_fractol_type;

typedef struct		s_fractol
{
	void			*mlx;
	void			*win;
	void			*image;
	int				*image_src;
	int				bpp;
	int				size_line;
	int				endian;
	double			d_real_julia;
	double			d_img_julia;
	bool			is_julia;
	t_fractol_type	type;

	double			min_real;
	double			max_real;
	double			min_img;
	double			max_img;

	double 			step_real;
	double			step_img;
	double			zoom;
	double			shift_real;
	double			shift_img;
}					t_fractol;

typedef struct	s_calc
{
	t_fractol	*params;
	int 		start_line;
	double		conts_img;

}				t_calc;



#endif
