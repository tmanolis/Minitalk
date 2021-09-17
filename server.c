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

void	convert_bits_to_char(char *str)
{
	int nb_binary;


}

void	ft_handler(int signum)
{
	size_t	i;
	char 	c;

	i = 0;
	// result |= (num[i] == '1') << (7 - i);
	while (i < 8)
	{
		if (signum == SIGUSR1)
			stock[i] = 1;
		else if (signum == SIGUSR2)
			stock[i] = 0;
		i++;
	}
	c
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