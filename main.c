/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:34:10 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/11 16:49:28 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_vars			*vars;

	if (argc != 2)
	{
		ft_puterror(ERROR_AGRC);
		return (0);
	}
	vars = malloc(sizeof(t_vars));
	if (!vars)
		return (0);
	vars->game_config = init_game_config(argv[1]);
	if (!vars->game_config)
		return (free_vars(vars));
	init_mlx(vars);
	init_hooks(vars);
	return (0);
}
