/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:21:04 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/15 18:35:55 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	define_window_size(int *width, int *height, char **map)
{
	*width = 0;
	*height = 0;
	while (map[*height])
		(*height)++;
	while (map[0][*width])
		(*width)++;
	*width *= TILE_RESOLUTION;
	*height *= TILE_RESOLUTION;
}

void	init_mlx_window(t_game *game)
{
	int	width;
	int	height;

	define_window_size(&width, &height, game->map);
	game->win = mlx_new_window(game->mlx, width, height, "So_long");
}
