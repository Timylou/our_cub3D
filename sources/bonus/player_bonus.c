/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:31:27 by yel-mens          #+#    #+#             */
/*   Updated: 2025/11/09 16:53:56 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static void	ft_angle_player(t_player *player)
{
	double	angle_speed;

	angle_speed = 0.04;
	if (player->left_rotate)
		player->angle -= angle_speed;
	if (player->right_rotate)
		player->angle += angle_speed;
	if (player->angle > 2 * PI)
		player->angle = 0;
	if (player->angle < 0)
		player->angle = 2 * PI;
}

static void	ft_position_player(t_player *player, float speed)
{
	double	cos_angle;
	double	sin_angle;

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

static int	ft_check_offmap(t_player *player, int ex_x, int ex_y, t_game *g)
{
	int	x;
	int	y;
	int	off_map;

	off_map = 0;
	x = player->x;
	y = player->y;
	if (y < 0 || y > g->m_height)
	{
		player->y = ex_y;
		off_map = 1;
	}
	if (x < 0 || x > g->m_width)
	{
		player->x = ex_x;
		off_map = 1;
	}
	return (off_map);
}

static void	ft_check_movement(t_player *p, float ex_x, float ex_y, t_game *g)
{
	int	blocked_x;
	int	blocked_y;

	if (ft_check_offmap(p, ex_x, ex_y, g))
		return ;
	if (g->map[(int)p->y][(int)p->x] == '1')
	{
		blocked_x = (g->map[(int)p->y][(int)ex_x] == '1');
		blocked_y = (g->map[(int)ex_y][(int)p->x] == '1');
		if (blocked_x && blocked_y)
		{
			p->x = ex_x;
			p->y = ex_y;
		}
		else if (!blocked_x)
			p->x = ex_x;
		else if (!blocked_y)
			p->y = ex_y;
	}
	ft_check_movement_continue(p, ex_x, ex_y, g);
}

void	ft_move_player(t_player *player, t_game *game)
{
	double	ex_x;
	double	ex_y;
	double	speed;

	speed = 0.03;
	ft_angle_player(player);
	player->dir_x = cos(player->angle);
	player->dir_y = sin(player->angle);
	player->plane_x = -player->dir_y * FOV_PLANE;
	player->plane_y = player->dir_x * FOV_PLANE;
	ex_x = player->x;
	ex_y = player->y;
	ft_position_player(player, speed);
	ft_check_movement(player, ex_x, ex_y, game);
}
