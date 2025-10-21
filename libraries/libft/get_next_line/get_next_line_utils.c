/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-mens <yel-mens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:04:01 by yel-mens          #+#    #+#             */
/*   Updated: 2024/10/30 14:52:32 by yel-mens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free_stash(char **stash, char **buffer, int res)
{
	if (*stash && res >= 0)
		free(*stash);
	*stash = NULL;
	if (*buffer && res >= 0)
		free(*buffer);
	*buffer = NULL;
	return (*stash);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2, int res)
{
	char	*str;
	int		len_s1;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = 0;
	while (s1[len_s1])
		len_s1++;
	str = malloc(sizeof(char) * (len_s1 + res + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < len_s1)
		str[i] = s1[i];
	i = -1;
	while (++i < res)
		str[i + len_s1] = s2[i];
	str[len_s1 + res] = 0;
	return (str);
}

char	*ft_select(const char *str)
{
	char	*selected;
	int		len;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	len = i + 1;
	selected = malloc(sizeof(char) * (len + 1));
	if (!selected)
		return (NULL);
	i = 0;
	while (i < len)
	{
		selected[i] = str[i];
		i++;
	}
	selected[len] = 0;
	return (selected);
}

char	*ft_strchr_gnl(const char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return ((char *) str + 1);
		str++;
	}
	return (NULL);
}

char	*ft_strdup_gnl(const char *str)
{
	int		len_str;
	int		i;
	char	*str_cpy;

	if (!str)
		return (NULL);
	len_str = 0;
	while (str[len_str])
		len_str++;
	str_cpy = malloc(sizeof(char) * (len_str + 1));
	if (!str_cpy)
		return (NULL);
	i = 0;
	while (str[i])
	{
		str_cpy[i] = str[i];
		i++;
	}
	str_cpy[i] = 0;
	return (str_cpy);
}
