/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 13:11:11 by yel-mens          #+#    #+#             */
/*   Updated: 2025/11/13 11:30:49 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_switch_angle(char angle, int player_x, char *line, t_game *game)
{
	line[player_x] = '0';
	if (angle == 'N')
		game->player->angle = PI + PI / 2;
	else if (angle == 'E')
		game->player->angle = 0;
	else if (angle == 'S')
		game->player->angle = PI / 2;
	else if (angle == 'W')
		game->player->angle = PI;
	game->player->x = player_x;
	return (player_x);
}

static char	*ft_skip_blank(int fd, t_game *game)
{
	char	*line;

	line = get_next_line(fd);
	while (line && (!line[0] || line[0] == '\n'))
	{
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
		ft_free_gnl_error("No map found in .cub file\n", fd, game);
	return (line);
}

static int	ft_check_line(char *line, int fd, t_list *lst, t_game *game)
{
	int		i;
	int		player_x;
	char	c;

	player_x = -1;
	i = 0;
	while (line[i])
	{
		c = line[i];
		if (c != ' ' && c != '1' && c != '0'
			&& c != 'N' && c != 'S' && c != 'E' && c != 'W' && c != '\n')
		{
			ft_lstclear(&lst, free);
			ft_free_gnl_error("Wrong character in map\n", fd, game);
		}
		if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			player_x = ft_switch_angle(c, i, line, game);
		i++;
	}
	if (player_x >= 0 && game->player->y >= 0)
	{
		ft_lstclear(&lst, free);
		ft_free_gnl_error("Player have 2 positions\n", fd, game);
	}
	return (player_x);
}

void	ft_open_map(int fd, t_game *game)
{
	char	*line;
	int		height;
	int		width;
	t_list	*lst;

	lst = NULL;
	width = 0;
	height = 0;
	line = ft_skip_blank(fd, game);
	while (line)
	{
		if ((int) ft_strlen(line) > width)
			width = ft_strlen(line);
		height++;
		ft_lstadd_back(&lst, ft_lstnew(line));
		if (ft_check_line(line, fd, lst, game) >= 0)
			game->player->y = height - 1;
		line = get_next_line(fd);
	}
	close(fd);
	ft_handle_lst(lst, width, height, game);
	ft_flood_fill(game);
}

void	ft_free_map(t_game *game)
{
	int	i;

	if (!game->map)
		return ;
	i = 0;
	while (i < game->m_height)
		free(game->map[i++]);
	free(game->map);
}
