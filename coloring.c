/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:33:08 by rhafidi           #+#    #+#             */
/*   Updated: 2025/02/26 21:48:53 by rhafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	get_color(int iter, int max_iter)
{
	double		t;
	double		t_cmplt;
	t_colors	color;

	if (iter == max_iter)
		return (0x00000000);
	t = (double) iter / max_iter;
	t_cmplt = 1 - t;
	color.r = (unsigned char)(9 * t_cmplt * t * t * t * 255);
	color.g = (unsigned char)(15 * t_cmplt * t_cmplt * t * t * 255);
	color.b = (unsigned char)(8.5 * t_cmplt * t_cmplt * t_cmplt * t * 255);
	return (color.r << 16 | color.g << 8 | color.b);
}

int	checksign(char c)
{
	if (c == '-')
		return (-1);
	else
		return (1);
}
