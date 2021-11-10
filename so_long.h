/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:40:52 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/10 18:43:13 by gmerlene         ###   ########.fr       */
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

# include <stdio.h>
# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>

typedef struct s_vars {
	void	*mlx;
	void	*win;
	char	**map;
}			t_vars;

char	**parse_map(int fd);
int		validate_map(char **map);
void	free_map(char **map);
int		validate_map_extension(char *file_name);
void	ft_puterror(char *error);
void	init_hooks(t_vars *vars);
void	init_mlx(t_vars *vars);

#endif
