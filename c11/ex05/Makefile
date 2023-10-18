NAME = do-op
SRCS = main.c
OBJS = main.o
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
	gcc -o ${NAME} ${OBJS}

clean:
	rm	-f ${OBJS}

fclean: clean
	rm -f ${NAME}

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

re: fclean all
