SRCS			= main.c

OBJ_DIR			= obj/

OBJS			= $(addprefix ${OBJ_DIR}, ${SRCS:.c=.o})

DEPS			= $(addprefix ${OBJ_DIR}, ${SRCS:.c=.d})

NAME			= so_long

CC				= gcc

FLAGS			= -Wall -Werror -Wextra -O3 -MMD

${OBJ_DIR}%.o: 	%.c
				${CC} ${FLAGS} -Imlx -c $< -o $@

all:			${OBJ_DIR} ${NAME}

${OBJ_DIR}:
				@mkdir -p ${OBJ_DIR}

${NAME}:		${OBJS}
				${CC} ${OBJS} -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}

clean:
				rm -rf ${OBJ_DIR}

fclean:			clean
				rm -f ${NAME}

re:				fclean all

.PHONY:			all clean fclean re

-include 		${DEPS}