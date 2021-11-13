/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:08:48 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/13 12:57:42 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_puterror(char *error)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error, 2);
	ft_putchar_fd('\n', 2);
}

int	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return (-1);
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (0);
}

int	free_game_config(t_game_config *game_config)
{
	if (!game_config)
		return (-1);
	free_map(game_config->map);
	if (!game_config->sprites)
		free(game_config->sprites);
	free(game_config);
	return (0);
}

int	free_vars(t_vars *vars)
{
	if (!vars)
		return (-1);
	free_game_config(vars->game_config);
	free(vars);
	return (0);
}
