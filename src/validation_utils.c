/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estferna <estferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:12:29 by estferna          #+#    #+#             */
/*   Updated: 2025/01/09 19:13:23 by estferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_valid_characters(char **map)
{
	int	l;
	int	c;

	l = 0;
	while (map[l])
	{
		c = 0;
		while (map[l][c])
		{
			if (ft_strchr("01CEP\n", map[l][c]) == 0)
			{
				free_array(map);
				ft_error_validation("Error\nDoes not have valid characters");
			}
			c++;
		}
		l++;
	}
}

int	count_char(char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

void	is_valid_min_characters(char **map)
{
	int	l;
	int	p_occ;
	int	c_occ;
	int	e_occ;

	l = 0;
	p_occ = 0;
	c_occ = 0;
	e_occ = 0;
	while (map[l])
	{
		p_occ += count_char(map[l], 'P');
		c_occ += count_char(map[l], 'C');
		e_occ += count_char(map[l], 'E');
		l++;
	}
	if (p_occ != 1 || e_occ != 1 || c_occ < 1)
	{
		free_array(map);
		ft_error_validation("Error\n"
			"Does not have the minimum number of characters");
	}
}

int	count_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_strchr("10PEC", line[i]))
	{
		i++;
	}
	return (i);
}

void	is_valid_rectangle(char **map)
{
	int	size;
	int	i;

	size = count_line(map[0]);
	i = 1;
	while (map[i])
	{
		if (size != count_line(map[i]))
		{
			free_array(map);
			ft_error_validation("Error\nnot a rectangle");
		}
		i++;
	}
}
