/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 22:55:36 by rhafidi           #+#    #+#             */
/*   Updated: 2025/02/25 16:08:57 by rhafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_mouse_for_julia(int button, int x, int y, t_mlx_data *mlx)
{
	double	zoom_factor;
	double	center_x;
	double	center_y;

	(void)x;
	(void)y;
	zoom_factor = 1.0;
	if (button == 4)
		zoom_factor = 0.9;
	else if (button == 5)
		zoom_factor = 1.1;
	center_x = mlx->img->graph.x_start + (mlx->img->graph.x_end
			- mlx->img->graph.x_start) / 2;
	center_y = mlx->img->graph.y_start + (mlx->img->graph.y_end
			- mlx->img->graph.y_start) / 2;
	mlx->img->graph.x_start = center_x + (mlx->img->graph.x_start - center_x)
		* zoom_factor;
	mlx->img->graph.x_end = center_x + (mlx->img->graph.x_end - center_x)
		* zoom_factor;
	mlx->img->graph.y_start = center_y + (mlx->img->graph.y_start - center_y)
		* zoom_factor;
	mlx->img->graph.y_end = center_y + (mlx->img->graph.y_end - center_y)
		* zoom_factor;
	display_julia(mlx, mlx->img, &mlx->c);
	return (0);
}

int	handle_keys_for_julia(int keycode, t_mlx_data *mlx)
{
	double	width;
	double	height;
	double	x_factor;
	double	y_factor;

	width = mlx->img->graph.x_end - mlx->img->graph.x_start;
	height = mlx->img->graph.y_end - mlx->img->graph.y_start;
	x_factor = width * 0.05;
	y_factor = height * 0.05;
	if (keycode == XK_Escape)
	{
		mlx_destroy_image(mlx->mlx_connection, mlx->img->img);
		mlx_destroy_window(mlx->mlx_connection, mlx->mlx_win);
		mlx_destroy_display(mlx->mlx_connection);
		free(mlx->mlx_connection);
		exit(1);
	}
	else if (keycode == XK_Left || keycode == XK_Right)
		x_movement(mlx, x_factor, keycode);
	else if (keycode == XK_Up || keycode == XK_Down)
		y_movement(mlx, y_factor, keycode);
	display_julia(mlx, mlx->img, &mlx->c);
	return (0);
}

int	handle_expose_for_julia(t_mlx_data *mlx)
{
	display_julia(mlx, mlx->img, &mlx->c);
	return (0);
}
