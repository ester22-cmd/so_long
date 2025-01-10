/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estferna <estferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:28:33 by estferna          #+#    #+#             */
/*   Updated: 2025/01/09 19:33:37 by estferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_valid_walls(char **map)
{
	int	l;
	int	c;

	l = 0;
	while (map[l])
	{
		c = 0;
		while (map[l][c] && ft_strchr("10CEP", map[l][c]))
		{
			if ((l == 0 && map[l][c] != '1')
				|| (map[l + 1] == NULL && map[l][c] != '1')
				|| (map[l][0] != '1')
				|| (ft_strchr("10CEP", map[l][c + 1]) == NULL
				&& map[l][c] != '1'))
			{
				free_array(map);
				ft_error_validation("Error\nnot surrounded by walls");
			}
			c++;
		}
		l++;
	}
}

void	flood_fill(char **map, int l, int c)
{
	if (map[l][c] != '1')
	{
		map[l][c] = '1';
		flood_fill(map, l + 1, c);
		flood_fill(map, l - 1, c);
		flood_fill(map, l, c + 1);
		flood_fill(map, l, c - 1);
	}
}

void	is_valid_flood(char **map)
{
	int	l;
	int	c;

	l = 0;
	while (map[l])
	{
		c = 0;
		while (map[l][c])
		{
			if (ft_strchr("CEP", map[l][c]))
			{
				free_array(map);
				ft_error_validation("Error\nnot a valid path");
			}
			c++;
		}
		l++;
	}
}

void	is_valid_path(char **map)
{
	int	l;
	int	c;

	l = 0;
	while (map[l])
	{
		c = 0;
		while (map[l][c])
		{
			if (map[l][c] == 'P')
			{
				flood_fill(map, l, c);
				break ;
			}
			c++;
		}
		l++;
	}
	is_valid_flood(map);
}

void	validation(t_game *game)
{
	(void)game;
	is_valid_characters(game->map);
	is_valid_min_characters(game->map);
	is_valid_rectangle(game->map);
	is_valid_walls(game->map);
	is_valid_path(game->map);
	free_array(game->map);
}
