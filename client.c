/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 22:25:44 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/12/09 11:32:18 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include "libftprintf/libftprintf.h"

static int	g_received;

void	handler(int signum)
{
	(void)signum;
	g_received = 1;
}

void	treat_char(char c, int pid)
{
	int	i;
	int	nb;

	i = 0;
	nb = 1;
	while (i < (int) sizeof(c) * 8)
	{
		while (g_received != 1)
		{
		}
		if ((c & nb) == 0)
		{
			g_received = 0;
			kill(pid, SIGUSR1);
		}
		else
		{
			g_received = 0;
			kill(pid, SIGUSR2);
		}
		nb = nb * 2;
		i++;
	}
}

void	send_signals(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		treat_char(str[i], pid);
		i++;
	}
	treat_char(str[i], pid);
}

int	ft_pid(char *str)
{
	int	i;
	int	pid;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		i++;
	}
	pid = ft_atoi(str);
	if (pid > 4194304 || pid < 1)
		return (-1);
	return (pid);
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	act;

	g_received = 1;
	if (argc != 3)
	{
		ft_printf("Specify PID and message, that's it\n");
		return (1);
	}
	pid = ft_pid(argv[1]);
	if (pid == -1)
	{
		ft_printf("Please enter a valid pid\n");
		return (2);
	}
	act.sa_handler = &handler;
	//act.sa_sigaction = &handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGUSR1, &act, NULL);
	send_signals(argv[2], pid);
	return (0);
}
