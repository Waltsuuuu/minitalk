/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wheino <wheino@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:06:41 by wheino            #+#    #+#             */
/*   Updated: 2025/07/16 13:31:05 by wheino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char *argv[])
{
	pid_t	pid;

	if (check_args(argc) == ERROR)
		return (EXIT_FAILURE);
	pid = check_pid(argv[1]);
	if (pid == ERROR)
		return (EXIT_FAILURE);
	kill(pid, SIGUSR1);
	return (EXIT_SUCCESS);
}
