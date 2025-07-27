/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wheino <wheino@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:06:46 by wheino            #+#    #+#             */
/*   Updated: 2025/07/27 20:55:34 by wheino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_server_state	g_state;

int	main(void)
{
	struct sigaction	sa;

	g_state.expecting_len = TRUE;
	g_state.msg_len = 0;
	g_state.msg = NULL;
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

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (sig == SIGUSR2 || sig == SIGUSR1)
		decode_bits(sig, info);
}

void	decode_bits(int sig, siginfo_t *info)
{
	static int		bit_index = 7;
	static int		current_char = 0;

	if (sig == SIGUSR2)
		current_char = current_char | (1 << (bit_index));
	bit_index--;
	if (bit_index < 0)
	{
		if (g_state.expecting_len == TRUE)
			build_len(current_char);
		else
			build_msg(current_char, info->si_pid);
		bit_index = 7;
		current_char = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

void	build_len(char c)
{
	static char	len_s[11];
	static int	i = 0;

	if (c == '\0')
	{
		len_s[i] = c;
		g_state.msg_len = ft_atoi(len_s);
		g_state.expecting_len = FALSE;
		i = 0;
	}
	else if (i < 10)
	{
		len_s[i++] = c;
		len_s[i] = '\0';
	}
}

void	build_msg(char c, pid_t pid)
{
	static int	i = 0;

	if (!g_state.msg)
	{
		g_state.msg = malloc((sizeof(char) * g_state.msg_len) + 1);
		if (!g_state.msg)
		{
			ft_printf("Malloc failed\n");
			exit(EXIT_FAILURE);
		}
	}
	g_state.msg[i++] = c;
	if (c == '\0')
	{
		ft_printf("%s\n", g_state.msg);
		free(g_state.msg);
		g_state.msg = NULL;
		g_state.expecting_len = TRUE;
		i = 0;
		kill(pid, SIGUSR2);
	}
}
