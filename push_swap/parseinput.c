/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseinput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdalqa <rabdalqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:34:10 by rabdalqa          #+#    #+#             */
/*   Updated: 2025/11/12 17:55:20 by rabdalqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check(int argnum, char **input)
{
	int		i;
	int		j;
	long	num;

	j = 1;
	while (j < argnum)
	{
		i = 0;
		if ((input[j][i] == '-' || input[j][i] == '+') && input[j][i
			+ 1] != '0')
			i++;
		if (!input[j][i] || ft_strlen(input[j] + i) > 10)
			return (0);
		while (input[j][i])
		{
			if (!ft_isdigit(input[j][i]))
				return (0);
			i++;
		}
		num = ft_atoi(input[j]);
		if (num < INT_MIN || num > INT_MAX)
			return (0);
		j++;
	}
	return (1);
}

int	checkdup(int argnum, char **input)
{
	int	i;
	int	j;

	i = 1;
	while (i < argnum)
	{
		j = i + 1;
		while (j < argnum)
		{
			if (ft_atoi(input[i]) == ft_atoi(input[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_Stack	*create_stack_from_args(int argnum, char **input)
{
	t_Stack	*stack;
	int		i;

	stack = init_stack();
	if (!stack)
		return (NULL);
	i = argnum - 1;
	while (i > 0)
	{
		push(stack, ft_atoi(input[i]));
		i--;
	}
	return (stack);
}
