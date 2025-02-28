/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrotset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 19:23:13 by rhafidi           #+#    #+#             */
/*   Updated: 2025/02/25 16:09:49 by rhafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	check_inside_set(double c_real, double c_img)
{
	t_complex_nbr	c;
	t_complex_nbr	z;
	int				i;
	double			norm;
	double			tmp_z_real;

	c.real = c_real;
	c.i = c_img;
	z.real = 0;
	z.i = 0;
	i = 0;
	norm = 0;
	while (i < 100 && norm <= 4)
	{
		tmp_z_real = (z.real * z.real) - (z.i * z.i);
		z.i = 2 * z.real * z.i;
		z.real = tmp_z_real;
		z.real += c.real;
		z.i += c.i;
		norm = (z.real * z.real) + (z.i * z.i);
		i++;
	}
	return (i);
}

static void	my_pixel_put(t_data *img, int x, int y)
{
	char	*offset;
	double	new_x;
	double	new_y;
	int		iter;

	while (y < HEIGHT)
	{
		new_y = ((double)-y / (double)HEIGHT)
			* (img->graph.y_end - img->graph.y_start) + img->graph.y_end;
		x = 0;
		while (x < WIDTH)
		{
			new_x = ((double)x / (double)WIDTH)
				* (img->graph.x_end - img->graph.x_start) + img->graph.x_start;
			offset = img->addr + (y * img->line_length
					+ x * (img->bits_per_pixel / 8));
			iter = check_inside_set(new_x, new_y);
			*(unsigned int *)offset = get_color(iter, 100);
			x++;
		}
		y++;
	}
}

void	display_mandelbortset(t_mlx_data *mlx, t_data *img)
{
	my_pixel_put(img, 0, 0);
	mlx_put_image_to_window(mlx->mlx_connection, mlx->mlx_win, img->img, 0, 0);
}
