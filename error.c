/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:40:02 by rhafidi           #+#    #+#             */
/*   Updated: 2025/02/25 16:04:11 by rhafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_manual(void)
{
	ft_putstr_fd(" --------------------------Manual------------------ \n", 2);
	ft_putstr_fd(" |                                                  | \n", 2);
	ft_putstr_fd(" |                        First:                    | \n", 2);
	ft_putstr_fd(" |        for the mandelbrot set to be displayed    | \n", 2);
	ft_putstr_fd(" |    --> ./fractol mandelbrot                      | \n", 2);
	ft_putstr_fd(" |                                                  | \n", 2);
	ft_putstr_fd(" |                       Second:                    | \n", 2);
	ft_putstr_fd(" |           for the julia set to be displayed      | \n", 2);
	ft_putstr_fd(" |    --> ./fractol julia {real_nbr} {imaginary_nbr}| \n", 2);
	ft_putstr_fd(" |                                                  | \n", 2);
	ft_putstr_fd(" --------------------------------------------------- \n", 2);
}
