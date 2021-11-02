# *--------- SOURCES ---------*

SRCS_1 = server.c						\
	ft_utils_server.c					\

SRCS_2 = client.c						\
		ft_utils_client.c				\

OBJS_1 = ${SRCS_1:.c=.o}

OBJS_2 = ${SRCS_2:.c=.o}

# *--------- Bonus ---------*

BONUS_1 = ./bonus/server_bonus.c		\
	./bonus/ft_utils_server_bonus.c		\

BONUS_2 = ./bonus/client_bonus.c		\
		./bonus/ft_utils_client_bonus.c	\

OBJS_BONUS_1 = ${BONUS_1:.c=.o}

OBJS_BONUS_2 = ${BONUS_2:.c=.o}

# *--------- OTHERS ---------*

NAME = server

NAME_2 = client

NAME_BONUS = server_bonus

NAME_BONUS_2 = client_bonus

CC = gcc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror

# *========= RULES =========*

all:		${NAME} ${NAME_2}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
			
${NAME}:	${OBJS_1}
			${CC} ${CFLAGS} ${OBJS_1} -o ${NAME}

${NAME_2}:	${OBJS_2}
			${CC} ${CFLAGS} ${OBJS_2} -o ${NAME_2}

bonus :		${NAME_BONUS} ${NAME_BONUS_2}

${NAME_BONUS}:	${OBJS_BONUS_1}
				${CC} ${CFLAGS} ${OBJS_BONUS_1} -o ${NAME_BONUS}

${NAME_BONUS_2}:	${OBJS_BONUS_2}
					${CC} ${CFLAGS} ${OBJS_BONUS_2} -o ${NAME_BONUS_2}

clean:
			${RM} ${OBJS_1} ${OBJS_2} ${OBJS_BONUS_1} ${OBJS_BONUS_2}

fclean:		clean
			${RM} ${NAME} ${NAME_2} ${NAME_BONUS} ${NAME_BONUS_2}

re:			fclean all

.PHONY:		all clean fclean re bonus