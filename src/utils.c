/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estferna <estferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:29:48 by estferna          #+#    #+#             */
/*   Updated: 2025/01/09 21:41:25 by estferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	array_len(char **map)
{
	int	i;

	if (!map)
		return (0);
	i = 0;
	while (map[i])
	{
		i++;
	}
	return (i);
}

void	free_array(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_error(void)
{
	ft_putendl_fd("Error!", 2);
	exit(EXIT_FAILURE);
}

void	ft_error_validation(char *str)
{
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}
