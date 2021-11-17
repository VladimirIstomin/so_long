/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:08:48 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/17 15:32:03 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_puterror(char *error)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error, 2);
	ft_putchar_fd('\n', 2);
}

int	free_game(t_game *game)
{
	free_map(game->map);
	if (game->enemy)
	{
		if (game->enemy->sprites)
			free(game->enemy->sprites);
		free(game->enemy);
	}
	return (0);
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

void	print_n_movemets(t_game *game)
{
	char	*movements;

	movements = ft_itoa(game->movements);
	mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFF, "Movements: ");
	mlx_string_put(game->mlx, game->win, 120, 10, 0xFFFFFF, movements);
	free(movements);
}
