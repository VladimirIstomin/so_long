/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_shape.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:27:55 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/09 15:07:52 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validators.h"

int	validate_map_shape(char **map)
{
	int	line_len;
	int	line_len_tmp;
	int	i;

	line_len = 0;
	i = 0;
	while (map[i])
	{
		line_len_tmp = ft_strlen(map[i]);
		if (map[i][line_len_tmp - 1] == '\n')
			line_len_tmp--;
		if (!line_len)
			line_len = line_len_tmp;
		else if (line_len != line_len_tmp)
		{
			ft_puterror(ERROR_INVALID_MAP_SHAPE);
			return (0);
		}
		i++;
	}
	return (1);
}
