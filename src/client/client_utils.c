/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wheino <wheino@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:25:08 by wheino            #+#    #+#             */
/*   Updated: 2025/07/27 20:34:04 by wheino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

pid_t	check_pid(const char *pid_string)
{
	int		i;
	pid_t	server_pid;

	i = 0;
	if (!pid_string || pid_string[0] == '\0')
	{
		ft_printf("ERROR: Empty PID.\n");
		return (ERROR);
	}
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
	if (kill(server_pid, 0) == ERROR || server_pid <= 0)
	{
		ft_printf("ERROR: Incorrect PID. PID %d does not exist.\n", server_pid);
		return (ERROR);
	}
	return (server_pid);
}

int	check_args(int argc)
{
	if (argc != 3)
	{
		ft_printf("ERROR: Execute with: ./client [PID] [MSG].\n");
		return (ERROR);
	}
	return (SUCCESS);
}
