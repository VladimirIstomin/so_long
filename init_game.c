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

static char	**create_map(char *file_name)
{
	int		fd;
	char	**map;

	if (!validate_map_extension(file_name))
		return (NULL);
	fd = open(file_name, O_RDONLY);
	map = parse_map(fd);
	close(fd);
	if (!map)
		return (NULL);
	if (!validate_map(map))
	{
		free_map(map);
		return (NULL);
	}
	return (map);
}

static t_player_pos	*get_player_position(char **map)
{
	int				i;
	int				j;
	t_player_pos	*player_position;

	if (!map)
		return (NULL);
	player_position = malloc(sizeof(t_player_pos));
	if (!player_position)
		return (NULL);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == MAP_PLAYER)
			{
				player_position->y = i;
				player_position->x = j;
			}
			j++;
		}
		i++;
	}
	return (player_position);
}

static t_sprites	*initialize_sprites(void *mlx)
{
	t_sprites	*sprites;
	int			w;
	int			h;

	sprites = malloc(sizeof(t_sprites));
	if (!sprites)
		return (NULL);
	sprites->wall = mlx_xpm_file_to_image(mlx, PATH_WALL, &w, &h);
	sprites->collectible = mlx_xpm_file_to_image(mlx, PATH_ORE, &w, &h);
	sprites->exit_open = mlx_xpm_file_to_image(mlx, PATH_EXIT_OPEN, &w, &h);
	sprites->exit_closed = mlx_xpm_file_to_image(mlx, PATH_EXIT_CLOSED, &w, &h);
	sprites->player = mlx_xpm_file_to_image(mlx, PATH_PLAYER, &w, &h);
	sprites->empty_space = mlx_xpm_file_to_image(mlx, PATH_EMPTY, &w, &h);
	return (sprites);
}

t_game	*init_game(void *mlx, char *map_file)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->map = create_map(map_file);
	game->sprites = initialize_sprites(mlx);
	game->player_position = get_player_position(game->map);
	if (!game->map || !game->sprites || !game->player_position)
	{
		free_game(game);
		return (0);
	}
	game->is_exit_open = 0;
	game->movements = 0;
	game->under_player = MAP_EMPTY_SPACE;
	game->n_collectibles = get_number_of_collectibles(game->map);
	return (game);
}
