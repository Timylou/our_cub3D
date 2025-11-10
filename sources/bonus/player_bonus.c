/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:31:27 by yel-mens          #+#    #+#             */
/*   Updated: 2025/11/10 18:40:47 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static void	ft_angle_player(t_player *player)
{
	double	angle_speed;

	angle_speed = ANGLE_SPEED;
	if (player->left_rotate)
		player->angle -= angle_speed;
	if (player->right_rotate)
		player->angle += angle_speed;
	if (player->angle > 2 * PI)
		player->angle = 0;
	if (player->angle < 0)
		player->angle = 2 * PI;
}

static void	ft_position_player(t_player *p, double *move_x, double *move_y)
{
	*move_x = 0.0;
	*move_y = 0.0;
	if (p->key_up)
	{
		*move_x += p->dir_x * SPEED;
		*move_y += p->dir_y * SPEED;
	}
	if (p->key_down)
	{
		*move_x -= p->dir_x * SPEED;
		*move_y -= p->dir_y * SPEED;
	}
	if (p->key_left)
	{
		*move_x += p->dir_y * SPEED;
		*move_y -= p->dir_x * SPEED;
	}
	if (p->key_right)
	{
		*move_x -= p->dir_y * SPEED;
		*move_y += p->dir_x * SPEED;
	}
}

static int	ft_is_walkable(t_game *game, int x, int y)
{
	t_door	*door;

	if (y < 0 || y >= game->m_height || x < 0 || x >= game->m_width)
		return (0);
	if (game->map[y][x] == '1')
		return (0);
	if (game->map[y][x] == 'D')
	{
		door = ft_get_door(game, x, y);
		if (door && door->state == STATE_CLOSED)
			return (0);
	}
	return (1);
}

static void	ft_check_movement(t_game *game, double move_x, double move_y)
{
	double		pad_x;
	double		pad_y;
	t_player	*p;

	pad_x = 0.0;
	pad_y = 0.0;
	p = game->player;
	if (move_x > 0)
		pad_x = 0.1;
	else if (move_x < 0)
		pad_x = -0.1;
	if (move_y > 0)
		pad_y = 0.1;
	else if (move_y < 0)
		pad_y = -0.1;
	if (ft_is_walkable(game, (int)(p->x + move_x + pad_x), (int)(p->y)))
		p->x += move_x;
	if (ft_is_walkable(game, (int)(p->x), (int)(p->y + move_y + pad_y)))
		p->y += move_y;
}

void	ft_move_player(t_player *player, t_game *game)
{
	double	move_x;
	double	move_y;

	ft_angle_player(player);
	player->dir_x = cos(player->angle);
	player->dir_y = sin(player->angle);
	player->plane_x = -player->dir_y * FOV_PLANE;
	player->plane_y = player->dir_x * FOV_PLANE;
	ft_position_player(player, &move_x, &move_y);
	ft_check_movement(game, move_x, move_y);
}
