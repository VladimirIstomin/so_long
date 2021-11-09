/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_exits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:29:32 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/09 16:14:47 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validators.h"

int	validate_exits(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == MAP_EXIT)
				return (1);
			j++;
		}
		i++;
	}
	ft_puterror(ERROR_NO_EXITS);
	return (0);
}
