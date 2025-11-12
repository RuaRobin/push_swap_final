/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   totop.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdalqa <rabdalqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:45:49 by rabdalqa          #+#    #+#             */
/*   Updated: 2025/11/12 14:10:51 by rabdalqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_tohead_upper_half(t_Stack *stack_a, t_StackNode *node_a,
		t_Stack *stack_b, t_StackNode *node_b)
{
	while (node_a != stack_a->head && node_b != stack_b->head)
		rr(stack_a, stack_b);
	while (node_a != stack_a->head)
		rotate(stack_a, 'a');
	while (node_b != stack_b->head)
		rotate(stack_b, 'b');
	return ;
}

void	move_tohead_lower_half(t_Stack *stack_a, t_StackNode *node_a,
		t_Stack *stack_b, t_StackNode *node_b)
{
	while (node_a != stack_a->head && node_b != stack_b->head)
		rrr(stack_a, stack_b);
	while (node_a != stack_a->head)
		rotate_rev(stack_a, 'a');
	while (node_b != stack_b->head)
		rotate_rev(stack_b, 'b');
	return ;
}

void	move_tohead(t_Stack *stack_a, size_t node_a_ind, t_Stack *stack_b,
		size_t node_b_ind)
{
	t_StackNode	*node_a;
	t_StackNode	*node_b;

	node_a = get_node(stack_a, node_a_ind);
	node_b = get_node(stack_b, node_b_ind);
	if (node_a_ind <= (stack_a->size + 1) / 2 && node_b_ind <= (stack_b->size
			+ 1) / 2)
		move_tohead_upper_half(stack_a, node_a, stack_b, node_b);
	if (node_a_ind > (stack_a->size + 1) / 2 && node_b_ind > (stack_b->size + 1)
		/ 2)
		move_tohead_lower_half(stack_a, node_a, stack_b, node_b);
	if (node_a_ind <= (stack_a->size + 1) / 2)
		while (node_a != stack_a->head)
			rotate(stack_a, 'a');
	else if (node_a_ind > (stack_a->size + 1) / 2)
		while (node_a != stack_a->head)
			rotate_rev(stack_a, 'a');
	if (node_b_ind > (stack_b->size + 1) / 2)
		while (node_b != stack_b->head)
			rotate_rev(stack_b, 'b');
	else if (node_b_ind <= (stack_b->size + 1) / 2)
		while (node_b != stack_b->head)
			rotate(stack_b, 'b');
	return ;
}

void	bring_min_to_top(t_Stack *s)
{
	int			min_index;
	t_StackNode	*min_node;

	min_index = find_min_index(s);
	if (min_index == 0)
		return ;
	min_node = get_node(s, min_index);
	move_a_tohead(s, min_node, min_index);
}

void	move_a_tohead(t_Stack *a, t_StackNode *node_a, size_t node_indix)
{
	if (node_indix <= (a->size + 1) / 2)
	{
		while (node_a != a->head)
			rotate(a, 'a');
	}
	else
	{
		while (node_a != a->head)
			rotate_rev(a, 'a');
	}
}
