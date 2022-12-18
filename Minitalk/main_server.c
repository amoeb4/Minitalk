/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniclient.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:26:21 by dafranco          #+#    #+#             */
/*   Updated: 2022/12/17 18:42:39 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include "minitalk.h"
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

void	sighandler(int signum)
{
	if (signum == SIGUSR1)
		printf("Signal 0 is here\n");
	if (signum == SIGUSR2)
		printf("Signal 1 is here\n");
}

int	main(void)
{
	struct sigaction	act;
	int					i;

	i = 0;
	printf("%d\n", getpid());
	signal(SIGINT, sighandler);
	while (1)
	{
		printf("No signal\n");
		sleep(5);
	}
	return (0);
}
