/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 21:45:45 by yel-mens          #+#    #+#             */
/*   Updated: 2025/10/17 15:17:42 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

void	ft_free_all(t_game *game)
{
	if (!game)
		return ;
	ft_free_map(game);
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
