/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estferna <estferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:28:33 by estferna          #+#    #+#             */
/*   Updated: 2025/01/06 21:16:28 by estferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


char	**init_map(char *path)
{
	int		fd;
	int		count;
	char	*line;
	char	**map;
	int		i;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_error();
	count = 0;
	line = get_next_line(fd);
	if (!line)
		ft_error();
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	map = malloc(sizeof(char *) * (count + 1));
	if (!map)
		ft_error();
	map[count] = NULL;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_error();
	i = 0;
	while (i < count)
	{

		map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return (map);
}

void	is_valid_characters(char **map)
{
	int	l;
	int	c;
	
	l = 0;
	while(map[l])
	{
		c = 0;
		while(map[l][c])
		{
			if(ft_strchr("01CEP\n", map[l][c]) == 0)
			{
				free_array(map);
				ft_error();
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
	printf("Player: %d\nColetável: %d\nSaida: %d\n", p_occ, c_occ, e_occ);
	if (p_occ != 1 || e_occ != 1 || c_occ < 1)
	{
		free_array(map);
		ft_error();
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
			ft_error();
		}
		i++;
	}
}


void	validation(t_game *game)
{
	(void)game;
	is_valid_characters(game->map);
	is_valid_min_characters(game->map);
	is_valid_rectangle(game->map);
}