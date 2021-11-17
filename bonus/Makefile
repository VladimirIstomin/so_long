SRCS			= main_bonus.c utils_bonus.c create_map_bonus.c\
				validate_map_bonus.c validate_map_extension_bonus.c\
				map_validators/validate_collectibles_bonus.c\
				map_validators/validate_exits_bonus.c\
				map_validators/validate_map_chars_bonus.c\
				map_validators/validate_map_shape_bonus.c\
				map_validators/validate_player_bonus.c\
				map_validators/validate_walls_bonus.c\
				init_mlx_window_bonus.c init_hooks_bonus.c init_game_bonus.c\
				render_window_bonus.c move_handlers_bonus.c

OBJ_DIR			= obj/

OBJS			= $(addprefix ${OBJ_DIR}, ${SRCS:.c=.o})

DEPS			= $(addprefix ${OBJ_DIR}, ${SRCS:.c=.d})

NAME			= so_long

LIBFT			= ../libft/libft.a

HEADERS			= so_long_bonus.h map_validators/map_validators_bonus.h

CC				= gcc

FLAGS			= -Wall -Werror -Wextra -O3 -MMD

FLAGS_DEV		= -Wall -Werror -Wextra -g3 -MMD

${OBJ_DIR}%.o: 	%.c
				${CC} ${FLAGS_DEV} -I/usr/local/include -c $< -o $@

all:			${OBJ_DIR} ${NAME}

${LIBFT}:		FORCE
				@${MAKE} -C ../libft all

${OBJ_DIR}:
				@mkdir -p ${OBJ_DIR}
				@mkdir -p ${OBJ_DIR}/map_validators

${NAME}:		${OBJS} ${LIBFT} ${HEADERS}
				${CC} ${OBJS} -L/usr/local/bin -lmlx -framework OpenGL -framework AppKit -o ${NAME} -L../libft -lft
				cp ${NAME} ../
				

FORCE:			;

clean:
				@${MAKE} -C ../libft clean
				@rm -rf ${OBJ_DIR}
				@echo "Clean: Done."

fclean:			clean
				@${MAKE} -C ../libft fclean
				@rm -f ../${NAME}
				@rm -f ${NAME}
				@echo "Fclean: Done."

re:				fclean all

.PHONY:			all FORCE clean fclean re

-include 		${DEPS}
