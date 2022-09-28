/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:28:43 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/03/25 16:12:02 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_init_status(t_printf_status *status)
{
	status->hash = 0;
}

int	ft_printf_flags_list(va_list *args, int format, const char **str,
	t_printf_status *status)
{
	if (format == '\0')
		return (0);
	else if (format == 'c')
		return (ft_printf_display_char(args));
	else if (format == 's')
		return (ft_printf_display_str(args));
	else if (format == 'p')
		return (ft_printf_display_ptr(args, 0));
	else if (format == 'd' || format == 'i')
		return (ft_printf_display_int(args));
	else if (format == 'u')
		return (ft_printf_display_uint(args));
	else if (format == 'x')
		return (ft_printf_display_hexl(args, status));
	else if (format == 'X')
		return (ft_printf_display_hexu(args, status));
	else if (format == '#')
		return (ft_printf_display_hash(args, *++*str, str, status));
	else if (format == ' ')
		return (ft_printf_display_space(args, *++*str, str, status));
	else if (format == '+')
		return (ft_printf_display_sign(args, *++*str, str, status));
	else
		return (ft_printf_display_default(format));
}

int	ft_printf(const char *args, ...)
{
	va_list			args_list;
	t_printf_status	status;
	size_t			cc;

	ft_printf_init_status(&status);
	cc = 0;
	if (!args)
		return (cc);
	va_start(args_list, args);
	while (*args != '\0')
	{
		if (*args == '%')
			cc += ft_printf_flags_list(&args_list, *++args, &args, &status);
		else
			cc += ft_printf_display_default(*args);
		if (*args != '\0')
			args++;
	}
	va_end(args_list);
	return (cc);
}
