/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wheino <wheino@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:06:41 by wheino            #+#    #+#             */
/*   Updated: 2025/07/17 16:03:16 by wheino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_msg(pid_t pid, const char *msg)
{
	int	i;

	i = 0;
	while (msg[i] != '\0')
	{
		send_char(pid, msg[i]);
		i++;
	}
	send_char(pid, msg[i]);
}

void	send_char(pid_t pid, char c)
{
	int	bit_index;
	int	bit;

	bit_index = 7;
	while (bit_index >= 0)
	{
		bit = (c >> bit_index) & 1;
		if (bit == 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		pause();
		bit_index--;
	}
}

void	handle_ack_signal(int sig)
{
	(void)sig;
}

int	main(int argc, char *argv[])
{
	pid_t	pid;

	if (check_args(argc) == ERROR)
		return (EXIT_FAILURE);
	pid = check_pid(argv[1]);
	if (pid == ERROR)
		return (EXIT_FAILURE);
	signal(SIGUSR1, handle_ack_signal);
	send_msg(pid, argv[2]);
	return (EXIT_SUCCESS);
}
