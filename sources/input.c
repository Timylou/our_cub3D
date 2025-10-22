/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 20:07:39 by yel-mens          #+#    #+#             */
/*   Updated: 2025/10/22 20:28:43 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_handle_input(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
	{
		mlx_loop_end(game->mlx);
		return (1);
	}
	if (keysym == XK_w)
		game->player->key_up = 1;
	else if (keysym == XK_a)
		game->player->key_left = 1;
	else if (keysym == XK_s)
		game->player->key_down = 1;
	else if (keysym == XK_d)
		game->player->key_right = 1;
	return (1);
}

int	ft_handle_release(int keysym, t_game *game)
{
	if (keysym == XK_w)
		game->player->key_up = 0;
	else if (keysym == XK_a)
		game->player->key_left = 0;
	else if (keysym == XK_s)
		game->player->key_down = 0;
	else if (keysym == XK_d)
		game->player->key_right = 0;
	return (1);
}