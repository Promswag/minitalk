/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_display_hex.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:13:24 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/03/25 16:04:59 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_display_hexl(va_list *args, t_printf_status *pf_status)
{
	unsigned int	n;

	n = va_arg(*args, unsigned int);
	if (pf_status->hash == 1)
	{
		ft_putstr_fd("0x", 1);
		ft_putnbr_base_fd(n, "0123456789abcdef", 1);
		return (ft_ullen(n, 16) + 2);
	}
	else
	{
		ft_putnbr_base_fd(n, "0123456789abcdef", 1);
		return (ft_ullen(n, 16));
	}
}

int	ft_printf_display_hexu(va_list *args, t_printf_status *pf_status)
{
	unsigned int	n;

	n = va_arg(*args, unsigned int);
	if (pf_status->hash == 1)
	{
		ft_putstr_fd("0x", 1);
		ft_putnbr_base_fd(n, "0123456789ABCDEF", 1);
		return (ft_ullen(n, 16) + 2);
	}
	else
	{
		ft_putnbr_base_fd(n, "0123456789ABCDEF", 1);
		return (ft_ullen(n, 16));
	}
}
