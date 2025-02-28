/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_helper_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:01:48 by rhafidi           #+#    #+#             */
/*   Updated: 2025/02/25 17:30:49 by rhafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	x_movement(t_mlx_data *mlx, double x_factor, int keycode)
{
	if (keycode == XK_Left)
	{
		mlx->img->graph.x_end -= x_factor;
		mlx->img->graph.x_start -= x_factor;
	}
	else
	{
		mlx->img->graph.x_end += x_factor;
		mlx->img->graph.x_start += x_factor;
	}
}

void	y_movement(t_mlx_data *mlx, double y_factor, int keycode)
{
	if (keycode == XK_Down)
	{
		mlx->img->graph.y_end -= y_factor;
		mlx->img->graph.y_start -= y_factor;
	}
	else
	{
		mlx->img->graph.y_end += y_factor;
		mlx->img->graph.y_start += y_factor;
	}
}
