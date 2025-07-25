/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wheino <wheino@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:06:46 by wheino            #+#    #+#             */
/*   Updated: 2025/07/25 15:37:09 by wheino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile sig_atomic_t	g_expecting_len = TRUE;
static int g_len;

// Remember to free malloc on CTRL+C / unexpected exit

void	decode_bits(int sig, siginfo_t *info)
{
	static int		bit_index = 0;
	static int		current_char = 0;

	if (sig == SIGUSR2)
		current_char = current_char | (1 << (7 - bit_index)); // make this more readable, why start from 0 when client starts from 7.
	bit_index++;
	if (bit_index == 8)
	{
		if (g_expecting_len == TRUE)
		{
			ft_printf("Build len\n");
			build_len(current_char); //Gathers the message length string. 
		}
		else
		{
			ft_printf("Build msg - char = %c\n", current_char);
			build_msg(current_char, info->si_pid); //Gathers the message string.
		}
		bit_index = 0;
		current_char = 0;
	}
	kill(info->si_pid, SIGUSR1); //ack signal
}

void	build_len(char c)
{
	static char	len_s[11];
	static int	i = 0;
	
	ft_printf("len char = %c\n", c);
	if (c == '\0')
	{
		len_s[i] = c;
		g_len = ft_atoi(len_s);
		g_expecting_len = FALSE;

	}
	else if (i < 10)
	{
		len_s[i++] = c;
		len_s[i] = '\0';
		i++;
	}
	ft_printf("len_s = %s", len_s);
	ft_printf("Len = %d\n", g_len);
}

void	build_msg(char c, pid_t pid)
{
	static int 	i = 0;
	static char	*msg = NULL;
	
	if (!msg)
		msg = malloc((sizeof(char) * g_len) + 1); //Maybe guard??
	msg[i++] = c;
	if (i == g_len)
	{
		msg[i] = '\0';
		ft_printf("%s\n", msg);
		free(msg);
		g_expecting_len = TRUE;
		i = 0;
		kill(pid, SIGUSR2);
	}
}

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	(void)context;
	if (sig == SIGUSR2 || sig == SIGUSR1)
	{
		ft_printf("signal received\n");
		decode_bits(sig, info);
	}
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
