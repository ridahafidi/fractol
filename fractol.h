/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:59:24 by rhafidi           #+#    #+#             */
/*   Updated: 2025/02/26 21:47:57 by rhafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>
# include <math.h>
# include <unistd.h>

# define WIDTH 1000
# define HEIGHT 1000

typedef struct s_graph
{
	double	x_start;
	double	x_end;
	double	y_start;
	double	y_end;
}	t_graph;

typedef struct s_t_julia_c
{
	double	real;
	double	i;
}	t_julia_c;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	t_graph		graph;
	int			endian;
}	t_data;

typedef struct s_mlxdata
{
	void		*mlx_connection;
	void		*mlx_win;
	t_data		*img;
	t_julia_c	c;
}	t_mlx_data;

typedef struct s_complexnbr
{
	double	real;
	double	i;
}	t_complex_nbr;

typedef struct s_colors
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_colors;

int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			ft_putstr_fd(char *s, int fd);
int				handle_mouse_for_mandelbrot(int button, int x,
					int y, t_mlx_data *mlx);
int				handle_keys_for_mandelbrot(int keycode, t_mlx_data *mlx);
void			display_mandelbortset(t_mlx_data *mlx, t_data *img);
int				handle_destroy(t_mlx_data *mlx);
int				ft_strlen(const char *s);
int				valid_args(char *str, int i);
void			display_julia(t_mlx_data *mlx, t_data *img, t_julia_c *c);
double			ft_atoi(char *str, int i, double res_1, double res_2);
unsigned int	get_color(int iter, int max_iter);
int				handle_mouse_for_julia(int button, int x,
					int y, t_mlx_data *mlx);
int				handle_expose_for_mandelbrot(t_mlx_data *mlx);
int				handle_keys_for_julia(int keycode, t_mlx_data *mlx);
int				handle_expose_for_julia(t_mlx_data *mlx);
void			x_movement(t_mlx_data *mlx, double x_factor, int keycode);
void			y_movement(t_mlx_data *mlx, double y_factor, int keycode);
void			print_manual(void);
int				checksign(char c);

#endif