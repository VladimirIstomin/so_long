/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:56:16 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/15 18:35:55 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_map(game->map);
	exit(0);
}

static int	handle_key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W
		|| keycode == KEY_A
		|| keycode == KEY_S
		|| keycode == KEY_D
	)
		handle_move(game, keycode);
	else if (keycode == KEY_ESC)
		exit_game(game);
	return (0);
}

void	init_hooks(t_game *game)
{
	mlx_key_hook(game->win, handle_key_press, game);
	mlx_hook(game->win, 17, 0, exit_game, game);
	render_window(game);
	mlx_loop(game->mlx);
}
