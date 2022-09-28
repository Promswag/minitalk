/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_display_char.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:50:56 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/03/25 15:48:32 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_display_char(va_list *args)
{
	int	c;

	c = va_arg(*args, int);
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_printf_display_default(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}
