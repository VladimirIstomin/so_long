/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 12:01:22 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/13 13:59:25 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*get_image(t_vars *vars, char obj)
{
	t_sprites			*sprites;

	sprites = vars->game_config->sprites;
	if (obj == MAP_WALL)
		return (sprites->wall);
	else if (obj == MAP_COLLECTIBLE)
		return (sprites->collectible);
	else if (obj == MAP_EXIT && vars->game_config->is_exit_open)
		return (sprites->exit_open);
	else if (obj == MAP_EXIT && !vars->game_config->is_exit_open)
		return (sprites->exit_closed);
	else if (obj == MAP_PLAYER)
		return (sprites->player);
	else
		return (sprites->empty_space);
}

void	render_window(t_vars *vars)
{
	void			*img;
	int				i;
	int				j;
	t_game_config	*game_config;

	i = 0;
	game_config = vars->game_config;
	img = get_image(vars, MAP_EMPTY_SPACE);
	mlx_put_image_to_window(vars->mlx, vars->win, img,
		game_config->player_x * TILE_RESOLUTION,
		game_config->player_y * TILE_RESOLUTION);
	while (game_config->map[i])
	{
		j = 0;
		while (game_config->map[i][j])
		{
			img = get_image(vars, game_config->map[i][j]);
			mlx_put_image_to_window(vars->mlx, vars->win, img,
				j * TILE_RESOLUTION, i * TILE_RESOLUTION);
			j++;
		}
		i++;
	}
}
