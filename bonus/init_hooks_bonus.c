/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hooks_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:56:16 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/17 18:56:21 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	handle_key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W
		|| keycode == KEY_A
		|| keycode == KEY_S
		|| keycode == KEY_D
	)
		handle_move(game, keycode);
	else if (keycode == KEY_ESC)
		exit_game(game, NULL);
	return (0);
}

static int	handle_cross_press(t_game *game)
{
	exit_game(game, NULL);
	return (0);
}

void	init_hooks(t_game *game)
{
	mlx_key_hook(game->win, handle_key_press, game);
	mlx_hook(game->win, 17, 0, handle_cross_press, game);
	render_window(game);
	print_n_movemets(game);
	mlx_loop_hook(game->mlx, animate_enemies, game);
	mlx_loop(game->mlx);
}
