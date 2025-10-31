/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 00:15:10 by yel-mens          #+#    #+#             */
/*   Updated: 2025/10/31 14:21:57 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_inict_camara(t_game *game, t_ray *r, int x)
{
	t_player	*p;

	p = game->player;
	r->camara = 2.0 * x / (double)game->w_width - 1.0;
	r->ray_dir_x = p->dir_x + p->plane_x * r->camara;
	r->ray_dir_y = p->dir_y + p->plane_y * r->camara;
	r->map_x = (int)p->x;
	r->map_y = (int)p->y;
	r->deltadist_x = my_abs(1 / r->ray_dir_x);
	r->deltadist_y = my_abs(1 / r->ray_dir_y);
}

void	ft_inict_sidedist(t_ray *r, t_player *player)
{
	if (r->ray_dir_x < 0)
	{
		r->step_x = -1;
		r->sidedist_x = (player->x - r->map_x) * r->deltadist_x;
	}
	else
	{
		r->step_x = 1;
		r->sidedist_x = (r->map_x + 1.0 - player->x) * r->deltadist_x;
	}
	if(r->ray_dir_y < 0)
	{
		r->step_y = -1;
		r->sidedist_y = (player->y - r->map_y) * r->deltadist_y;
	}
	else
	{
		r->step_y = 1;
		r->sidedist_y = (r->map_y + 1.0 - player->y) * r->deltadist_y;
	}
}

void	ft_inict_dda(t_game *game, t_ray *r)
{
	while (r->hit == 0)
	{
		if (r->sidedist_x < r->sidedist_y)
		{
			r->sidedist_x += r->deltadist_x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->sidedist_y += r->deltadist_y;
			r->map_y += r->step_y;
			r->side = 1;
		}
		if (r->map_y < 0 || r->map_y >= game->m_height ||
			r->map_x < 0 || r->map_x >= game->m_width)
			r->hit = 1;
		else if (game->map[r->map_y][r->map_x] == '1')
			r->hit = 1;
	}
}

t_img	*ft_select_texture(t_game *game, t_ray *r)
{
	t_img	*img;

	if (r->side == 0)
	{
		if (r->step_x == -1)
			img = game->we_img;
		else
			img = game->ea_img;
	}
	else
	{
		if (r->step_y == -1)
			img = game->no_img;
		else
			img = game->so_img;
	}
	return (img);
}

void	ft_raycast(t_game *game)
{
	t_ray	r;
	int		i;

	i = 0;
	while (i < game->w_width)
	{
		ft_struct_inict(&r);
		ft_inict_camara(game, &r, i);
		ft_inict_sidedist(&r, game->player);
		ft_inict_dda(game, &r);
		ft_realistic_height(game, &r);
		ft_draw_texture(game, &r, i);
		i++;
	}
}
