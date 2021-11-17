/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_chars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:01:29 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/11 16:43:49 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validators.h"

static int	check_valid_char(char **map, int i, int j)
{
	if (
		map[i][j] == MAP_EXIT
		|| map[i][j] == MAP_WALL
		|| map[i][j] == MAP_PLAYER
		|| map[i][j] == MAP_COLLECTIBLE
		|| map[i][j] == MAP_EMPTY_SPACE
	)
		return (1);
	ft_puterror(ERROR_INVALID_CHAR);
	return (0);
}

int	validate_map_chars(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!check_valid_char(map, i, j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
