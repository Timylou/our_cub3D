/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brturcio <brturcio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:03:30 by brturcio          #+#    #+#             */
/*   Updated: 2024/11/09 12:20:33 by brturcio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *str, char c)
{
	size_t	i;
	size_t	is_word;
	size_t	counter;

	counter = 0;
	is_word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			if (is_word == 0)
			{
				counter++;
				is_word = 1;
			}
		}
		else
			is_word = 0;
		i++;
	}
	return (counter);
}

static int	ft_free(char **result, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}

static void	fill_result(char *new, char const *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
}

static int	div_words(char **result, char const *str, char sep)
{
	size_t	i;
	size_t	count;
	size_t	j;

	i = 0;
	j = 0;
	while (str[j])
	{
		count = 0;
		while (str[j + count] && str[j + count] != sep)
			count++;
		if (count > 0)
		{
			result[i] = malloc(sizeof(char) * (count + 1));
			if (!result[i])
				return (ft_free(result, i));
			fill_result(result[i], (str + j), sep);
			i++;
			j = j + count;
		}
		else
			j++;
	}
	result[i] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	array = malloc(sizeof(char *) * (words + 1));
	if (!array)
		return (NULL);
	if (!div_words(array, s, c))
		return (NULL);
	return (array);
}
