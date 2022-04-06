SRCS = ./philo.c \
			./utils.c \
			./close.c \
			./eat.c \
			./data.c \
			./time.c				

OBJS =	${SRCS:.c=.o}

NAME =			philo

CC =		clang
CFLAGS =	-Wall -Wextra -Werror
RM = 		rm -rf

all: 		${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:	clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		bonus all clean fclean re