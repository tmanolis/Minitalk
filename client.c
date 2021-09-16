/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 17:16:26 by tmanolis          #+#    #+#             */
/*   Updated: 2021/09/16 16:48:31 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	pid_t pid;

	if (argc > 1)
	{
		pid = ft_atoi(argv[1]);
		kill(pid, SIGUSR2);
	}
	return (0);
}