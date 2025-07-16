/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wheino <wheino@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:06:41 by wheino            #+#    #+#             */
/*   Updated: 2025/07/16 13:18:30 by wheino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

pid_t	check_pid(const char *pid_string)
{
	int		i;
	pid_t	server_pid;

	i = 0;
	if (!pid_string || pid_string[0] == '\0')
		return (ERROR);
	while (pid_string[i] != '\0')
	{
		if (ft_isdigit(pid_string[i]) == 0)
		{
			ft_printf("ERROR: Invalid PID format.\n");
			return (ERROR);
		}
		i++;
	}
	server_pid = ft_atoi(pid_string);
	if (kill(server_pid, 0) == -1)
	{
		ft_printf("ERROR: Incorrect PID. PID %d does not exist.\n", server_pid);
		return (ERROR);
	}
	return (server_pid);
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	
	if (argc != 3)
	{
		ft_printf("ERROR: Execute with: ./client [PID] [MSG].\n");
		return (EXIT_FAILURE);
	}
	pid = check_pid(argv[1]);
	if (pid == ERROR)
		return (EXIT_FAILURE);
	kill(pid, SIGUSR1);
	return (EXIT_SUCCESS);
}

