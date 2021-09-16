/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:45:57 by tmanolis          #+#    #+#             */
/*   Updated: 2021/09/16 16:20:03 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void ft_handler(int signum)
{
    if (signum == SIGUSR1)
        printf("Received SIGUSR1!\n");
	if (signum == SIGUSR2)
		printf("Received SIGUSR2!\n");
}

int	main(void)
{
	struct	sigaction sa;
	int		pid;

	sa.sa_handler = ft_handler;
	pid = getpid();
	if (pid != -1)
	{
		ft_putnbr_fd(pid, 1);
		ft_putchar_fd('\n', 1);
	}
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
	}
	return (0);
}