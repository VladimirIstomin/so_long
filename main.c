/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:34:10 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/10 17:57:39 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**create_map(char *file_name)
{
	int		fd;
	char	**map;

	if (!validate_map_extension(file_name))
		return (NULL);
	fd = open(file_name, O_RDONLY);
	map = parse_map(fd);
	close(fd);
	if (!map)
		return (NULL);
	if (!validate_map(map))
	{
		free_map(map);
		return (NULL);
	}
	return (map);
}

int	main(int argc, char **argv)
{
	t_vars	*vars;

	if (argc != 2)
	{
		ft_putstr_fd(ERROR_AGRC, 2);
		return (0);
	}
	vars = malloc(sizeof(t_vars));
	if (!vars)
		return (0);
	vars->map = create_map(argv[1]);
	if (!vars->map)
		return (0);
	init_mlx(vars);
	init_hooks(vars);
	return (0);
}
