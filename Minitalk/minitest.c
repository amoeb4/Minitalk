/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:26:22 by dafranco          #+#    #+#             */
/*   Updated: 2022/12/17 19:20:34 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include "minitalk.h"
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

pid_t	getpid(void);
int		kill(pid_t pid, int sig);

int	main(int argc, char **argv)
{
	while (1)
	{
		printf("client up\n");
		sleep(5);
		if (argc == 2)
			kill(ft_atoi(argv[1]), SIGUSR1);
		if (argc == 3)
			kill(ft_atoi(argv[1]), SIGUSR2);
	}
	return (0);
}
