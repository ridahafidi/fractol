/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_set_events_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:46:39 by rhafidi           #+#    #+#             */
/*   Updated: 2025/02/25 18:06:19 by rhafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	handle_mouse_for_my_set(int button, int x, int y, t_mlx_data *mlx)
{
	double	zoom_factor;
	double	mouse_x;
	double	mouse_y;
	double	new_x_start;
	double	new_y_start;

	mouse_x = ((double)x / WIDTH) * (mlx->img->graph.x_end
			- mlx->img->graph.x_start) + mlx->img->graph.x_start;
	mouse_y = ((double)-y / HEIGHT) * (mlx->img->graph.y_end
			- mlx->img->graph.y_start) + mlx->img->graph.y_end;
	zoom_factor = 1;
	if (button == 4)
		zoom_factor = 2.0;
	else if (button == 5)
		zoom_factor = 0.5;
	new_x_start = mouse_x - (mouse_x - mlx->img->graph.x_start) / zoom_factor;
	mlx->img->graph.x_end = ((mlx->img->graph.x_end - mlx->img->graph.x_start)
			/ zoom_factor) + new_x_start;
	mlx->img->graph.x_start = new_x_start;
	new_y_start = mouse_y - (mouse_y - mlx->img->graph.y_start) / zoom_factor;
	mlx->img->graph.y_end = ((mlx->img->graph.y_end - mlx->img->graph.y_start)
			/ zoom_factor) + new_y_start;
	mlx->img->graph.y_start = new_y_start;
	display_my_set(mlx, mlx->img, mlx->img->current_color);
	return (0);
}

int	handle_keys_for_my_set(int keycode, t_mlx_data *mlx)
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
	else if (keycode == XK_r || keycode == XK_g || keycode == XK_b)
		mlx->img->current_color = keycode;
	display_my_set(mlx, mlx->img, mlx->img->current_color);
	return (0);
}

int	handle_expose_for_my_set(t_mlx_data *mlx)
{
	display_my_set(mlx, mlx->img, mlx->img->current_color);
	return (0);
}
