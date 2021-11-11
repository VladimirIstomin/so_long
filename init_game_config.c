/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_config.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:19:13 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/11 16:47:39 by gmerlene         ###   ########.fr       */
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

t_game_config	*init_game_config(char *map_file)
{
	t_game_config	*game_config;

	game_config = malloc(sizeof(t_game_config));
	if (!game_config)
		return (NULL);
	game_config->map = create_map(map_file);
	if (!game_config->map)
	{
		free_game_config(game_config);
		return (0);
	}
	game_config->is_exit_open = 0;
	game_config->n_collectibles = get_number_of_collectibles(game_config->map);
	define_player_position(game_config);
	return (game_config);
}
