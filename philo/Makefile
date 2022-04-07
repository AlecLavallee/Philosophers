SRCS = ./srcs/philo.c \
			./srcs/utils.c \
			./srcs/close.c \
			./srcs/eat.c \
			./srcs/data.c \
			./srcs/time.c				

OBJS =	${SRCS:.c=.o}

NAME =			philo

CC =		clang
CFLAGS =	-Wall -Wextra -Werror
RM = 		rm -rf

all: 		${NAME}

.c.o:
			${CC} ${CFLAGS} -I include/ -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -I include/ -o ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:	clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		bonus all clean fclean re