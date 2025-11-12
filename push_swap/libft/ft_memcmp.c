/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdalqa <rabdalqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:59:32 by rabdalqa          #+#    #+#             */
/*   Updated: 2025/09/03 15:00:30 by rabdalqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*first;
	const char	*second;

	first = (const char *)s1;
	second = (const char *)s2;
	i = 0;
	while (i < n)
	{
		if (first[i] == second[i])
			i++;
		else
			return ((unsigned char)first[i] - (unsigned char)second[i]);
	}
	return (0);
}
