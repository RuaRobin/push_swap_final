/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdalqa <rabdalqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 19:15:49 by rabdalqa          #+#    #+#             */
/*   Updated: 2025/09/03 13:40:04 by rabdalqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	wordlen(const char *s, char c)
{
	size_t	k;

	k = 0;
	while (s[k] && s[k] != c)
		k++;
	return (k);
}

static char	**free_all(char **str, size_t i)
{
	while (i > 0)
		free(str[--i]);
	free(str);
	return (NULL);
}

static size_t	countwords(const char *s, char c)
{
	size_t	size;

	size = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			size++;
			while (*s && *s != c)
				s++;
		}
	}
	return (size);
}

static char	**mysplit(char **str, char const *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		str[i] = (char *)malloc((wordlen(s, c) + 1) * sizeof(char));
		if (str[i] == NULL)
			return (free_all(str, i));
		j = 0;
		while (j < wordlen(s, c) && *s != '\0')
		{
			str[i][j] = s[j];
			j++;
		}
		str[i++][j] = '\0';
		s += wordlen(s, c);
	}
	str[i] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	if (!s)
		return (NULL);
	str = (char **)malloc((countwords(s, c) + 1) * sizeof(char *));
	if (str == NULL)
		return (NULL);
	return (mysplit(str, s, c));
}
