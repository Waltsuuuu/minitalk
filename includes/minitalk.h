/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wheino <wheino@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:06:43 by wheino            #+#    #+#             */
/*   Updated: 2025/07/16 13:30:53 by wheino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h> // write, pause, usleep, sleep
# include <signal.h> // signal, sigemptyset, sigaddset, sigaction, kill
# include <stdlib.h> // malloc, free, exit
# include <sys/types.h> //getpid
# include "libft.h"
# include "ft_printf.h"

# define ERROR -1
# define SUCCESS 0

/* -- client_utils.c -- */
pid_t	check_pid(const char *pid_string);
int		check_args(int argc);

#endif