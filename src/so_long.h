/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estferna <estferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:44:27 by estferna          #+#    #+#             */
/*   Updated: 2024/12/15 22:17:46 by estferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# define WIDTH 256
# define HEIGHT 256

typedef struct s_game	t_game;

struct s_game
{
	mlx_t			*mlx;
	mlx_texture_t	*cat_texture;
	mlx_image_t		*catimage;
	mlx_texture_t	*fence_texture;
	mlx_image_t		*fenceimage;
	mlx_texture_t	*grass_texture;
	mlx_image_t		*grassimage;
	mlx_texture_t	*home_texture;
	mlx_image_t		*homeimage;
	mlx_texture_t	*portion_texture;
	mlx_image_t		*portionimage;
	char			**map;
};

#endif