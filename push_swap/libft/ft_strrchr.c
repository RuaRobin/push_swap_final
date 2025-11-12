/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdalqa <rabdalqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 19:05:24 by rabdalqa          #+#    #+#             */
/*   Updated: 2025/09/03 13:53:14 by rabdalqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;

	p = NULL;
	while (*s != '\0')
	{
		if ((unsigned char)*s == (unsigned char)c)
			p = (char *)s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (p);
}
