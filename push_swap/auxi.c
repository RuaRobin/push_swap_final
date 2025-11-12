/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdalqa <rabdalqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 19:54:30 by rabdalqa          #+#    #+#             */
/*   Updated: 2025/11/12 17:49:32 by rabdalqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_Stack *stack_a)
{
	if (stack_a->size == 2)
	{
		if (stack_a->head->data > stack_a->head->next->data)
			swap(stack_a, 'a');
		return ;
	}
	else if (stack_a->size == 3)
		sort_three(stack_a);
}

void	sort_three(t_Stack *stack)
{
	int	first;
	int	second;
	int	third;

	if (is_sorted(stack))
		return ;
	first = stack->head->data;
	second = stack->head->next->data;
	third = stack->tail->data;
	if (first > second && second > third && first > third)
	{
		rotate(stack, 'a');
		swap(stack, 'a');
	}
	else if (first < second && first > third)
		rotate_rev(stack, 'a');
	else if (first > second && first < third)
		swap(stack, 'a');
	else if (first > second && second < third && first > third)
		rotate(stack, 'a');
	else if (first < second && second > third && first < third)
	{
		swap(stack, 'a');
		rotate(stack, 'a');
	}
}

int	is_sorted(t_Stack *stack)
{
	t_StackNode	*current;
	size_t		count;

	current = stack->head;
	count = 0;
	if (is_empty(stack) || stack->size == 1)
		return (1);
	while (count < stack->size - 1)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
		count++;
	}
	return (1);
}
