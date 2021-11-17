/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:40:52 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/17 16:20:17 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define ERROR_AGRC "Incorrect number of arguments."
# define ERROR_MAP_PARSING "Cannot parse the map, check its filename."
# define ERROR_PARSE_SPRITE "Sprite parsing wasn't successful, check files."

# define MAP_WALL '1'
# define MAP_COLLECTIBLE 'C'
# define MAP_EXIT 'E'
# define MAP_PLAYER 'P'
# define MAP_EMPTY_SPACE '0'
# define MAP_ENEMY 'Z'

# define PATH_WALL "./bonus/textures/wall.xpm"
# define PATH_ORE "./bonus/textures/collectible.xpm"
# define PATH_EXIT_OPEN "./bonus/textures/exit_open.xpm"
# define PATH_EXIT_CLOSED "./bonus/textures/exit_closed.xpm"
# define PATH_PLAYER "./bonus/textures/steve.xpm"
# define PATH_EMPTY "./bonus/textures/empty.xpm"
# define PATH_ENEMY_0 "./bonus/textures/enemy/lava_0.xpm"
# define PATH_ENEMY_1 "./bonus/textures/enemy/lava_1.xpm"
# define PATH_ENEMY_2 "./bonus/textures/enemy/lava_2.xpm"
# define PATH_ENEMY_3 "./bonus/textures/enemy/lava_3.xpm"
# define PATH_ENEMY_4 "./bonus/textures/enemy/lava_4.xpm"
# define PATH_ENEMY_5 "./bonus/textures/enemy/lava_5.xpm"
# define PATH_ENEMY_6 "./bonus/textures/enemy/lava_6.xpm"
# define PATH_ENEMY_7 "./bonus/textures/enemy/lava_7.xpm"
# define PATH_ENEMY_8 "./bonus/textures/enemy/lava_8.xpm"
# define PATH_ENEMY_9 "./bonus/textures/enemy/lava_9.xpm"

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# define TILE_RESOLUTION 64

# define WON_GAME "You've finished the game with total number of movements: "
# define LOST_GAME "You've drowned in lava!!"

# include <stdio.h>
# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include "mlx.h"

typedef struct s_enemy {
	void	**sprites;
	int		sprite_index;
}			t_enemy;

typedef struct s_game {
	void	*mlx;
	void	*win;
	void	*wall;
	void	*collectible;
	void	*exit_closed;
	void	*exit_open;
	void	*player;
	void	*empty_space;
	char	**map;
	t_enemy	*enemy;
	int		n_collectibles;
	int		is_exit_open;
	int		player_x;
	int		player_y;
	char	under_player;
	int		movements;
}			t_game;

char	**create_map(char *file_name);
int		validate_map(char **map);
int		validate_map_extension(char *file_name);
void	ft_puterror(char *error);
void	init_hooks(t_game *game);
void	init_mlx_window(t_game *game);
void	init_game(t_game *game, char *map_file);
void	render_window(t_game *game);
int		animate_enemies(t_game *game);
int		free_game(t_game *game);
int		free_map(char **map);
int		exit_game(t_game *game, char *error);
void	print_n_movemets(t_game *game);
void	handle_move(t_game *game, int keycode);

#endif
