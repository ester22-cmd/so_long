/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estferna <estferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:21:26 by estferna          #+#    #+#             */
/*   Updated: 2025/01/09 21:18:37 by estferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_game *game, mlx_image_t *image, int x, int y)
{
	if (mlx_image_to_window(game->mlx, image,
			x * TILE_WIDTH, y * TILE_HEIGHT) < 0)
		ft_error();
}

void	ft_hook(void *param)
{
	const t_game	*game = (t_game *)param;

	(void)game;
}

void	finish_game(t_game *game)
{
	free_array(game->map);
	mlx_delete_texture(game->cat_texture);
	mlx_delete_image(game->mlx, game->catimage);
	mlx_delete_image(game->mlx, game->fenceimage);
	mlx_delete_texture(game->fence_texture);
	mlx_delete_texture(game->grass_texture);
	mlx_delete_image(game->mlx, game->grassimage);
	mlx_delete_texture(game->home_texture);
	mlx_delete_image(game->mlx, game->homeimage);
	mlx_delete_texture(game->portion_texture);
	mlx_delete_image(game->mlx, game->portionimage);
	mlx_terminate(game->mlx);
	exit(0);
}

int32_t	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		ft_error();
	(void)argv;
	if (is_valid_extension(argv[1], ".ber"))
		ft_error();
	game.map = init_map(argv[1]);
	game.window_width = ft_strlen(game.map[0]);
	game.window_height = array_len(game.map);
	validation(&game);
	game.map = init_map(argv[1]);
	init_game(&game);
	finish_game(&game);
	return (EXIT_SUCCESS);
}
