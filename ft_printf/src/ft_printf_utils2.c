/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:43:20 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/03/23 16:48:46 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

static int	ft_scale(int number, int base)
{
	int	scale;

	scale = 1;
	while (number >= base || number <= -base)
	{
		scale *= base;
		number /= base;
	}
	return (scale);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	scale;

	scale = ft_scale(n, 10);
	if (n < 0)
		ft_putchar_fd('-', fd);
	while (scale != 0)
	{
		if (n >= 0)
			ft_putchar_fd(n / scale + 48, fd);
		else
			ft_putchar_fd(-(n / scale) + 48, fd);
		n %= scale;
		scale /= 10;
	}
}
