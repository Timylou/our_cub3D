/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:47:44 by brturcio          #+#    #+#             */
/*   Updated: 2025/11/08 20:29:14 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static void	ft_draw_sprite_stripe(t_sprite_draw *d, int x)
{
	int	y;
	int	tex_y;
	int	color;
	int	tex_x;

	tex_x = (int)(256 * (x - d->start_x) * d->texture->width / d->width) / 256;
	if (d->transform_y > 0 && x >= 0 && x < d->game->w_width
		&& d->transform_y < d->game->z_buffer[x])
	{
		y = d->start_y;
		while (y < d->end_y)
		{
			tex_y = (int)((((y * 256) - (d->game->w_height * 128)
							+ (d->height * 128)) * d->texture->height)
					/ d->height) / 256;
			color = ft_get_pixel(d->texture, tex_x, tex_y);
			if ((color & 0x00FFFFFF) != 0)
				ft_put_pixel(d->game->frame, x, y, color);
			y++;
		}
	}
}

static void	ft_calculate_draw_limits(t_game *game, t_sprite_draw *d)
{
	d->height = (int)my_abs(game->w_height / d->transform_y);
	d->start_y = -d->height / 2 + game->w_height / 2;
	if (d->start_y < 0)
		d->start_y = 0;
	d->end_y = d->height / 2 + game->w_height / 2;
	if (d->end_y >= game->w_height)
		d->end_y = game->w_height;
	d->width = (int)my_abs(game->w_height / d->transform_y);
	d->start_x = -d->width / 2 + d->screen_x;
	if (d->start_x < 0)
		d->start_x = 0;
	d->end_x = d->width / 2 + d->screen_x;
	if (d->end_x >= game->w_width)
		d->end_x = game->w_width;
}

static void	ft_calculate_transform(t_game *game, t_sprite *sprite,
	t_sprite_draw *d)
{
	double		sprite_x;
	double		sprite_y;
	double		inv_det;
	t_player	*p;

	p = game->player;
	sprite_x = sprite->x - p->x;
	sprite_y = sprite->y - p->y;
	inv_det = 1.0 / (p->plane_x * p->dir_y - p->dir_x * p->plane_y);
	d->transform_x = inv_det * (p->dir_y * sprite_x - p->dir_x * sprite_y);
	d->transform_y = inv_det * (-p->plane_y * sprite_x + p->plane_x * sprite_y);
	d->screen_x = (int)((game->w_width / 2)
			* (1 + d->transform_x / d->transform_y));
}

static void	ft_draw_one_sprite(t_game *game, t_sprite *sprite)
{
	t_sprite_draw	d;
	int				x;

	d.game = game;
	if (sprite->anim_frame == 0)
		d.texture = game->sprite_1;
	else if (sprite->anim_frame == 1)
		d.texture = game->sprite_2;
	else if (sprite->anim_frame == 2)
		d.texture = game->sprite_3;
	else
		d.texture = game->sprite_4;
	ft_calculate_transform(game, sprite, &d);
	ft_calculate_draw_limits(game, &d);
	x = d.start_x;
	while (x < d.end_x)
	{
		ft_draw_sprite_stripe(&d, x);
		x++;
	}
}

void	ft_render_sprites(t_game *game)
{
	t_list		*node;
	t_sprite	*sprite;

	ft_sort_sprites(game);
	node = game->sprites;
	while (node)
	{
		sprite = (t_sprite *)node->content;
		ft_update_sprite_animation(sprite);
		ft_draw_one_sprite(game, sprite);
		node = node->next;
	}
}
