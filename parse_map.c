/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:43:41 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/09 12:24:15 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static void	read_map_from_fd(int fd, char ***map)
{
	int	i;
	int	len;
	int	ptr_size;

	i = 0;
	len = 1;
	ptr_size = sizeof(char *);
	while (1)
	{
		(*map)[i] = get_next_line(fd);
		if (!(*map)[i])
			return ;
		if (i == len - 1)
		{
			*map = ft_realloc(*map, ptr_size * len, ptr_size * len * 2);
			len *= 2;
			if (!*map)
				return ;
		}
		i++;
	}
}

char	**parse_map(int fd)
{
	char	**map;

	map = malloc(sizeof(char *));
	if (!map)
		return (NULL);
	read_map_from_fd(fd, &map);
	if (errno)
	{
		perror("Error");
		free_map(map);
		map = NULL;
	}
	return (map);
}
