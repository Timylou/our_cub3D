/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:31:27 by yel-mens          #+#    #+#             */
/*   Updated: 2025/10/23 01:01:18 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_free_player(t_game *game)
{
	if (!game->player)
		return ;
	free(game->player);
}

static void	ft_angle_player(t_player *player)
{
	float	angle_speed = 0.5;

	if (player->left_rotate)
		player->angle -= angle_speed;
	if (player->right_rotate)
		player->angle += angle_speed;
	if (player->angle > 2 * PI)
		player->angle = 0;
	if (player->angle < 0)
		player->angle = 2 * PI;
}

static void	ft_position_player(t_player *player, int speed)
{
	float	cos_angle;
	float	sin_angle;

	cos_angle = cos(player->angle);
	sin_angle = sin(player->angle);
	if (player->key_up)
    {
        player->x += cos_angle * speed;
        player->y += sin_angle * speed;
    }
    if (player->key_down)
    {
        player->x -= cos_angle * speed;
        player->y -= sin_angle * speed;
    }
    if (player->key_left)
    {
        player->x += sin_angle * speed;
        player->y -= cos_angle * speed;
    }
    if (player->key_right)
    {
        player->x -= sin_angle * speed;
        player->y += cos_angle * speed;
    }
}

static void	ft_check_movement(t_player *player, int ex_x, int ex_y, t_game *g)
{
	int	x;
	int	y;

	x = player->x;
	y = player->y;
	if (y < 0 || y > g->m_height)
		player->y = ex_y;
	if (x < 0 || x > g->m_width)
		player->x = ex_x;
	else if (g->map[y][x] == '1')
	{
		player->x = ex_x;
		player->y = ex_y;
	}
}

static void	ft_movement_player(t_player *player, int speed, t_game *game)
{
	int	ex_x;
	int	ex_y;

	ex_x = player->x;
	ex_y = player->y;
	ft_position_player(player, speed);
	ft_check_movement(player, ex_x, ex_y, game);
}

void	ft_move_player(t_player *player, t_game *game)
{
	int	speed;

	speed = 1;
	ft_angle_player(player);
	ft_movement_player(player, speed, game);
}
