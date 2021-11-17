/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_collectibles_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:45:26 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/17 13:40:15 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validators_bonus.h"

int	validate_collectibles(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == MAP_COLLECTIBLE)
				return (1);
			j++;
		}
		i++;
	}
	ft_puterror(ERROR_NO_COLLECTIBLES);
	return (0);
}
