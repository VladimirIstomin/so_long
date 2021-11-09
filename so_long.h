/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:40:52 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/09 16:29:42 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define ERROR_AGRC "Incorrect number of arguments."

# include <stdio.h>
# include "libft/libft.h"
# include <errno.h>
# include <fcntl.h>

# define MAP_WALL '1'
# define MAP_COLLECTIBLE 'C'
# define MAP_EXIT 'E'
# define MAP_PLAYER 'P'
# define MAP_EMPTY_SPACE '0'

char	**parse_map(int fd);
int		validate_map(char **map);
int		validate_map_extension(char *file_name);
void	ft_puterror(char *error);

#endif
