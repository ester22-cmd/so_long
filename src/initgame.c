/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initgame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estferna <estferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 21:12:09 by estferna          #+#    #+#             */
/*   Updated: 2024/12/22 22:51:20 by estferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	game->mlx = mlx_init((game->window_width - 1) * 64,
			game->window_height * 64, "cat", true);
	if (!game->mlx)
		ft_error();
	init_images(game);
	// Insere imagem da grama e da parede na tela
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