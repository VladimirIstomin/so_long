SRCS			= main.c

OBJ_DIR			= obj/

OBJS			= $(addprefix ${OBJ_DIR}, ${SRCS:.c=.o})

DEPS			= $(addprefix ${OBJ_DIR}, ${SRCS:.c=.d})

NAME			= so_long

LIBFT			= ./libft/libft.a

CC				= gcc

FLAGS			= -Wall -Werror -Wextra -O3 -MMD

${OBJ_DIR}%.o: 	%.c
				${CC} ${FLAGS} -Imlx -c $< -o $@

all:			${OBJ_DIR} ${NAME}

${LIBFT}:		FORCE
				@${MAKE} -C libft all

${OBJ_DIR}:
				@mkdir -p ${OBJ_DIR}

${NAME}:		${OBJS} ${LIBFT}
				${CC} ${OBJS} -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME} -Llibft -lft

FORCE:			;

clean:
				@${MAKE} -C libft clean
				@rm -rf ${OBJ_DIR}
				@echo "Clean: Done."

fclean:			clean
				@${MAKE} -C libft fclean
				@rm -f ${NAME}
				@echo "Fclean: Done."

re:				fclean all

.PHONY:			all FORCE clean fclean re

-include 		${DEPS}
