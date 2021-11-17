/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_window_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 12:01:22 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/17 15:41:31 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	*get_image(t_game *game, char obj)
{
	void	*img;

	if (obj == MAP_WALL)
		img = game->wall;
	else if (obj == MAP_COLLECTIBLE)
		img = game->collectible;
	else if (obj == MAP_EXIT && game->is_exit_open)
		img = game->exit_open;
	else if (obj == MAP_EXIT && !game->is_exit_open)
		img = game->exit_closed;
	else if (obj == MAP_PLAYER)
		img = game->player;
	else
		img = game->empty_space;
	if (!img)
	{
		ft_puterror(ERROR_PARSE_SPRITE);
		exit_game(game);
	}
	return (img);
}

int	animate_enemies(t_game *game)
{
	void	*img;
	int		i;
	int		j;

	if (game->enemy->sprite_index == 9)
		game->enemy->sprite_index = 0;
	else
		game->enemy->sprite_index++;
	img = game->enemy->sprites[game->enemy->sprite_index];
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == MAP_ENEMY)
				mlx_put_image_to_window(game->mlx, game->win, img,
					j * TILE_RESOLUTION, i * TILE_RESOLUTION);
			j++;
		}
		i++;
	}
	return (0);
}

void	render_window(t_game *game)
{
	void	*img;
	int		i;
	int		j;

	i = 0;
	img = get_image(game, game->under_player);
	mlx_put_image_to_window(game->mlx, game->win, img,
		game->player_x * TILE_RESOLUTION,
		game->player_y * TILE_RESOLUTION);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != MAP_ENEMY)
			{
				img = get_image(game, game->map[i][j]);
				mlx_put_image_to_window(game->mlx, game->win, img,
					j * TILE_RESOLUTION, i * TILE_RESOLUTION);
			}
			j++;
		}
		i++;
	}
}
