/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validators.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:28:09 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/09 16:38:44 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_VALIDATORS_H
# define MAP_VALIDATORS_H

# define ERROR_INVALID_CHAR "Invalid char(s) in the map file."
# define ERROR_NO_EXITS "No exits in the map."
# define ERROR_NO_PLAYERS "No player in the map."
# define ERROR_MANY_PLAYERS "More than one player in the map."
# define ERROR_NO_COLLECTIBLES "No collectibles in the map."
# define ERROR_NO_SOLID_WALL "The map doesn't have solid walls."
# define ERROR_INVALID_MAP_SHAPE "The map doesn't have rectangular shape."
# define ERROR_INVALID_MAP_EXTENSION "The map file doesn't have .ber extension."

# include "../so_long.h"
# include "../libft/libft.h"

int	validate_collectibles(char **map);
int	validate_exits(char **map);
int	validate_map_chars(char **map);
int	validate_map_shape(char **map);
int	validate_player(char **map);
int	validate_walls(char **map);

#endif
