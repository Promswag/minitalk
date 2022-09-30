/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:18:08 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/09/30 17:36:28 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signal, siginfo_t *siginfo, void *context)
{
	static int				i;
	static unsigned char	c;

	(void)context;
	c <<= 1;
	if (signal == SIGUSR1)
		c += 1;
	if (!i)
		i = 0;
	if (++i == 8)
	{
		i = 0;
		if (c == 0)
		{
			ft_printf("\n");
			kill(siginfo->si_pid, SIGUSR1);
		}
		else
			ft_printf("%c", c);
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("%u\n", (int)pid);
	sa.sa_flags = 0;
	sa.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
