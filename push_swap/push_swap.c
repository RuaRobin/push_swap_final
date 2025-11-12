/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdalqa <rabdalqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:50:22 by rabdalqa          #+#    #+#             */
/*   Updated: 2025/11/12 17:54:09 by rabdalqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_cost(t_Stack *stack_a, int node_a_ind, t_Stack *stack_b,
		int node_b_ind)
{
	int	cost_a;
	int	cost_b;
	int	mid_a;
	int	mid_b;

	mid_a = (stack_a->size - 1) / 2;
	mid_b = (stack_b->size - 1) / 2;
	if (node_a_ind <= mid_a)
		cost_a = node_a_ind;
	else
		cost_a = stack_a->size - node_a_ind;
	if (node_b_ind <= mid_b)
		cost_b = node_b_ind;
	else
		cost_b = stack_b->size - node_b_ind;
	if ((node_a_ind <= mid_a && node_b_ind <= mid_b) || (node_a_ind > mid_a
			&& node_b_ind > mid_b))
	{
		if (cost_a > cost_b)
			return (cost_a);
		return (cost_b);
	}
	return (cost_a + cost_b);
}

int	search_for_min_cost(t_Stack *stack_a, t_Stack *stack_b)
{
	t_StackNode	*node_b;
	size_t		i;
	int 		cost;
	int 		min_index;
	int 		min_cost;

	i = 0;
	node_b = stack_b->head;
	min_cost = INT_MAX;
	min_index = 0;
	while (i < stack_b->size)
	{
		cost = calc_cost(stack_a,find_target(node_b, stack_a), stack_b, i);
		if (min_cost > cost)
		{
			min_cost = cost;
			min_index = i;
		}
		node_b = node_b->next;
		i++;
	}
	return min_index;

}

void	push_swap(t_Stack *stack_a, t_Stack *stack_b)
{
	size_t	index;
	int		target;

	while (stack_a->size != 3)
		pp(stack_a, stack_b, 'b');
	sort_three(stack_a);
	while (stack_b->size > 0)
	{
		index = search_for_min_cost(stack_a, stack_b);
		target = find_target(get_node(stack_b,index),stack_a);
		move_tohead(stack_a, target, stack_b, index);
		pp(stack_a, stack_b, 'a');
	}
	bring_min_to_top(stack_a);
}
