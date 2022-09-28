/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:36:13 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/03/16 16:36:25 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_nblen(int number, int base)
{
	int	len;

	len = 1;
	if (number < 0)
		len++;
	while (number >= base || number <= -base)
	{
		number /= base;
		len++;
	}
	return (len);
}

size_t	ft_ullen(unsigned long int number, unsigned long int base)
{
	int	len;

	len = 1;
	while (number >= base)
	{
		number /= base;
		len++;
	}
	return (len);
}

void	ft_putnbr_base_fd(unsigned long int n, char *base, int fd)
{
	size_t	size;

	size = ft_strlen(base);
	if (n > size - 1)
		ft_putnbr_base_fd((n / size), base, fd);
	ft_putchar_fd(base[n % size], fd);
}

static unsigned int	ft_scale(
	unsigned int number,
	unsigned int base)
{
	unsigned int	scale;

	scale = 1;
	while (number >= base)
	{
		scale *= base;
		number /= base;
	}
	return (scale);
}

void	ft_print_uint_fd(unsigned int n, int fd)
{
	int	scale;

	scale = ft_scale(n, 10);
	while (scale != 0)
	{
		ft_putchar_fd(n / scale + 48, fd);
		n %= scale;
		scale /= 10;
	}
}
