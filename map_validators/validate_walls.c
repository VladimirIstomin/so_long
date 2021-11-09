/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:29:43 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/09 16:11:24 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validators.h"

static int	check_solid_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!line[i + 1] && line[i] == '\n')
			return (1);
		else if (line[i] != MAP_WALL)
			return (0);
		i++;
	}
	return (1);
}

static int	check_side_wall(char *line)
{
	int	last_char_index;

	last_char_index = (int)ft_strlen(line) - 1;
	if (line[last_char_index] == '\n')
		last_char_index--;
	return (line[0] == MAP_WALL && line[last_char_index] == MAP_WALL);
}

int	validate_walls(char **map)
{
	int	i;
	int	res;

	i = 0;
	res = 1;
	while (map[i])
	{
		if (i == 0 || !map[i + 1])
			res = check_solid_wall(map[i]);
		else
			res = check_side_wall(map[i]);
		if (!res)
		{
			ft_puterror(ERROR_NO_SOLID_WALL);
			return (0);
		}
		i++;
	}
	return (1);
}
