/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_two_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:43:17 by brturcio          #+#    #+#             */
/*   Updated: 2025/11/08 12:41:16 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	ft_check_id_continue(char *id)
{
	if (id[0] == 'S' && id[1] == 'D')
		return (1);
	else if (id[0] == 'S' && id[1] == '1')
		return (1);
	else if (id[0] == 'S' && id[1] == '2')
		return (1);
	else if (id[0] == 'S' && id[1] == '3')
		return (1);
	else if (id[0] == 'S' && id[1] == '4')
		return (1);
	return (0);
}

int	ft_switch_img3(char *id, t_img *img, t_game *game)
{
	if (id[0] == 'S' && id[1] == '3')
	{
		if (game->sprite_3)
			return (0);
		game->sprite_3 = img;
	}
	if (id[0] == 'S' && id[1] == '4')
	{
		if (game->sprite_4)
			return (0);
		game->sprite_4 = img;
	}
	return (1);
}

int	ft_switch_img2(char *id, t_img *img, t_game *game)
{
	if (id[0] == 'S' && id[1] == 'D')
	{
		if (game->door_img)
			return (0);
		game->door_img = img;
	}
	if (id[0] == 'S' && id[1] == '1')
	{
		if (game->sprite_1)
			return (0);
		game->sprite_1 = img;
	}
	if (id[0] == 'S' && id[1] == '2')
	{
		if (game->sprite_2)
			return (0);
		game->sprite_2 = img;
	}
	if (!ft_switch_img3(id, img, game))
		return (0);
	return (1);
}
