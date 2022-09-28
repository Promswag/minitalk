/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_display_ptr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:09:31 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/03/25 15:48:58 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_display_ptr(va_list *args, int format)
{
	void	*ptr;

	ptr = va_arg(*args, void *);
	if (ptr)
	{
		if (format)
		{
			ft_putstr_fd("0X", 1);
			ft_putnbr_base_fd((unsigned long int)ptr, "0123456789ABCDEF", 1);
		}
		else
		{
			ft_putstr_fd("0x", 1);
			ft_putnbr_base_fd((unsigned long int)ptr, "0123456789abcdef", 1);
		}
		return (ft_ullen((unsigned long int)ptr, 16) + 2);
	}
	else
	{
		ft_putstr_fd("0x0", 1);
		return (3);
	}
}
