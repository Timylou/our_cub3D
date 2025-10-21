/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 13:11:11 by yel-mens          #+#    #+#             */
/*   Updated: 2025/10/19 17:54:51 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_free_gnl_error(char *msg, int fd, t_game *game)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	ft_error(msg, game);
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

static void	ft_check_line(char *line, int fd, t_list *lst, t_game *game)
{
	int		i;
	char	c;

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
		i++;
	}
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
		ft_check_line(line, fd, lst, game);
		line = get_next_line(fd);
	}
	close(fd);
	ft_handle_lst(lst, width, height, game);
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
