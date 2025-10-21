/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:43:51 by yel-mens          #+#    #+#             */
/*   Updated: 2025/10/20 16:51:55 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char **ft_copy_map(t_game *game)
{
	char	**map;
	char	**map_copy;
	int		i;

	map = game->map;
	map_copy = malloc(sizeof(char *) * game->m_height);
	if (!map_copy)
		ft_error("Malloc Error\n", game);	
	i = 0;
	while (i < game->m_height)
	{
		map_copy[i] = ft_strdup(map[i]);
	}
}

void	ft_flood_fill(t_game *game)
{
	char	**copy_map;
}
