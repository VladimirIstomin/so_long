/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:34:10 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/09 14:01:27 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	//char	**map;

	(void)argv;
	if (argc != 2)
	{
		ft_putstr_fd(ERROR_AGRC, 2);
		return (0);
	}
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "Hello, world!");
	mlx_loop(mlx);
	return (0);
}
