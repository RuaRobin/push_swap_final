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

void	search_for_target_cost(t_Stack *stack_a, t_Stack *stack_b, int *costs,
		int *targets)
{
	t_StackNode	*node_b;
	size_t		i;
	int			target;

	i = 0;
	node_b = stack_b->head;
	while (i < stack_b->size)
	{
		target = find_target(node_b, stack_a);
		costs[i] = calc_cost(stack_a, target, stack_b, i);
		targets[i] = target;
		node_b = node_b->next;
		i++;
	}
}

void	push_swap(t_Stack *stack_a, t_Stack *stack_b)
{
	size_t	index;
	int		*costs;
	int		*targets;

	while (stack_a->size != 3)
		pp(stack_a, stack_b, 'b');
	sort_three(stack_a);
	while (stack_b->size > 0)
	{
		costs = (int *)ft_calloc(stack_b->size, sizeof(int));
		targets = (int *)ft_calloc(stack_b->size, sizeof(int));
		if (!costs || !targets)
		{
			free(costs);
			free(targets);
			return ;
		}
		search_for_target_cost(stack_a, stack_b, costs, targets);
		index = find_min(costs, stack_b->size);
		move_tohead(stack_a, targets[index], stack_b, index);
		free(costs);
		free(targets);
		pp(stack_a, stack_b, 'a');
	}
	bring_min_to_top(stack_a);
}
