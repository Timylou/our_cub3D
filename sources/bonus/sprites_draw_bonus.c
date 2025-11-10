/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_draw_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:09:57 by brturcio          #+#    #+#             */
/*   Updated: 2025/11/10 10:19:41 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static void	ft_draw_stripe_contine(t_sprite_draw *d, int x, int tex_x, int y)
{
	int	color;
	int	tex_y;

	tex_y = (int)((((y * 256) - (d->game->w_height * 128) + (d->height * 128))
				* d->texture->height) / d->height) / 256;
	if (tex_y < 0)
		tex_y = 0;
	if (tex_y >= d->texture->height)
		tex_y = d->texture->height - 1;
	color = ft_get_pixel(d->texture, tex_x, tex_y);
	if ((color & 0x00FFFFFF) != 0)
		ft_put_pixel(d->game->frame, x, y, color);
}

void	ft_draw_sprite_stripe(t_sprite_draw *d, int x)
{
	int	y;
	int	tex_x;
	int	unclamped_start_x;

	unclamped_start_x = -d->width / 2 + d->screen_x;
	tex_x = (int)(256 * (x - unclamped_start_x) * d->texture->width
			/ d->width) / 256;
	if (d->transform_y > 0 && x >= 0 && x < d->game->w_width
		&& d->transform_y < d->game->z_buffer[x])
	{
		y = d->start_y;
		while (y < d->end_y)
		{
			ft_draw_stripe_contine(d, x, tex_x, y);
			y++;
		}
	}
}
