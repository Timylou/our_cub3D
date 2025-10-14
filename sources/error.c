/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 21:45:45 by yel-mens          #+#    #+#             */
/*   Updated: 2025/10/14 21:45:47 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void ft_free_mlx_win(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

void    ft_free_all(t_game *game)
{
	if (!game)
		return ;
	ft_free_mlx_win(game);
	free(game);
}

void    ft_error(char *msg, t_game *game)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	if (game)
		ft_free_all(game);
	exit(EXIT_FAILURE);
}