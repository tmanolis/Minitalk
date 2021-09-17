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
	int 	*stock;

	i = 0;
	stock = (char *)malloc(sizeof(char) * (8 + 1));
	if (!stock)
	{
		ft_putstr_fd("ERROR\n", 2);
		exit(1);
	}
	while (i < 8)
	{
		if (signum == SIGUSR1)
			stock[i] = 1;
		else if (signum == SIGUSR2)
			stock[i] = 0;
		i++;
	}
	convert_bits_to_char(stock);
}

int	main(void)
{
	struct	sigaction sa;
	int		i;

	sa.sa_handler = ft_handler;
	sa.sa_flags = 0;
	i = 0;
	print_pid();
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		// i++;
		// if (i == 7)
		// {
		// 	i = 0;
		// 	ft_putstr_fd("\n", 1);
		// }
	}
	return (0);
}