/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 22:59:26 by rhafidi           #+#    #+#             */
/*   Updated: 2025/02/28 20:45:45 by rhafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initiate(t_mlx_data *mlx, t_data *img)
{
	mlx->mlx_connection = mlx_init();
	if (!mlx->mlx_connection)
		exit(1);
	mlx->mlx_win = mlx_new_window(mlx->mlx_connection,
			WIDTH, HEIGHT, "Fractol");
	if (!mlx->mlx_win)
	{
		mlx_destroy_display(mlx->mlx_connection);
		free(mlx->mlx_connection);
		exit(1);
	}
	img->img = mlx_new_image(mlx->mlx_connection, WIDTH, HEIGHT);
	if (!img->img)
	{
		mlx_destroy_display(mlx->mlx_connection);
		free(mlx->mlx_connection);
		exit(1);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	img->graph.x_start = -2;
	img->graph.x_end = 2;
	img->graph.y_start = -2;
	img->graph.y_end = 2;
	mlx->img = img;
}

void	mandelbrot(t_mlx_data *mlx, t_data *img)
{
	initiate(mlx, img);
	display_mandelbortset(mlx, img);
	mlx_key_hook(mlx->mlx_win, &handle_keys_for_mandelbrot, mlx);
	mlx_hook(mlx->mlx_win, 17, 0, &handle_destroy, mlx);
	mlx_mouse_hook(mlx->mlx_win, &handle_mouse_for_mandelbrot, mlx);
	mlx_expose_hook(mlx->mlx_win, &handle_expose_for_mandelbrot, mlx);
	mlx_loop(mlx->mlx_connection);
}

void	julia(t_mlx_data *mlx, t_data *img, char *c_real, char *c_img)
{
	initiate(mlx, img);
	mlx->c.real = ft_atoi(c_real, 0, 0, 0);
	mlx->c.i = ft_atoi(c_img, 0, 0, 0);
	display_julia(mlx, img, &mlx->c);
	mlx_key_hook(mlx->mlx_win, &handle_keys_for_julia, mlx);
	mlx_mouse_hook(mlx->mlx_win, &handle_mouse_for_julia, mlx);
	mlx_hook(mlx->mlx_win, 17, 0, &handle_destroy, mlx);
	mlx_expose_hook(mlx->mlx_win, &handle_expose_for_julia, mlx);
	mlx_loop(mlx->mlx_connection);
}

int	main(int ac, char **av)
{
	t_mlx_data	mlx;
	t_data		img;

	if (ac <= 4)
	{
		if (ac == 2)
		{
			if (!ft_strncmp(av[1], "mandelbrot", 11))
				mandelbrot(&mlx, &img);
		}
		else if (ac == 4)
		{
			if (!ft_strncmp(av[1], "julia", 6))
			{
				if (!valid_args(av[2], 0) && !valid_args(av[3], 0))
					julia(&mlx, &img, av[2], av[3]);
			}
		}
	}
	print_manual();
	return (0);
}
