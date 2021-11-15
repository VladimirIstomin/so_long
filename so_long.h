/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:40:52 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/15 15:28:49 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define ERROR_AGRC "Incorrect number of arguments."
# define ERROR_MAP_PARSING "Cannot parse the map, check its filename."

# define MAP_WALL '1'
# define MAP_COLLECTIBLE 'C'
# define MAP_EXIT 'E'
# define MAP_PLAYER 'P'
# define MAP_EMPTY_SPACE '0'

# define PATH_WALL "./textures/wall.xpm"
# define PATH_ORE "./textures/ore/ore_0.xpm"
# define PATH_EXIT_OPEN "./textures/exit_open.xpm"
# define PATH_EXIT_CLOSED "./textures/exit_closed.xpm"
# define PATH_PLAYER "./textures/steve.xpm"
# define PATH_EMPTY "./textures/empty.xpm"

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# define TILE_RESOLUTION 64

# define FINISH_GAME "You've finished the game with total number of movements: "

# include <stdio.h>
# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include "mlx.h"

typedef struct s_player_pos
{
	int	x;
	int	y;
}		t_player_pos;

typedef struct s_sprites
{
	void	*wall;
	void	*collectible;
	void	*exit_closed;
	void	*exit_open;
	void	*player;
	void	*empty_space;
}			t_sprites;

typedef struct s_game {
	char			**map;
	t_sprites		*sprites;
	int				n_collectibles;
	int				is_exit_open;
	t_player_pos	*player_position;
	char			under_player;
	int				movements;
}					t_game;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_game	*game;
}			t_vars;

char	**parse_map(int fd);
int		validate_map(char **map);
int		validate_map_extension(char *file_name);
void	ft_puterror(char *error);
void	init_hooks(t_vars *vars);
void	init_mlx_window(t_vars *vars);
t_game	*init_game(void *mlx, char *map_file);
void	render_window(t_vars *vars);
int		free_map(char **map);
int		free_game(t_game *game);
int		free_vars(t_vars *vars);
int		exit_game(t_vars *vars);
void	print_n_movemets(int movements);
void	handle_move(t_vars *vars, int keycode);

#endif
