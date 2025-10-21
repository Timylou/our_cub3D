/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 21:52:36 by yel-mens          #+#    #+#             */
/*   Updated: 2025/10/16 14:59:31 by yel-mens         ###   ########.fr       */
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

t_game	*ft_init_game(void)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		ft_error("game malloc error\n", game);
	ft_init_mlx_win(game);
	return (game);
}
