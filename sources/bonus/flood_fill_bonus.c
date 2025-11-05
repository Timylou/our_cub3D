/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:43:51 by yel-mens          #+#    #+#             */
/*   Updated: 2025/11/04 10:03:33 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static void	ft_free_copy(char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
		free(map[i++]);
	free(map);
}

static char	**ft_copy_map(t_game *game)
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
		if (!map_copy[i])
		{
			while (--i >= 0)
				free(map_copy[i]);
			ft_error("Malloc Error\n", game);
		}
		i++;
	}
	return (map_copy);
}

static void	ft_rec_flood_fill(char **map, int x, int y, t_game *game)
{
	if (y < 0 || y >= game->m_height || x < 0 || x >= game->m_width)
	{
		ft_free_copy(map, game->m_height);
		ft_error("Map not closed\n", game);
	}
	if (map[y][x] == '1' || map[y][x] == 'X' || map[y][x] == 'D')
		return ;
	map[y][x] = 'X';
	ft_rec_flood_fill(map, x + 1, y, game);
	ft_rec_flood_fill(map, x - 1, y, game);
	ft_rec_flood_fill(map, x, y + 1, game);
	ft_rec_flood_fill(map, x, y - 1, game);
}

void	ft_flood_fill(t_game *game)
{
	char	**copy_map;

	copy_map = ft_copy_map(game);
	ft_rec_flood_fill(copy_map, game->player->x, game->player->y, game);
	ft_free_copy(copy_map, game->m_height);
}
