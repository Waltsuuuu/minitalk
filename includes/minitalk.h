/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wheino <wheino@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:06:43 by wheino            #+#    #+#             */
/*   Updated: 2025/07/27 13:55:04 by wheino           ###   ########.fr       */
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
# define TRUE 1
# define FALSE 0

/* -- server.c -- */
void	build_len(char c);
void	build_msg(char c, pid_t pid);
void	decode_bits(int sig, siginfo_t *info);
void	handle_signal(int sig, siginfo_t *info, void *context);
int		*print_byte(char current_char, int *current_client);

/* -- client.c -- */
int		send_msg(pid_t pid, const char *msg);
void	send_char(pid_t pid, char c);

/* -- client_utils.c -- */
pid_t	check_pid(const char *pid_string);
int		check_args(int argc);
void	send_len(pid_t pid, char *msg);

#endif