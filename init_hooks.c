/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:56:16 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/15 14:56:14 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	free_vars(vars);
	exit(0);
}

static int	handle_key_press(int keycode, t_vars *vars)
{
	if (keycode == KEY_W
		|| keycode == KEY_A
		|| keycode == KEY_S
		|| keycode == KEY_D
	)
		handle_move(vars, keycode);
	else if (keycode == KEY_ESC)
		exit_game(vars);
	return (0);
}

void	init_hooks(t_vars *vars)
{
	mlx_key_hook(vars->win, handle_key_press, vars);
	mlx_hook(vars->win, 17, 0, exit_game, vars);
	render_window(vars);
	mlx_loop(vars->mlx);
}
