/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_player_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:32:25 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/17 13:40:31 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validators_bonus.h"

static int	handle_many_players_error(void)
{
	ft_puterror(ERROR_MANY_PLAYERS);
	return (0);
}

static int	handle_no_players_error(void)
{
	ft_puterror(ERROR_NO_PLAYERS);
	return (0);
}

int	validate_player(char **map)
{
	int	n_players;
	int	i;
	int	j;

	n_players = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == MAP_PLAYER)
				n_players++;
			if (n_players > 1)
				return (handle_many_players_error());
			j++;
		}
		i++;
	}
	if (n_players == 0)
		return (handle_no_players_error());
	return (1);
}
