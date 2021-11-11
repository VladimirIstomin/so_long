/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:40:52 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/11 16:31:58 by gmerlene         ###   ########.fr       */
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

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# define TILE_RESOLUTION 64

# include <stdio.h>
# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>

typedef struct s_game_config {
	char	**map;
	int		n_collectibles;
	int		is_exit_open;
	int		player_x;
	int		player_y;
}			t_game_config;

typedef struct s_vars {
	void			*mlx;
	void			*win;
	t_game_config	*game_config;
}					t_vars;

char			**parse_map(int fd);
int				validate_map(char **map);
int				validate_map_extension(char *file_name);
void			ft_puterror(char *error);
void			init_hooks(t_vars *vars);
void			init_mlx(t_vars *vars);
t_game_config	*init_game_config(char *map_file);
int				free_map(char **map);
int				free_game_config(t_game_config *game_config);
int				free_vars(t_vars *vars);

#endif
