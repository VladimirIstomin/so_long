/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:25:39 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/09 16:47:12 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validators/map_validators.h"

int	validate_map(char **map)
{
	return (
		validate_walls(map)
		&& validate_exits(map)
		&& validate_collectibles(map)
		&& validate_player(map)
		&& validate_map_shape(map)
		&& validate_map_chars(map)
	);
}
