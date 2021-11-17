/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:34:10 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/17 13:40:45 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_puterror(ERROR_AGRC);
		return (0);
	}
	game.mlx = mlx_init();
	init_game(&game, argv[1]);
	if (game.map)
	{
		init_mlx_window(&game);
		init_hooks(&game);
	}
	return (0);
}
