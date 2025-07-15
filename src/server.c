/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wheino <wheino@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:06:46 by wheino            #+#    #+#             */
/*   Updated: 2025/07/15 19:41:20 by wheino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	pid_t	pid;
	
	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	
	while(1)
		pause();
	return (EXIT_SUCCESS);
}