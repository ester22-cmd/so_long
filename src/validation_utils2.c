/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estferna <estferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:12:29 by estferna          #+#    #+#             */
/*   Updated: 2025/01/09 19:33:16 by estferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_extension(char *file, char *extension)
{
	int	file_size;
	int	extension_size;

	file_size = ft_strlen(file);
	extension_size = ft_strlen(extension);
	while (extension_size >= 0)
	{
		if (extension[extension_size] != file[file_size])
			return (1);
		file_size--;
		extension_size--;
	}
	return (0);
}
