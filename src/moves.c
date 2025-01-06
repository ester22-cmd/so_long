/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estferna <estferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 21:40:34 by estferna          #+#    #+#             */
/*   Updated: 2025/01/04 19:20:26 by estferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// validar se tem parede, pra ele nao sair
//validar se tem coletavel, se tiver que ele desapareça
void	collect_portion(t_game *game, int x, int y)
{
	size_t	i;
	
	i = 0;
	while (i < game->portionimage->count)
	{
		if (game->portionimage->instances[i].x == x
			&& game->portionimage->instances[i].y == y
			&& game->portionimage->instances[i].enabled)
		{
			game->portionimage->instances[i].enabled = false;
			game->count_collection++;
		}
		i++;
	}
	if (game->count_collection == game->portionimage->count)
		game->is_finish = 1;
}

void	move_cat(t_game *game, int x, int y)
{
	int	x_map;
	int	y_map;
	
	if (x == 0 || y == 0)
		return ;
	x_map = x / 64;
	y_map = y / 64;
	if (game->map[y_map][x_map] == '1')
		return ;
	game->count_steps++;
	ft_putnbr_fd(game->count_steps, STDOUT_FILENO);
	ft_putendl_fd("", STDOUT_FILENO);
	if (game->map[y_map][x_map] == 'C')
		collect_portion(game, x, y);
	if (game->map[y_map][x_map] == 'E' && game->is_finish)
		finish_game(game);
	game->catimage->instances[0].x = x;
	game->catimage->instances[0].y = y;
}

void	listen_moves(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;

	if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
		move_cat(game, game->catimage->instances[0].x + 64,
			game->catimage->instances[0].y);
		// game->catimage->instances[0].x += 64;
	if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
		move_cat(game, game->catimage->instances[0].x - 64,
			game->catimage->instances[0].y);
	if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
		move_cat(game, game->catimage->instances[0].x,
			game->catimage->instances[0].y - 64);
	if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
		move_cat(game, game->catimage->instances[0].x,
			game->catimage->instances[0].y + 64);
	if (keydata.key == MLX_KEY_ESCAPE)
		finish_game(game);
}
