/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_door_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:26:21 by brturcio          #+#    #+#             */
/*   Updated: 2025/11/07 08:02:53 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void ft_door_status_check(t_game *game)
{
	int		map_x;
	int		map_y;
	t_door	*door;

	map_x = (int)(game->player->x + game->player->dir_x);
	map_y = (int)(game->player->y + game->player->dir_y);
	if (game->map[map_y][map_x] == 'D')
	{
		door = ft_get_door(game, map_x, map_y);
		if (door)
		{
			if (door->state == STATE_CLOSED)
				door->state = STATE_OPEN;
			else
				door->state = STATE_CLOSED;
		}
	}
}

t_door	*ft_get_door(t_game *game, int x, int y)
{
	t_list	*node;
	t_door	*door;

	node = game->doors;
	while (node)
	{
		door = (t_door *)node->content;
		if (door->x == x && door->y == y)
			return (door);
		node = node->next;
	}
	return (NULL);
}

void	ft_is_door(t_game *game, int x, int y)
{
	t_door	*door;

	door = malloc(sizeof(t_door));
	if (!door)
		ft_error("Malloc door failed", game);
	door->state = STATE_CLOSED;
	door->x = x;
	door->y = y;
	ft_lstadd_back(&game->doors, ft_lstnew(door));
	game->count_doors++;
}

void	ft_valid_one_door(t_game *game, int x, int y)
{
	char	up;
	char	down;
	char	left;
	char	right;
	int		vertical;
	int		horizontal;

	if (x <= 0 || y <= 0 || x >= game->m_width - 1 || y >= game->m_height - 1)
		ft_error("Door on the edge of the map\n", game);
	up = game->map[y - 1][x];
	down = game->map[y + 1][x];
	left = game->map[y][x - 1];
	right = game->map[y][x + 1];
	if (up == ' ' || down == ' ' || left == ' ' || right == ' ')
		ft_error("Door adjacent to void/space\n", game);
	vertical = (up == '1' && down == '1');
	horizontal = (left == '1' && right == '1');
	if (!vertical && !horizontal)
		ft_error("Door must be embedded between two walls\n", game);
}

void	ft_validate_door(t_game *game)
{
	t_list	*node;
	t_door	*d;

	node = game->doors;
	while (node)
	{
		d = (t_door *)node->content;
		ft_valid_one_door(game, d->x, d->y);
		node = node ->next;
	}
}
