/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:56:16 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/13 14:56:07 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	exit_game_cross(t_vars *vars)
{
	free_vars(vars);
	exit(0);
}

static int	handle_key_press(int keycode, t_vars *vars)
{
	// if (keycode == KEY_W)
	// 	handle_go_up(vars);
	// else if (keycode == KEY_A)
	// 	handle_go_left(vars);
	// else if (keycode == KEY_S)
	// 	handle_go_down(vars);
	// else if (keycode == KEY_D)
	// 	handle_go_right(vars);
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		free_vars(vars);
		exit(0);
	}
	return (0);
}

void	init_hooks(t_vars *vars)
{
	mlx_key_hook(vars->win, handle_key_press, vars);
	mlx_hook(vars->win, 17, 0, exit_game_cross, vars);
	render_window(vars);
	mlx_loop(vars->mlx);
}
