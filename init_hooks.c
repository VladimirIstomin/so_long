/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:56:16 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/10 19:21:13 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

int	exit_game_cross(t_vars *vars)
{
	free_map(vars->map);
	exit(0);
}

int	exit_game_esc(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		free_map(vars->map);
		exit(0);
	}
	return (0);
}

void	init_hooks(t_vars *vars)
{
	mlx_key_hook(vars->win, exit_game_esc, vars);
	mlx_hook(vars->win, 17, 0, exit_game_cross, vars);
	mlx_loop(vars->mlx);
}
