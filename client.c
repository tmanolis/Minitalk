/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 17:16:26 by tmanolis          #+#    #+#             */
/*   Updated: 2021/09/17 15:23:43 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	convert_char_to_bin(char c, pid_t pid)
{
	int i;

	i = 7;
	while(i >= 0)
	{
		if (c & (1 << i))
		{
			kill(pid, SIGUSR1);
			usleep(TIME);
		}
		else
		{
			kill(pid, SIGUSR2);
			usleep(TIME);
		}	
		i--;
	}
}

int		main(int argc, char **argv)
{
	int i;
	pid_t pid;

	i = 0;
	if (argc > 1)
	{
		pid = ft_atoi(argv[1]);
	}
	if (argc == 3)
	{
		while(argv[2][i] != '\0')
		{
			convert_char_to_bin(argv[2][i], pid);
			i++;
		}
	}
	return (0);
}