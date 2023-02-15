FILES =	pipex.c pipex_pt2.c

# OBJS = ${FILES:.c=.o}

NAME = pipex
# wait pour entre 1er et 2 eme commande
CC = cc

INCLUDE = -I ./ -I ./libft 
LIB = -L ./libft -lft

CFLAGS = -Wall -Wextra -Werror


OBJS_PATH = objs
OBJS = ${patsubst %.c, ${OBJS_PATH}/%.o, ${SRCS}}

${OBJS}: ${OBJS_PATH}/%.o: %.c *.h Makefile
		mkdir -p ${OBJS_PATH}
		${CC} ${CFLAGS} -g -c $< -o $@ -I ${INCLUDE}



${NAME}: 	${OBJS}
		+${MAKE} -C ./libft/
		${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIB} ${INCLUDE} 

all:	${NAME}


clean:	
		+${MAKE} -C ./libft/ clean
		rm -f ${OBJS}
		rm -f ${OBJSBONUS}
		rm -rf *.d

fclean:	clean;
		+${MAKE} -C ./libft/ fclean
		rm -f ${NAME}
		rm -f ${NAMEBONUS}

re:	fclean all


.PHONY: all clean fclean re