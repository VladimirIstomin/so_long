SRCS			= main.c utils.c parse_map.c\
				validate_map.c validate_map_extension.c\
				map_validators/validate_collectibles.c\
				map_validators/validate_exits.c\
				map_validators/validate_map_chars.c\
				map_validators/validate_map_shape.c\
				map_validators/validate_player.c\
				map_validators/validate_walls.c\
				init_mlx_window.c init_hooks.c init_game.c\
				render_window.c move_handlers.c

OBJ_DIR			= obj/

OBJS			= $(addprefix ${OBJ_DIR}, ${SRCS:.c=.o})

DEPS			= $(addprefix ${OBJ_DIR}, ${SRCS:.c=.d})

NAME			= so_long

LIBFT			= ./libft/libft.a

HEADERS			= so_long.h map_validators/map_validators.h

CC				= gcc

FLAGS			= -Wall -Werror -Wextra -O3 -MMD

FLAGS_DEV		= -Wall -Werror -Wextra -g3

${OBJ_DIR}%.o: 	%.c
				${CC} ${FLAGS_DEV} -I/usr/local/include -c $< -o $@

all:			${OBJ_DIR} ${NAME}

${LIBFT}:		FORCE
				@${MAKE} -C libft all

${OBJ_DIR}:
				@mkdir -p ${OBJ_DIR}
				@mkdir -p ${OBJ_DIR}/map_validators

${NAME}:		${OBJS} ${LIBFT} ${HEADERS}
				${CC} ${OBJS} -L/usr/local/bin -lmlx -framework OpenGL -framework AppKit -o ${NAME} -Llibft -lft

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
