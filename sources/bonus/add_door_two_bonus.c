/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_door_two_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:04:02 by brturcio          #+#    #+#             */
/*   Updated: 2025/11/05 13:19:16 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	ft_update_doors_continue(t_door *door)
{
	if (door->state == STATE_CLOSING)
	{
		door->progress -= DOOR_SPEED;
		if (door->progress <= 0.0)
		{
			door->progress = 0.0;
			door->state = STATE_IDLE;
		}
	}
}

void	ft_update_doors(t_game *game)
{
	t_list	*node;
	t_door	*door;

	node = game->doors;
	while (node)
	{
		door = (t_door *)node->content;
		if (door->state == STATE_OPENING)
		{
			door->progress += DOOR_SPEED;
			if (door->progress >= 1.0)
			{
				door->progress = 1.0;
				door->state = STATE_IDLE;
			}
		}
		ft_update_doors_continue(door);
		node = node->next;
	}
}
