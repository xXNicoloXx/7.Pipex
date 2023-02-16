FILES =	pipex.c pipex_pt2.c
FILES_PATH = src/

OBJS_PATH = objs
OBJS = ${patsubst %.c, ${OBJS_PATH}/%.o, ${FILES}}

INCLUDE = -I ./src/inc
INCLUDE_LIBFT = -I ./libft

LIB = -L ./libft -lft

CFLAGS = -Wall -Wextra -Werror -g
NAME = pipex
CC = cc

vpath %.c ${FILES_PATH}

all:	${NAME}

${OBJS}: ${OBJS_PATH}/%.o: %.c Makefile ./src/inc/pipex.h
		mkdir -p ${OBJS_PATH}
		${CC} ${CFLAGS} -c $< -o $@ ${INCLUDE} ${INCLUDE_LIBFT}

${NAME}: 	${OBJS}
		+${MAKE} -C ./libft/
		${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIB} ${INCLUDE} ${INCLUDE_LIBFT}

clean:	
		+${MAKE} -C ./libft/ clean
		rm -rf ${OBJS_PATH}

fclean:	clean;
		+${MAKE} -C ./libft/ fclean
		rm -f ${NAME}
		rm -f ${NAMEBONUS}

re:	fclean all

.PHONY: all clean fclean re