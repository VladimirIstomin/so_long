/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:43:41 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/17 15:53:55 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*remove_nl_from_line(char *line)
{
	char	line_len;

	if (!line)
		return (NULL);
	line_len = ft_strlen(line);
	if (line[line_len - 1] == '\n')
		line = ft_realloc(line, line_len + 1, line_len);
	return (line);
}

static void	read_map_from_fd(int fd, char ***map)
{
	int		i;
	int		len;
	int		ptr_size;
	char	*line;

	i = 0;
	len = 1;
	ptr_size = sizeof(char *);
	while (1)
	{
		line = get_next_line(fd);
		(*map)[i] = remove_nl_from_line(line);
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

static char	**parse_map(int fd)
{
	char	**map;

	map = malloc(sizeof(char *));
	if (!map)
		return (NULL);
	read_map_from_fd(fd, &map);
	if (!map[0])
	{
		ft_puterror(ERROR_MAP_PARSING);
		free_map(map);
		return (NULL);
	}
	return (map);
}

char	**create_map(char *file_name)
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
