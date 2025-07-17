/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wheino <wheino@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:06:43 by wheino            #+#    #+#             */
/*   Updated: 2025/07/17 16:07:09 by wheino           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include "libft.h"
# include "ft_printf.h"

# define ERROR -1
# define SUCCESS 0

/* -- server.c -- */
void	handle_signal(int sig, siginfo_t *info, void *context);

/* -- client.c -- */
void	send_msg(pid_t pid, const char *msg);
void	send_char(pid_t pid, char c);

/* -- client_utils.c -- */
pid_t	check_pid(const char *pid_string);
int		check_args(int argc);

#endif