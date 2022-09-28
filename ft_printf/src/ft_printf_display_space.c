/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_display_space.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:10:49 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/03/25 15:59:36 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_display_space(va_list *args, char c, const char **str,
	t_printf_status *pf_status)
{
	int	n;

	if (c == 'd' || c == 'i')
	{
		n = va_arg(*args, int);
		if (n >= 0)
			ft_putstr_fd(" ", 1);
		ft_putnbr_fd(n, 1);
		if (n < 0)
			return (ft_nblen(n, 10));
		else
			return (ft_nblen(n, 10) + 1);
	}
	else
		return (ft_printf_flags_list(args, c, str, pf_status));
}
