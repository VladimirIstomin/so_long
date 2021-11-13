/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_config.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:19:13 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/13 14:01:20 by gmerlene         ###   ########.fr       */
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

static void	define_player_position(t_game_config *game_config)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	map = game_config->map;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == MAP_PLAYER)
			{
				game_config->player_y = i;
				game_config->player_x = j;
				return ;
			}
			j++;
		}
		i++;
	}
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

t_game_config	*init_game_config(void *mlx, char *map_file)
{
	t_game_config	*game_config;

	game_config = malloc(sizeof(t_game_config));
	if (!game_config)
		return (NULL);
	game_config->map = create_map(map_file);
	game_config->sprites = initialize_sprites(mlx);
	if (!game_config->map || !game_config->sprites)
	{
		free_game_config(game_config);
		return (0);
	}
	game_config->is_exit_open = 0;
	game_config->n_collectibles = get_number_of_collectibles(game_config->map);
	define_player_position(game_config);
	return (game_config);
}
