/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 21:45:45 by yel-mens          #+#    #+#             */
/*   Updated: 2025/11/04 12:28:13 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static void	ft_free_imgs(t_game *game)
{
	if (game->no_img)
		ft_free_image(game->no_img, game);
	if (game->so_img)
		ft_free_image(game->so_img, game);
	if (game->we_img)
		ft_free_image(game->we_img, game);
	if (game->ea_img)
		ft_free_image(game->ea_img, game);
	if (game->door_img)
		ft_free_image(game->door_img, game);
	if (game->sprite_1)
		ft_free_image(game->sprite_1, game);
	if (game->sprite_2)
		ft_free_image(game->sprite_2, game);
	if (game->sprite_3)
		ft_free_image(game->sprite_3, game);
	if (game->sprite_4)
		ft_free_image(game->sprite_4, game);
	if (game->frame)
		ft_free_image(game->frame, game);
}

static void	ft_free_mlx_win(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

static void	ft_free_player(t_game *game)
{
	if (!game->player)
		return ;
	free(game->player);
}

void	ft_free_all(t_game *game)
{
	if (!game)
		return ;
	ft_free_map(game);
	ft_free_player(game);
	ft_free_doors(game);
	ft_free_imgs(game);
	ft_free_mlx_win(game);
	free(game);
}

void	ft_error(char *msg, t_game *game)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	if (game)
		ft_free_all(game);
	exit(EXIT_FAILURE);
}
