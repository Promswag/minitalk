/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:21:50 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/10/04 14:19:43 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	terminate_message_to_pid(int pid, int bit)
{
	while (bit--)
	{
		kill(pid, SIGUSR2);
		usleep(69);
	}
}

void	send_message_to_pid(int pid, char *message)
{
	int	bit;
	int	r;

	while (*message)
	{
		bit = 8;
		while (bit--)
		{
			if (((*message >> bit) % 2))
				r = kill(pid, SIGUSR1);
			else
				r = kill(pid, SIGUSR2);
			if (r)
			{
				ft_printf("Proccess with PID %d is unreachable.\n", pid);
				exit(0);
			}
			usleep(69);
		}
		message++;
	}
	terminate_message_to_pid(pid, 8);
}

void	signal_ack(int signal)
{
	if (signal == SIGUSR1)
	{
		ft_printf("Message sent.\n");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		signal(SIGUSR1, signal_ack);
		send_message_to_pid(ft_atoi(argv[1]), argv[2]);
		while (1)
			pause();
	}
}
