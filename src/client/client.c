/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wheino <wheino@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:06:41 by wheino            #+#    #+#             */
/*   Updated: 2025/07/27 14:32:00 by wheino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile sig_atomic_t	g_signal_received;

void	send_len(pid_t pid, char *msg)
{
	int		len;
	char	*len_s;

	len = ft_strlen(msg);
	len_s = ft_itoa(len);
	send_msg(pid, len_s);
}

int	send_msg(pid_t pid, const char *msg)
{
	int	i;

	i = 0;
	while (msg[i] != '\0')
	{
		send_char(pid, msg[i]);
		i++;
	}
	send_char(pid, msg[i]);
	return (SUCCESS);
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
		while (!g_signal_received)
			usleep(1);
		g_signal_received = 0;
		bit_index--;
	}
}

void	handle_ack_signal(int sig)
{
	if (sig == SIGUSR1)
		g_signal_received = 1;
	else if (sig == SIGUSR2)
		ft_printf("Message sent succesfully!\n");
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
	signal(SIGUSR2, handle_ack_signal);
	send_len(pid, argv[2]);
	send_msg(pid, argv[2]);
	return (EXIT_SUCCESS);
}
