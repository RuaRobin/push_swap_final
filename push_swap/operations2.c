/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdalqa <rabdalqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 18:29:44 by rabdalqa          #+#    #+#             */
/*   Updated: 2025/11/12 17:28:23 by rabdalqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	peek(t_Stack *stack)
{
	if (is_empty(stack))
		return (INT_MIN);
	return (stack->head->data);
}

void	rotate_rev(t_Stack *stack, char stack_spec)
{
	t_StackNode	*temp;

	if (is_empty(stack) || stack->size < 2)
		return ;
	temp = stack->head;
	while (temp->next != stack->tail)
		temp = temp->next;
	stack->head = stack->tail;
	stack->tail = temp;
	stack->tail->next = stack->head;
	if (stack_spec == 'a')
		write(1, "rra\n", 4);
	else if (stack_spec == 'b')
		write(1, "rrb\n", 4);
}

void	rrr(t_Stack *stack_a, t_Stack *stack_b)
{
	rotate_rev(stack_a, 'N');
	rotate_rev(stack_b, 'N');
	write(1, "rrr\n", 4);
}

t_StackNode	*get_node(t_Stack *s, size_t index)
{
	size_t		i;
	t_StackNode	*curr;

	if (index >= s->size)
		return (NULL);
	if (index == 0)
		return (s->head);
	i = 0;
	curr = s->head;
	while (i < index)
	{
		if (i == index)
			break ;
		curr = curr->next;
		i++;
	}
	return (curr);
}

int	get_index(t_Stack *stack, t_StackNode *target)
{
	t_StackNode	*cur;
	int			index;
	int			first;

	first = 1;
	if (!stack || is_empty(stack) || !target)
		return (-1);
	cur = stack->head;
	index = 0;
	while (cur != stack->head || first)
	{
		first = 0;
		if (cur == target)
			return (index);
		cur = cur->next;
		index++;
	}
	return (-1);
}
