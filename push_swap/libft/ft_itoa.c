/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdalqa <rabdalqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:06:02 by rabdalqa          #+#    #+#             */
/*   Updated: 2025/08/31 15:33:23 by rabdalqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countdig(int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num *= -1;
		len++;
	}
	while (num != 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

static char	*ft_reverse(char *s)
{
	size_t	len;
	size_t	i;
	char	temp;

	i = 0;
	len = ft_strlen(s);
	if (s[0] == '-')
		i = 1;
	else
		len--;
	while (i <= len / 2)
	{
		temp = s[i];
		s[i] = s[len - i];
		s[len - i] = temp;
		i++;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	i;

	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	str = (char *)malloc(countdig(n) + 1);
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		n = n * -1;
		str[i++] = '-';
	}
	while (n != 0)
	{
		str[i++] = n % 10 + 48;
		n = n / 10;
	}
	str[i] = '\0';
	return (ft_reverse(str));
}
