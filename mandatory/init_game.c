/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:19:13 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/15 14:38:52 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_number_of_collectibles(char **map)
{
	int	i;
	int	j;
	int	number_of_collectibles;

	i = 0;
	number_of_collectibles = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == MAP_COLLECTIBLE)
				number_of_collectibles++;
			j++;
		}
		i++;
	}
	return (number_of_collectibles);
}

static void	init_player_position(t_game *game)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = game->map;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == MAP_PLAYER)
			{
				game->player_y = i;
				game->player_x = j;
			}
			j++;
		}
		i++;
	}
}

static void	init_sprites(t_game *game)
{
	int		w;
	int		h;
	void	*mlx;

	mlx = game->mlx;
	game->wall = mlx_xpm_file_to_image(mlx, PATH_WALL, &w, &h);
	game->collectible = mlx_xpm_file_to_image(mlx, PATH_ORE, &w, &h);
	game->exit_open = mlx_xpm_file_to_image(mlx, PATH_EXIT_OPEN, &w, &h);
	game->exit_closed = mlx_xpm_file_to_image(mlx, PATH_EXIT_CLOSED, &w, &h);
	game->player = mlx_xpm_file_to_image(mlx, PATH_PLAYER, &w, &h);
	game->empty_space = mlx_xpm_file_to_image(mlx, PATH_EMPTY, &w, &h);
}

void	init_game(t_game *game, char *map_file)
{
	game->map = create_map(map_file);
	if (!game->map)
		return ;
	init_sprites(game);
	init_player_position(game);
	game->is_exit_open = 0;
	game->movements = 0;
	game->under_player = MAP_EMPTY_SPACE;
	game->n_collectibles = get_number_of_collectibles(game->map);
}
