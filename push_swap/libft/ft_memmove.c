/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdalqa <rabdalqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 19:12:12 by rabdalqa          #+#    #+#             */
/*   Updated: 2025/08/31 15:44:17 by rabdalqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dst;
	const unsigned char	*srce;
	int					i;

	i = 0;
	dst = (unsigned char *)dest;
	srce = (const unsigned char *)src;
	if (dst <= srce)
	{
		while (n--)
		{
			dst[i] = srce[i];
			i++;
		}
	}
	else if (dst > srce)
	{
		while (n--)
			dst[n] = srce[n];
	}
	return (dst);
}
