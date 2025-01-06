/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estferna <estferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:21:26 by estferna          #+#    #+#             */
/*   Updated: 2025/01/05 18:59:03 by estferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	array_len(char **map)
{
	int	i;

	if (!map)
		return(0);
	i = 0;
	while (map[i])
	{
		i++;
	}
	return(i);
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

// Exit the program as failure.
void	ft_error(void)
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
void	ft_hook(void *param)
{
	const t_game	*game = (t_game *)param;

	(void)game;
	// printf("WIDTH: %d | HEIGHT: %d\n", game->mlx->width, game->mlx->height);
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

int	is_valid_extension(char *file, char *extension)
{
	int	file_size;
	int	extension_size;

	file_size = ft_strlen(file);
	extension_size = ft_strlen(extension);
	while(extension_size >= 0)
	{
		if(extension[extension_size] != file[file_size])
			return(1);
		file_size--;
		extension_size--;
	}
	return(0);
}

int32_t	main(int argc, char **argv)
{
	t_game	game;

	if(argc != 2)
		ft_error();
	(void)argv;
	if(is_valid_extension(argv[1], ".ber"))
		ft_error();
	game.map = init_map(argv[1]);
	game.window_width = ft_strlen(game.map[0]);
	game.window_height = array_len(game.map);
	validation(&game);
	init_game(&game);
	finish_game(&game);
	return (EXIT_SUCCESS);
}