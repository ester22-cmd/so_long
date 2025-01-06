/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estferna <estferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 21:44:27 by estferna          #+#    #+#             */
/*   Updated: 2025/01/04 19:29:53 by estferna         ###   ########.fr       */
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
	int				is_finish;
	size_t			count_collection;
	int				count_steps;
	int				window_width;
	int				window_height;
};

void	init_textures(t_game *game);
int		init_images(t_game *game);
void	put_grass_fence(t_game *game);
void	put_image(t_game *game, mlx_image_t *image, int x, int y);
void	put_portion_home(t_game *game);
void	put_catimage(t_game *game);

void	init_game(t_game *game);
void	listen_moves(mlx_key_data_t keydata, void *param);
void	ft_hook(void *param);
void	free_array(char **map);
void	finish_game(t_game *game);
char	**init_map(char *path);
void	validation(t_game *game);
void	ft_error(void);

#endif