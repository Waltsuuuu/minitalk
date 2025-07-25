/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wheino <wheino@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:06:46 by wheino            #+#    #+#             */
/*   Updated: 2025/07/25 14:11:59 by wheino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	*print_byte(char current_char, pid_t *current_client)
{
	if (current_char == '\0')
	{
		write(1, "\n", 1);
		*current_client = 0;
	}
	else
		write(1, &current_char, 1);
	return (current_client);
}

void	print_byte(int sig, siginfo_t *info, void *context)
{
	static int		bit_index = 0;
	static int		current_char = 0;
	static pid_t	current_client;
	pid_t			client;

	if (sig == SIGUSR2)
		current_char = current_char | (1 << (7 - bit_index));
	bit_index++;
	if (bit_index == 8)
	{
		print_byte(current_char, &current_client);
		bit_index = 0;
		current_char = 0;
	}
	kill(client, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
