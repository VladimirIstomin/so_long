/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:21:04 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/13 13:01:32 by gmerlene         ###   ########.fr       */
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

void	init_mlx_window(t_vars *vars)
{
	int	width;
	int	height;

	define_window_size(&width, &height, vars->game_config->map);
	vars->win = mlx_new_window(vars->mlx, width, height, "Minecraft - So long");
}
