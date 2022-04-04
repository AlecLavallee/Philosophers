SRCS = ./eat.c \
				./think.c \
				./sleep.c \
				./hilo.c \
				./utils.c \
				./main.c

OBJS =	${SRCS:.c=.o}

NAME =			philo

CC =		clang
CFLAGS =	-Wall -Wextra -Werror
RM = 		rm -rf

all: 		${NAME}

.c.o:
			${CC} ${CFLAGS} -I${INCLUDE} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -I${INCLUDE} -o ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:	clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		bonus all clean fclean re