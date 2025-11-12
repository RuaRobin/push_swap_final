/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdalqa <rabdalqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 18:13:25 by rabdalqa          #+#    #+#             */
/*   Updated: 2025/09/02 12:54:45 by rabdalqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
