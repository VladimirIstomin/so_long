/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 12:01:22 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/15 18:58:39 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*get_image(t_game *game, char obj)
{
	if (obj == MAP_WALL)
		return (game->wall);
	else if (obj == MAP_COLLECTIBLE)
		return (game->collectible);
	else if (obj == MAP_EXIT && game->is_exit_open)
		return (game->exit_open);
	else if (obj == MAP_EXIT && !game->is_exit_open)
		return (game->exit_closed);
	else if (obj == MAP_PLAYER)
		return (game->player);
	else
		return (game->empty_space);
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
			img = get_image(game, game->map[i][j]);
			mlx_put_image_to_window(game->mlx, game->win, img,
				j * TILE_RESOLUTION, i * TILE_RESOLUTION);
			j++;
		}
		i++;
	}
}
