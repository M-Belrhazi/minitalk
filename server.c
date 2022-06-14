/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbelrhaz <mbelrhaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 22:24:24 by mbelrhaz          #+#    #+#             */
/*   Updated: 2022/06/13 21:20:44 by mbelrhaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include "libftprintf/libftprintf.h"

void	fillstr(char c, int pid);

void	handler(int signum, siginfo_t *info, void *ucontext)
{
	static int	i;
	static int	tab[8];
	char		c;
	static int	nb = 1;

	(void)ucontext;
	if (signum == SIGUSR1)
		tab[i] = 0 * nb;
	else
		tab[i] = 1 * nb;
	if (i == 7)
	{
		i = 0;
		nb = 1;
		c = tab[0] | tab[1] | tab[2] | tab[3]
			| tab[4] | tab[5] | tab[6] | tab[7];
		fillstr(c, info->si_pid);
		kill(info->si_pid, SIGUSR1);
		return ;
	}
	i++;
	nb = nb * 2;
	kill(info->si_pid, SIGUSR1);
}

char	*ft_create_one_char_str(char c)
{
	char	*one;

	one = ft_strdup("i");
	if (!one)
		return (NULL);
	one[0] = c;
	return (one);
}

void	fillstr(char c, int pid)
{
	static char	*superstr;
	char		*one;

	if (!superstr)
	{
		superstr = ft_strdup("i");
		if (!superstr)
			return ;
		superstr[0] = c;
		return ;
	}
	if (c == 0)
	{
		ft_printf("%s\n", superstr);
		free(superstr);
		superstr = NULL;
		kill(pid, SIGUSR2);
		return ;
	}
	one = ft_create_one_char_str(c);
	if (!one)
		return ;
	superstr = ft_strjoin(superstr, one);
	if (!superstr)
		return ;
}

int	main(void)
{
	int					pid;
	struct sigaction	act;

	pid = getpid();
	act.sa_sigaction = &handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	ft_printf("%i\n", pid);
	ft_printf("Waiting for signals...\n");
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
	{
		sleep(1);
	}
}
