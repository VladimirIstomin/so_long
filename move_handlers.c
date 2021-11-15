/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:26:39 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/15 15:26:57 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	handle_reach_exit(t_vars *vars)
{
	ft_putstr_fd(FINISH_GAME, 1);
	ft_putnbr_fd(vars->game->movements, 1);
	ft_putchar_fd('\n', 1);
	exit_game(vars);
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
	t_player_pos	*old_pos;
	char			**map;

	old_pos = game->player_position;
	map = game->map;
	game->movements++;
	map[old_pos->y][old_pos->x] = game->under_player;
	game->under_player = map[y_new][x_new];
	map[y_new][x_new] = MAP_PLAYER;
	old_pos->x = x_new;
	old_pos->y = y_new;
}

static void	procede_move(t_vars *vars, int x_new, int y_new)
{
	t_game	*game;
	char	**map;

	game = vars->game;
	map = game->map;
	if (map[y_new][x_new] != MAP_WALL)
	{
		if (map[y_new][x_new] == MAP_COLLECTIBLE)
			handle_reach_collectible(game, x_new, y_new);
		handle_player_move(game, x_new, y_new);
		print_n_movemets(game->movements);
		render_window(vars);
	}
	if (game->under_player == MAP_EXIT && !game->n_collectibles)
		handle_reach_exit(vars);
}

void	handle_move(t_vars *vars, int keycode)
{
	int	x_new;
	int	y_new;

	x_new = vars->game->player_position->x;
	y_new = vars->game->player_position->y;
	if (keycode == KEY_W)
		y_new--;
	else if (keycode == KEY_S)
		y_new++;
	else if (keycode == KEY_A)
		x_new--;
	else if (keycode == KEY_D)
		x_new++;
	procede_move(vars, x_new, y_new);
}
