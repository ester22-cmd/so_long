/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estferna <estferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:21:26 by estferna          #+#    #+#             */
/*   Updated: 2024/12/22 19:24:42 by estferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
int32_t	main(void)
{
	t_game	game;
	
	game.map = ft_split(
		"1111111\n"
		"10C0C11\n"
		"10110E1\n"
		"10101P1\n"
		"1111111", '\n');
	init_game(&game);
	finish_game(&game);
	return (EXIT_SUCCESS);
}
