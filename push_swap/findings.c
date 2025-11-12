/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdalqa <rabdalqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:26:20 by rabdalqa          #+#    #+#             */
/*   Updated: 2025/11/12 14:06:02 by rabdalqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_index(t_Stack *s)
{
	t_StackNode	*curr;
	int			min;
	int			index;
	int			min_index;

	min_index = 0;
	index = 1;
	min = s->head->data;
	curr = s->head->next;
	while (curr != s->head)
	{
		if (curr->data < min)
		{
			min = curr->data;
			min_index = index;
		}
		curr = curr->next;
		index++;
	}
	return (min_index);
}

int	find_min(int *arr, size_t size)
{
	int		min;
	size_t	i;
	int		min_index;

	i = 0;
	min_index = 0;
	min = arr[0];
	while (i < size)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

int	find_max(t_Stack *s)
{
	t_StackNode	*curr;
	int			max;

	max = s->head->data;
	curr = s->head->next;
	while (curr != s->head)
	{
		if (curr->data > max)
			max = curr->data;
		curr = curr->next;
	}
	return (max);
}

int	find_target(t_StackNode *node, t_Stack *stack)
{
	t_StackNode	*curr;
	int			min;
	size_t		index;
	int			target;

	if (node->data > find_max(stack))
		return (find_min_index(stack));
	index = 0;
	curr = stack->head;
	min = INT_MAX;
	target = 0;
	while (index < stack->size)
	{
		if (curr->data - node->data < min && curr->data - node->data > 0)
		{
			min = curr->data - node->data;
			target = index;
		}
		curr = curr->next;
		index++;
	}
	return (target);
}
