/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:08:07 by dafranco          #+#    #+#             */
/*   Updated: 2023/01/11 11:58:41 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include "minitalk.h"

int	stock_length(int i)
{
	static int	len = 0;

	if (i == 3)
		return (len);
	if (i == 1 && len < 1)
		len--;
	if (i == 0)
	{
		len *= -1;
		return (len);
	}
	return (len);
}

void	sig_handler_len(int signum)
{
	if (signum == SIGUSR1)
		stock_length(1);
	if (signum == SIGUSR2)
		stock_length(0);
	return ;
}

void	sig_handler(int signum)
{
	if (signum == SIGUSR1)
		printf("Signal 0 is here\n");
	if (signum == SIGUSR2)
		printf("Signal 1 is here\n");
	return ;
}

int	main(void)
{
	struct sigaction	sig;
	int					k;

	k = 0;
	sig.sa_handler = sig_handler_len;
	printf("%d\n", getpid());
	while (1)
	{
		if (k > 0)
			printf("%d\n", k);
		usleep(1000000);
		sigaction(SIGUSR2, &sig, NULL);
		sigaction(SIGUSR1, &sig, NULL);
		k = stock_length(3);
		if (k > 0)
			sig.sa_handler = sig_handler;
	}
	return (0);
}
