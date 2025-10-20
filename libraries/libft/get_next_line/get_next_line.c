/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:03:49 by yel-mens          #+#    #+#             */
/*   Updated: 2024/11/04 11:46:31 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*temp;
	static char	*buffer = NULL;
	int			res;

	res = ft_read(fd, &buffer, &stash);
	while (res > 0 || stash)
	{
		temp = stash;
		stash = ft_strjoin(temp, buffer, res);
		free(temp);
		free(buffer);
		if (!stash)
			return (NULL);
		if (!ft_strchr(stash) && res > 0)
		{
			res = ft_read(fd, &buffer, &stash);
			continue ;
		}
		temp = ft_select(stash);
		stash = ft_linedel(stash);
		return (temp);
	}
	ft_free_stash(&stash, &buffer, res);
	return (NULL);
}

char	*ft_linedel(char *str)
{
	int	i;
	int	line;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	line = i;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	i++;
	while (str[i])
	{
		str[i - line - 1] = str[i];
		i++;
	}
	str[i - line - 1] = '\0';
	if (str[0] == '\0')
	{
		free(str);
		return (NULL);
	}
	return (str);
}

int	ft_read(int fd, char **buffer, char **stash)
{
	int	res;

	res = ft_check(fd, buffer, stash);
	if (res < 0)
		return (0);
	if (!(*stash) && res > 0)
	{
		*stash = malloc(sizeof(char));
		if (!(*stash))
			return (0);
		(*stash)[0] = 0;
	}
	return (res);
}

int	ft_check(int fd, char **buffer, char **stash)
{
	int	res;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	*buffer = malloc(sizeof(char) * BUFFER_SIZE);
	if (!(*buffer))
		return (-1);
	res = read(fd, *buffer, BUFFER_SIZE);
	if (res < 0)
	{
		if (*stash)
			free(*stash);
		*stash = NULL;
		return (-1);
	}
	return (res);
}
