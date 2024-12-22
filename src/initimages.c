/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initimages.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estferna <estferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 20:40:06 by estferna          #+#    #+#             */
/*   Updated: 2024/12/22 17:49:32 by estferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_textures(t_game *game)
{
	game->cat_texture = mlx_load_png("./textures/cat.png");
	if (game->cat_texture == NULL)
		ft_error();
	game->fence_texture = mlx_load_png("./textures/fence.png");
	if (game->fence_texture == NULL)
		ft_error();
	game->grass_texture = mlx_load_png("./textures/grass.png");
	if (game->grass_texture == NULL)
		ft_error();
	game->home_texture = mlx_load_png("./textures/home.png");
	if (game->home_texture == NULL)
		ft_error();
	game->portion_texture = mlx_load_png("./textures/portion.png");
	if (game->portion_texture == NULL)
		ft_error();
}

int	init_images(t_game *game)
{
	init_textures(game);
	game->catimage = mlx_texture_to_image(game->mlx, game->cat_texture);
	if (!game->catimage)
		ft_error();
	game->fenceimage = mlx_texture_to_image(game->mlx, game->fence_texture);
	if (game->fenceimage == NULL)
		ft_error();
	game->grassimage = mlx_texture_to_image(game->mlx, game->grass_texture);
	if (game->grassimage == NULL)
		ft_error();
	game->homeimage = mlx_texture_to_image(game->mlx, game->home_texture);
	if (game->homeimage == NULL)
		ft_error();
	game->portionimage = mlx_texture_to_image(game->mlx, game->portion_texture);
	if (game->portionimage == NULL)
		ft_error();
	return (0);
}

void	put_grass_fence(t_game *game)
{
	int	line;
	int	col;

	line = 0;
	col = 0;
	while (game->map[line] != NULL)
	{
		col = 0;
		while (game->map[line][col])
		{
			if (game->map[line][col] == '1')
			{
				put_image(game, game->fenceimage, col, line);
			}
			else
			{
				put_image(game, game->grassimage, col, line);
			}
			col++;
		}
		line++;
	}
}

void	put_portion_home(t_game *game)
{
	int	line;
	int	col;

	line = 0;
	col = 0;
	while (game->map[line] != NULL)
	{
		col = 0;
		while (game->map[line][col])
		{
			if (game->map[line][col] == 'C')
			{
				put_image(game, game->portionimage, col, line);
			}
			if (game->map[line][col] == 'E')
			{
				put_image(game, game->homeimage, col, line);
			}
			col++;
		}
		line++;
	}
}

void	put_catimage(t_game *game)
{
	int	line;
	int	col;

	line = 0;
	col = 0;
	while (game->map[line] != NULL)
	{
		col = 0;
		while (game->map[line][col])
		{
			if (game->map[line][col] == 'P')
			{
				put_image(game, game->catimage, col, line);
			}
			col++;
		}
		line++;
	}
}

