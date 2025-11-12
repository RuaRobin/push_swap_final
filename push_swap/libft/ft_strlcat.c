/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdalqa <rabdalqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:50:25 by rabdalqa          #+#    #+#             */
/*   Updated: 2025/08/31 15:48:55 by rabdalqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	i;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (dstlen < size)
	{
		i = dstlen;
		while (i < size - 1 && src[i - dstlen] != '\0')
		{
			dst[i] = src[i - dstlen];
			i++;
		}
		dst[i] = '\0';
	}
	if (size <= dstlen)
		return (size + srclen);
	else
		return (dstlen + srclen);
}
