/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_display_hash.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:22:41 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/03/25 16:04:09 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_display_hash(va_list *args, char c, const char **str,
	t_printf_status *pf_status)
{
	unsigned int	n;

	if (c == 'x' || c == 'X')
	{
		n = va_arg(*args, unsigned int);
		if (n == 0)
			return (ft_printf_display_default('0'));
		if (c == 'x')
		{
			ft_putstr_fd("0x", 1);
			ft_putnbr_base_fd(n, "0123456789abcdef", 1);
		}
		else
		{
			ft_putstr_fd("0X", 1);
			ft_putnbr_base_fd(n, "0123456789ABCDEF", 1);
		}
		return (ft_ullen(n, 16) + 2);
	}
	else
	{
		pf_status->hash = 1;
		return (ft_printf_flags_list(args, c, str, pf_status));
	}
}
