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
# include <math.h>

# define WIDTH		800
# define HEIGHT		800
# define MAX_ITER	50
# define THREADS 	8

# define ZOOM_IN	4
# define ZOOM_OUT	5
# define ESC		53
# define UP			126
# define DOWN		125
# define LEFT		123
# define RIGHT		124
# define SPACE		49

# define MAX_COLOR	255

typedef enum		e_fractol_type
{
	mand,
	julia,
	tricorn,
	celtic,
	ship,
	other
}					t_fractol_type;

typedef struct		s_fractol
{
	void			*mlx;
	void			*win;
	void			*image;
	int				*image_src;
	int				bpp;
	int				size_line;
	int				endian;
	int				*for_threads;
	double			d_real_julia;
	double			d_img_julia;
	double			min_r;
	double			max_r;
	double			min_i;
	double			max_i;
	double			step_r;
	double			step_i;
	t_fractol_type	type;
	int 			red;
	int 			green;
	int 			blue;
	bool			is_julia;
}					t_fractol;

typedef struct		s_thread_info
{
	t_fractol		*prm;
	int				strt;
}					t_thread_info;

void				init_mandelbrot(t_fractol *params);
void				init_julia(t_fractol *params);
void				init_tricorn(t_fractol *params);
void				init_celtic(t_fractol *params);
void				init_ship(t_fractol *params);

int					ft_mandelbrot_iterations(double x, double y);
int					ft_julia_iterations(double x, double y, t_fractol *params);
int					ft_tricorn_iterations(double x, double y);
int					ft_celtic_iterations(double x, double y);
int					ft_ship_iterations(double x, double y);

void				ft_make_threads(t_fractol *params);

int					exit_x(void *par);
int					ft_fractol_hooks(int key, t_fractol *params);
int					ft_mouse_zoom(int key, int x, int y, t_fractol *params);
int					ft_mouse(int x, int y, t_fractol *params);

void				thread_operation(t_thread_info *inf);
void				ft_make_threads(t_fractol *params);

void				hook_left(t_fractol *params);
void				hook_right(t_fractol *params);
void				hook_up(t_fractol *params);
void				hook_down(t_fractol *params);
void				hook_disco(t_fractol *params);

#endif
