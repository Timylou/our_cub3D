/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:03:12 by yel-mens          #+#    #+#             */
/*   Updated: 2025/10/17 15:38:17 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_check_id(char **split_line, int fd, t_game *game)
{
	char	*id;

	if (!split_line[1])
		ft_free_split_gnl("Too few argument in .cub\n", split_line, fd, game);
	if (split_line[2])
		ft_free_split_gnl("Too much argument in .cub\n", split_line, fd, game);
	id = split_line[0];
	if (id[0] == 'N' && id[1] == 'O')
		return ;
	else if (id[0] == 'S' && id[1] == 'O')
		return ;
	else if (id[0] == 'W' && id[1] == 'E')
		return ;
	else if (id[0] == 'E' && id[1] == 'A')
		return ;
	else if (id[0] == 'F' || id [0] == 'C')
		return ;
	ft_free_split_gnl("Identifier error in the .cub\n", split_line, fd, game);
}

static int	ft_switch_img(char *id, t_img *img, t_game *game)
{
	if (id[0] == 'N' && id[1] == 'O')
	{
		if (game->NO_img)
			return (0);
		game->NO_img = img;
	}
	else if (id[0] == 'S' && id[1] == 'O')
	{
		if (game->SO_img)
			return (0);
		game->SO_img = img;
	}
	else if (id[0] == 'W' && id[1] == 'E')
	{
		if (game->WE_img)
			return (0);
		game->WE_img = img;
	}
	else if (id[0] == 'E' && id[1] == 'A')
	{
		if (game->EA_img)
			return (0);
		game->EA_img = img;
	}
	return (1);
}

static void	ft_rgb_str_to_hex(char *rgb, char **split, int fd, t_game *game)
{
	char	**parts;
	int		r;
	int		g;
	int		b;

	parts = ft_split(rgb, ',');
	if (!parts || !parts[0] || !parts[1] || !parts[2] || parts[3])
		ft_free_split_gnl("Incorrect RGB syntax\n", split, fd, game);
	r = ft_atoi(parts[0]);
	g = ft_atoi(parts[1]);
	b = ft_atoi(parts[2]);
	ft_free_split(parts);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		ft_free_split_gnl("Incorrect RGB code\n", split, fd, game);
	if (split[0][0] == 'F')
		game->floor_color = (r << 16) | (g << 8) | b;
	else if (split[0][0] == 'C')
		game->ceiling_color = (r << 16) | (g << 8) | b;
}

static int	ft_handle_line(char *line, int fd, t_game *game)
{
	char	**split_line;
	t_img	*img;

	split_line = ft_split(line, ' ');
	free(line);
	if (!split_line || !split_line[0])
	{
		if (split_line)
			free(split_line);
		return (0);
	}
	ft_check_id(split_line, fd, game);
	if (ft_strlen(split_line[0]) == 2)
	{
		split_line[1][ft_strlen(split_line[1]) - 1] = 0;
		img = ft_open_image(game->mlx, split_line[1], 100, 100);
		if (!img)
			ft_free_split_gnl("Cannot open image\n", split_line, fd, game);
		if (!ft_switch_img(split_line[0], img, game))
		{
			if (img->img)
				free(img->img);
			free(img);
			ft_free_split_gnl("2 similar ID detected\n", split_line, fd, game);
		}
	}
	else if (ft_strlen(split_line[0]) == 1)
		ft_rgb_str_to_hex(split_line[1], split_line, fd, game);
	ft_free_split(split_line);
	return (1);
}

void	ft_open_header(int fd, t_game *game)
{
	int		index;
	char	*line;

	index = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (line[0])
			index += ft_handle_line(line, fd, game);
		if (index == 6)
			break ;
		line = get_next_line(fd);
	}
}
