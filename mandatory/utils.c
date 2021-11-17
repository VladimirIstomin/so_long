/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:08:48 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/17 16:18:11 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_puterror(char *error)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error, 2);
	ft_putchar_fd('\n', 2);
}

int	exit_game(t_game *game, char *error)
{
	mlx_destroy_window(game->mlx, game->win);
	free_map(game->map);
	if (error)
		ft_puterror(error);
	exit(0);
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

void	print_n_movemets(int movements)
{
	ft_putstr_fd("Number of movements: ", 1);
	ft_putnbr_fd(movements, 1);
	ft_putchar_fd('\n', 1);
}
