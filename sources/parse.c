/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:59:57 by yel-mens          #+#    #+#             */
/*   Updated: 2025/10/18 13:10:45 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3D.h"

void	ft_free_split(char **split_line)
{
	int	i;

	i = 0;
	while (split_line[i])
		free(split_line[i++]);
	free(split_line);
}

void	ft_free_split_gnl(char *msg, char **split_line, int fd, t_game *game)
{
	char	*line;

	if (split_line)
		ft_free_split(split_line);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	ft_error(msg, game);
}

t_game	*ft_parse(char *map_name)
{
	t_game	*game;
	int		fd;

	game = NULL;
	fd = ft_open_file(map_name, ".cub", game);
	game = ft_init_game();
	if (ft_open_header(fd, game) != 6)
		ft_free_split_gnl("You need 6 IDs\n", ft_split("a a", ' '), fd, game);
	ft_open_map(fd, game);
	return (game);
}
