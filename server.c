/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:45:57 by tmanolis          #+#    #+#             */
/*   Updated: 2021/09/17 15:32:34 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	print_pid(void)
{
	int pid;
	
	pid = getpid();
	if (pid != -1)
	{
		ft_putstr_fd("PID : ", 1);
		ft_putnbr_fd(pid, 1);
		ft_putchar_fd('\n', 1);
	}
	else
		ft_putstr_fd("Couldn't get the PID\n", 2);
}

void ft_handler(int signum)
{
    if (signum == SIGUSR1)
        printf("Received 1\n");
	else if (signum == SIGUSR2)
		printf("Received 0\n");
}

int	main(void)
{
	struct	sigaction sa;

	sa.sa_handler = ft_handler;
	sa.sa_flags = 0;
	print_pid();
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
	}
	return (0);
}