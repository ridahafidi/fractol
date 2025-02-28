/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:33:08 by rhafidi           #+#    #+#             */
/*   Updated: 2025/02/26 21:47:40 by rhafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	set_color(t_colors *color, double t, int keycode)
{
	double	t_cmplt;

	t_cmplt = 1 - t;
	if (keycode == XK_r)
	{
		color->r = (unsigned char)(8.5 * t_cmplt * t_cmplt * t_cmplt * t * 255);
		color->g = (unsigned char)(9 * t_cmplt * t * t * t * 255);
		color->b = (unsigned char)(15 * t_cmplt * t_cmplt * t * t * 255);
	}
	if (keycode == XK_g)
	{
		color->r = (unsigned char)(15 * t_cmplt * t_cmplt * t * t * 255);
		color->g = (unsigned char)(8.5 * t_cmplt * t_cmplt * t_cmplt * t * 255);
		color->b = (unsigned char)(9 * t_cmplt * t * t * t * 255);
	}
	if (keycode == XK_b)
	{
		color->r = (unsigned char)(9 * t_cmplt * t * t * t * 255);
		color->g = (unsigned char)(15 * t_cmplt * t_cmplt * t * t * 255);
		color->b = (unsigned char)(8.5 * t_cmplt * t_cmplt * t_cmplt * t * 255);
	}
}

unsigned int	get_color(int iter, int max_iter, int keycode)
{
	double		t;
	double		t_cmplt;
	t_colors	color;

	if (iter == max_iter)
		return (0x00000000);
	t = (double)iter / max_iter;
	t_cmplt = 1 - t;
	color.r = (unsigned char)(9 * t_cmplt * t * t * t * 255);
	color.g = (unsigned char)(15 * t_cmplt * t_cmplt * t * t * 255);
	color.b = (unsigned char)(8.5 * t_cmplt * t_cmplt * t_cmplt * t * 255);
	set_color(&color, t, keycode);
	return (color.r << 16 | color.g << 8 | color.b);
}

int	checksign(char c)
{
	if (c == '-')
		return (-1);
	else
		return (1);
}
