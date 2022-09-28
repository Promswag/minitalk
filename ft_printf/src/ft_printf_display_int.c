/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_display_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:10:06 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/03/25 15:48:54 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_display_int(va_list *args)
{
	int	n;

	n = va_arg(*args, int);
	ft_putnbr_fd(n, 1);
	return (ft_nblen(n, 10));
}
