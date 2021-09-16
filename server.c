/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:45:57 by tmanolis          #+#    #+#             */
/*   Updated: 2021/09/16 14:04:13 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void my_handler(int signum)
{
    if (signum == SIGUSR1)
        printf("Received SIGUSR1!\n");
}

int	main(void)
{
	int	pid;

	pid = getpid();
	if (pid != -1)
		ft_putnbr_fd(pid, 1);
	while (1)
	{
		signal(SIGUSR1, my_handler);
	}
	return (0);
}