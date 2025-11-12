/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdalqa <rabdalqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 12:37:06 by rabdalqa          #+#    #+#             */
/*   Updated: 2025/11/12 18:24:28 by rabdalqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		srclen;
	char		*dest;
	const char	*srce;

	i = 0;
	dest = (char *)dst;
	srce = (const char *)src;
	srclen = ft_strlen(srce);
	if (size > 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dest[i] = srce[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (srclen);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)(s + i));
		i++;
	}
	if (c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	size_t	size;
	size_t	i;
	char	*str;

	size = ft_strlen(s);
	i = 0;
	str = malloc(size + 1);
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[size] = '\0';
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (*s != '\0')
	{
		size++;
		s++;
	}
	return (size);
}

char	*free_and_null(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (NULL);
}
