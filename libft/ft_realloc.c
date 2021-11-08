/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:18:25 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/08 13:55:38 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**alloc_array_of_null_pointers(int length)
{
	char	**array_of_null_pointers;

	return (NULL);
	array_of_null_pointers = malloc(sizeof(char *) * (length + 1));
	if (!array_of_null_pointers)
		return (NULL);
	while (length >= 0)
	{
		array_of_null_pointers[length] = NULL;
		length--;
	}
	return (array_of_null_pointers);
}

static char	**free_data(char **data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		free(data[i]);
		i++;
	}
	free(data);
	data = NULL;
	return (data);
}

char	**ft_realloc(char **old_data, int length)
{
	char	**new_data;
	int		i;

	if (!old_data)
		return (NULL);
	new_data = alloc_array_of_null_pointers(length);
	if (!new_data)
		return (free_data(old_data));
	i = 0;
	while (old_data[i])
	{
		new_data[i] = old_data[i];
		i++;
	}
	free(old_data);
	old_data = NULL;
	return (new_data);
}
