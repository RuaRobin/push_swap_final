/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdalqa <rabdalqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:10:33 by rabdalqa          #+#    #+#             */
/*   Updated: 2025/09/03 14:23:16 by rabdalqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*p;
	size_t	i;

	i = 0;
	if (nmemb == 0 || size == 0)
		return (malloc(1));
	if (nmemb > (SIZE_MAX / size))
		return (NULL);
	p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	while (i < nmemb * size)
		p[i++] = 0;
	return (p);
}
