/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:08:48 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/15 15:38:58 by gmerlene         ###   ########.fr       */
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

int	free_game(t_game *game)
{
	if (!game)
		return (-1);
	free_map(game->map);
	if (!game->sprites)
		free(game->sprites);
	if (game->player_position)
		free(game->player_position);
	free(game);
	return (0);
}

int	free_vars(t_vars *vars)
{
	if (!vars)
		return (-1);
	free_game(vars->game);
	free(vars);
	return (0);
}

void	print_n_movemets(int movements)
{
	ft_putstr_fd("Number of movements: ", 1);
	ft_putnbr_fd(movements, 1);
	ft_putchar_fd('\n', 1);
}
