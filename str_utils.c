/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhafidi <rhafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:59:27 by rhafidi           #+#    #+#             */
/*   Updated: 2025/02/26 21:48:10 by rhafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		if (!*s1)
			return (0);
		s1++;
		s2++;
		n--;
	}
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		s++;
	}
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	valid_args(char *str, int i)
{
	int	found_point;
	int	is_digit;
	int	sign;

	i = 0;
	found_point = 0;
	is_digit = 0;
	sign = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		sign++;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			is_digit++;
		if (str[i] == '.')
			found_point++;
		i++;
	}
	if ((found_point == 1 || found_point == 0)
		&& is_digit + found_point + sign == ft_strlen(str))
		return (0);
	return (1);
}

double	ft_atoi(char *str, int i, double res_1, double res_2)
{
	double	div;
	int		sign;

	sign = 1;
	div = 1.0;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = checksign(str[i]);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res_1 *= (res_1 * 10) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res_2 = (res_2 * 10) + (str[i] - '0');
		div *= 10;
		i++;
	}
	return ((res_1 + res_2 / div) * (double)sign);
}
