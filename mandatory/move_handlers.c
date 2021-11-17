/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:26:39 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/15 18:35:55 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	handle_reach_exit(t_game *game)
{
	ft_putstr_fd(FINISH_GAME, 1);
	ft_putnbr_fd(game->movements, 1);
	ft_putchar_fd('\n', 1);
	exit_game(game);
}

static void	handle_reach_collectible(t_game *game, int x_new, int y_new)
{
	game->n_collectibles--;
	game->map[y_new][x_new] = MAP_EMPTY_SPACE;
	if (!game->n_collectibles)
		game->is_exit_open = 1;
}

static void	handle_player_move(t_game *game, int x_new, int y_new)
{
	char	**map;

	map = game->map;
	game->movements++;
	map[game->player_y][game->player_x] = game->under_player;
	game->under_player = map[y_new][x_new];
	map[y_new][x_new] = MAP_PLAYER;
	game->player_x = x_new;
	game->player_y = y_new;
}

static void	procede_move(t_game *game, int x_new, int y_new)
{
	char	**map;

	map = game->map;
	if (map[y_new][x_new] != MAP_WALL)
	{
		if (map[y_new][x_new] == MAP_COLLECTIBLE)
			handle_reach_collectible(game, x_new, y_new);
		handle_player_move(game, x_new, y_new);
		print_n_movemets(game->movements);
		render_window(game);
	}
	if (game->under_player == MAP_EXIT && !game->n_collectibles)
		handle_reach_exit(game);
}

void	handle_move(t_game *game, int keycode)
{
	int	x_new;
	int	y_new;

	x_new = game->player_x;
	y_new = game->player_y;
	if (keycode == KEY_W)
		y_new--;
	else if (keycode == KEY_S)
		y_new++;
	else if (keycode == KEY_A)
		x_new--;
	else if (keycode == KEY_D)
		x_new++;
	procede_move(game, x_new, y_new);
}
