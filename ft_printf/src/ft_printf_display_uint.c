/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_display_uint.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:12:49 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/03/25 16:07:33 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_display_uint(va_list *args)
{
	unsigned int	n;

	n = va_arg(*args, unsigned int);
	ft_print_uint_fd(n, 1);
	return (ft_ullen(n, 10));
}
