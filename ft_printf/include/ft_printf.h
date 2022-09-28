/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:23:51 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/03/25 16:11:52 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_printf_status {
	int	hash;
}		t_printf_status;

//ft_printf
int		ft_printf(const char *args, ...);
int		ft_printf_flags_list(va_list *args, int format, const char **str,
			t_printf_status *status);
int		ft_printf_display_default(int c);
int		ft_printf_display_char(va_list *args);
int		ft_printf_display_str(va_list *args);
int		ft_printf_display_ptr(va_list *args, int format);
int		ft_printf_display_int(va_list *args);
int		ft_printf_display_uint(va_list *args);
int		ft_printf_display_hexl(va_list *args, t_printf_status *status);
int		ft_printf_display_hexu(va_list *args, t_printf_status *status);
int		ft_printf_display_hash(va_list *args, char c, const char **str,
			t_printf_status *status);
int		ft_printf_display_space(va_list *args, char c, const char **str,
			t_printf_status *status);
int		ft_printf_display_sign(va_list *args, char c, const char **str,
			t_printf_status *status);

//libft
size_t	ft_strlen(const char *s);
size_t	ft_nblen(int n, int base);
size_t	ft_ullen(unsigned long int n, unsigned long int base);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putnbr_base_fd(unsigned long int n, char *base, int fd);
void	ft_print_uint_fd(unsigned int n, int fd);

#endif