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

#include "so_long_bonus.h"

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

static void	init_enemy_sprites(t_game *game)
{
	int		w;
	int		h;
	t_enemy	*enemy;
	void	**enemy_sprites;

	enemy = malloc(sizeof(t_enemy));
	if (!enemy)
		exit_game(game);
	enemy->sprite_index = 0;
	game->enemy = enemy;
	enemy_sprites = malloc(sizeof(void *) * 10);
	if (!enemy_sprites)
		exit_game(game);
	enemy->sprites = enemy_sprites;
	enemy->sprites[0] = mlx_xpm_file_to_image(game->mlx, PATH_ENEMY_0, &w, &h);
	enemy->sprites[1] = mlx_xpm_file_to_image(game->mlx, PATH_ENEMY_1, &w, &h);
	enemy->sprites[2] = mlx_xpm_file_to_image(game->mlx, PATH_ENEMY_2, &w, &h);
	enemy->sprites[3] = mlx_xpm_file_to_image(game->mlx, PATH_ENEMY_3, &w, &h);
	enemy->sprites[4] = mlx_xpm_file_to_image(game->mlx, PATH_ENEMY_4, &w, &h);
	enemy->sprites[5] = mlx_xpm_file_to_image(game->mlx, PATH_ENEMY_5, &w, &h);
	enemy->sprites[6] = mlx_xpm_file_to_image(game->mlx, PATH_ENEMY_6, &w, &h);
	enemy->sprites[7] = mlx_xpm_file_to_image(game->mlx, PATH_ENEMY_7, &w, &h);
	enemy->sprites[8] = mlx_xpm_file_to_image(game->mlx, PATH_ENEMY_8, &w, &h);
	enemy->sprites[9] = mlx_xpm_file_to_image(game->mlx, PATH_ENEMY_9, &w, &h);
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
	init_enemy_sprites(game);
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
