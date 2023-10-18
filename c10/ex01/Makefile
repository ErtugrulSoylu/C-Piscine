SRC = main.c
OBJS = ${SRC:.c=.o}
GCC = gcc -Wall -Werror -Wextra
NAME = ft_cat

all: ${NAME}

%.o: %.c
	${GCC} -c $< -o $@

${NAME}: ${OBJS}
	${GCC} -o ${NAME} ${OBJS}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re:	fclean all
