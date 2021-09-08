# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmanolis <tmanolis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/08 15:56:47 by tmanolis          #+#    #+#              #
#    Updated: 2021/09/08 16:15:30 by tmanolis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_1 = server.c			\
	ft_utils.c				\

SRCS_2 = ft_utlis.c			\

OBJS_1 = ${SRCS_1:.c=.o}

OBJS_2 = ${SRCS_2:.c=.o}

NAME_1 = server

NAME_2 = client

CC = gcc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
			
${NAME_1}:	${OBJS_1}
			${CC} ${CFLAGS} ${OBJS_1} -o ${NAME_1}

# ${NAME_2}:	${OBJS_2}
# 			${CC} ${CFLAGS} ${OBJS_2} -o ${NAME_2}

all:		${NAME_1} ${NAME_2}

clean:
			${RM} ${OBJS_1} ${OBJS_2}

fclean:		clean
			${RM} ${NAME_1} ${NAME_2}

re:			fclean all

.PHONY:		all clean fclean re