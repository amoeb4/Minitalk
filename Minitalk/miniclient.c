/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniclient.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:26:21 by dafranco          #+#    #+#             */
/*   Updated: 2022/12/17 19:43:08 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include "minitalk.h"
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int	sighandler_1(int signum)
{
	if (signum == SIGUSR1)
		printf("Signal 0 is here\n");
	return (signum);
}

int	sighandler_2(int signum)
{
	if (signum == SIGUSR2)
		printf("Signal 1 is here\n");
	return (signum);
}

int	main(void)
{
	struct sigaction	act;
	int					i;

	i = 0;
	printf("%d\n", getpid());
	while (1)
	{
		if (!&signal)
		{
			printf("No signal\n");
			usleep(50000);
		}
		if (signal(SIGINT, sighandler))
		{
			signal(SIGINT, sighandler);
		}
		if (signal(SIGINT, sighandler))
		{
			signal(SIGINT, sighandler);
		}
	}
	return (0);
}
