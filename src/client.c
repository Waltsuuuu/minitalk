/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wheino <wheino@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:06:41 by wheino            #+#    #+#             */
/*   Updated: 2025/07/16 12:59:45 by wheino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char *argv[])
{
	pid_t	pid;
	
	if (argc != 3)
	{
		ft_printf("ERROR: Execute with: ./client [PID] [MSG]\n");
		return (EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	kill(pid, SIGUSR1);
	return (EXIT_SUCCESS);
}