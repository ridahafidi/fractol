/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:28:24 by rhafidi           #+#    #+#             */
/*   Updated: 2025/02/25 18:05:28 by rhafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static int	check_inside_set_julia(double z_real, double z_i, t_julia_c *c)
{
	t_complex_nbr	z;
	int				i;
	double			norm;
	double			tmp_z_real;

	z.real = z_real;
	z.i = z_i;
	i = 0;
	norm = 0;
	while (i < 100 && norm <= 4)
	{
		tmp_z_real = (z.real * z.real) - (z.i * z.i);
		z.i = 2 * z.real * z.i;
		z.real = tmp_z_real;
		z.real += c->real;
		z.i += c->i;
		norm = (z.real * z.real) + (z.i * z.i);
		i++;
	}
	return (i);
}

static void	my_pixel_put_julia(t_data *img, int x, int y, int keycode)
{
	char	*offset;
	double	new_x;
	double	new_y;
	int		iter;

	while (y < HEIGHT)
	{
		new_y = ((double)-y / (double)HEIGHT) * (img->graph.y_end
				- img->graph.y_start) + img->graph.y_end;
		x = 0;
		while (x < WIDTH)
		{
			new_x = ((double)x / (double)WIDTH) * (img->graph.x_end
					- img->graph.x_start) + img->graph.x_start;
			offset = img->addr + (y * img->line_length + x
					* (img->bits_per_pixel / 8));
			iter = check_inside_set_julia(new_x, new_y, &img->c);
			*(unsigned int *)offset = get_color(iter, 100, keycode);
			x++;
		}
		y++;
	}
}

void	display_julia(t_mlx_data *mlx, t_data *img, int keycode)
{
	my_pixel_put_julia(img, 0, 0, keycode);
	mlx_put_image_to_window(mlx->mlx_connection, mlx->mlx_win, img->img, 0, 0);
}
