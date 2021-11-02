/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:41:26 by tmanolis          #+#    #+#             */
/*   Updated: 2021/11/02 14:31:57 by tmanolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h> 

# ifdef __MACH__
#  define TIME 100
# elif __APPLE__
#  define TIME 100
# elif __linux__
#  define TIME 400
# endif

// UTILS SERVER
size_t	ft_strlen(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_initialize(void);
// UTILS CLIENT
int		ft_isdigit(int c);
int		ft_atoi(const char *str);

#endif