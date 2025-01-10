/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initgame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estferna <estferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 21:12:09 by estferna          #+#    #+#             */
/*   Updated: 2025/01/09 21:23:41 by estferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	game->mlx = mlx_init((game->window_width - 1) * 64,
			game->window_height * 64, "cat", true);
	if (!game->mlx)
		ft_error();
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	init_images(game);
	put_grass_fence(game);
	put_portion_home(game);
	put_catimage(game);
	game->count_steps = 0;
	game->is_finish = 0;
	game->count_collection = 0;
	mlx_key_hook(game->mlx, listen_moves, game);
	mlx_loop_hook(game->mlx, ft_hook, game);
	mlx_loop(game->mlx);
}

char	**create_map(char *path, int count)
{
	int		i;
	int		fd;
	char	**map;

	map = malloc(sizeof(char *) * (count + 1));
	if (!map)
		ft_error_validation("Error\nFile is empty");
	map[count] = NULL;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_error_validation("Error\nFile dont open");
	i = 0;
	while (i < count)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return (map);
}

char	**init_map(char *path)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_error_validation("Error\nFile dont open");
	count = 0;
	line = get_next_line(fd);
	if (!line)
		ft_error_validation("Error\nFile is empty");
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (create_map(path, count));
}
