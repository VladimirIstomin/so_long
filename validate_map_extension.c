/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_extension.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmerlene <gmerlene@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:04:33 by gmerlene          #+#    #+#             */
/*   Updated: 2021/11/09 16:47:28 by gmerlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validators/map_validators.h"

int	validate_map_extension(char *file_name)
{
	int	len;

	len = ft_strlen(file_name);
	if (
		len > 3
		&& (
			file_name[len - 4] == '.'
			&& file_name[len - 3] == 'b'
			&& file_name[len - 2] == 'e'
			&& file_name[len - 1] == 'r'
		)
	)
		return (1);
	ft_puterror(ERROR_INVALID_MAP_EXTENSION);
	return (0);
}
