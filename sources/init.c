/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 21:52:36 by yel-mens          #+#    #+#             */
/*   Updated: 2025/10/22 20:00:56 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_init_mlx_win(t_game *game)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	if (!mlx)
		ft_error("mlx init error\n", game);
	game->w_width = 1600;
	game->w_height = 900;
	win = mlx_new_window(mlx, game->w_width, game->w_height, "cub3D");
	if (!win)
		ft_error("mlx window init error\n", game);
	game->mlx = mlx;
	game->win = win;
}

static void	ft_init_player(t_game *game)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		ft_error("Malloc Error\n", game);
	player->x = -1;
	player->y = -1;
	player->angle = 0;
	player->key_up = 0;
	player->key_down = 0;
	player->key_left = 0;
	player->key_right = 0;
	player->left_rotate = 0;
	player->right_rotate = 0;
	game->player = player;
}

static void	ft_init_frame(t_game *game)
{
	int	width;
	int	height;

	game->frame = malloc(sizeof(t_img));
	if (!game->frame)
		ft_error("Malloc frame\n", game);
	width = game->w_width;
	height = game->w_height;
	game->frame->img = mlx_new_image(game->mlx, width, height);
	if (!game->frame->img)
		ft_error("frame image init\n", game);
	game->frame->data = mlx_get_data_addr(game->frame->img,
			&game->frame->bpp, &game->frame->size_line, &game->frame->edn);
	game->frame->width = game->w_width;
	game->frame->height = game->w_height;
}

t_game	*ft_init_game(void)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		ft_error("game malloc error\n", game);
	ft_init_player(game);
	ft_init_mlx_win(game);
	ft_init_frame(game);
	return (game);
}
