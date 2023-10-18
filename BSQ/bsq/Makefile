SRC = srcs/main.c srcs/utils.c srcs/utils2.c srcs/solution.c srcs/control.c
OBJS = ${SRC:.c=.o}
INC = include
GCC = gcc -Wall -Werror -Wextra
NAME = bsq

all: ${NAME}

%.o: %.c
	${GCC} -c $< -o $@ -I${INC}

${NAME}: ${OBJS}
	${GCC} -o ${NAME} ${OBJS}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re:	fclean all
