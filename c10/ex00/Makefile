SRC = main.c
OBJS = ${SRC:.c=.o}
GCC = gcc -Wall -Werror -Wextra
NAME = ft_display_file

all: ${NAME}

%.o: %.c
	${GCC} -c $< -o $@

${NAME}: ${OBJS}
	${GCC} -o ${NAME} ${OBJS}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}
