/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estferna <estferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:21:26 by estferna          #+#    #+#             */
/*   Updated: 2024/12/15 22:33:32 by estferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Exit the program as failure.
static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}
void	put_image(t_game *game, mlx_image_t *image, int x, int y)
{
	if (mlx_image_to_window(game->mlx, image, x * TILE_WIDTH, y * TILE_HEIGHT) < 0)
		ft_error();
}
// Print the window width and height.
static void	ft_hook(void *param)
{
	const t_game	*game = (t_game *)param;

	printf("WIDTH: %d | HEIGHT: %d\n", game->mlx->width, game->mlx->height);
}

void	listen_moves(mlx_key_data_t keydata, void* param)
{
	t_game	*game;
	
	game = (t_game *)param;

	if (keydata.key == MLX_KEY_RIGHT)
		game->catimage->instances[0].x += 5;
	
	if (keydata.key == MLX_KEY_0)
		game->portionimage->instances[0].enabled = 0;
	if (keydata.key == MLX_KEY_1)
		game->portionimage->instances[0].enabled = 1;
}

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
void	put_grass_fence(t_game* game)
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
void	put_portion(t_game* game)
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
			col++;
		}
		line++;
	}
}
int32_t	main(void)
{
	t_game	game;
	
	game.map = ft_split(
		"1111111\n"
		"10C0011\n"
		"1011011\n"
		"11101P1\n"
		"1111111", '\n');

	game.mlx = mlx_init(1800, 1000, "cat", true);
	if (!game.mlx)
		ft_error();
	init_images(&game);
	// Insere imagem da grama e da parede na tela
	put_grass_fence(&game);
	put_portion(&game);
	// if ((mlx_image_to_window(game.mlx, game.catimage, 500, 500) < 0))
	// 	ft_error();
	
	// imagem da cerquinha
		
	//imagem da graminha

	//imagem da casinha
	// if (mlx_image_to_window(game.mlx, game.homeimage, 400, 200) < 0)
	// 	ft_error();
		
	//imagem do potinho
	// if (mlx_image_to_window(game.mlx, game.portionimage, 500, 100) < 0)
	// 	ft_error();
	

	// if (mlx_image_to_window(game.mlx, game.portionimage, 450, 450) < 0)
	// 	ft_error();
	mlx_key_hook(game.mlx, listen_moves, &game);
	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop!
	mlx_loop_hook(game.mlx, ft_hook, &game);
	mlx_loop(game.mlx);

	// liberando memoria do catineo
	mlx_delete_texture(game.cat_texture);
	mlx_delete_image(game.mlx, game.catimage);

	mlx_delete_image(game.mlx, game.fenceimage);
	mlx_delete_texture(game.fence_texture);
	
	mlx_delete_texture(game.grass_texture);
	mlx_delete_image(game.mlx, game.grassimage);

	mlx_delete_texture(game.home_texture);
	mlx_delete_image(game.mlx, game.homeimage);
	
	mlx_delete_texture(game.portion_texture);
	mlx_delete_image(game.mlx, game.portionimage);
	
	mlx_terminate(game.mlx);
	return (EXIT_SUCCESS);
}
