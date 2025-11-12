/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdalqa <rabdalqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:10:30 by rabdalqa          #+#    #+#             */
/*   Updated: 2025/11/12 18:57:03 by rabdalqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate_rev_check(t_Stack *stack)
{
	t_StackNode	*temp;

	if (is_empty(stack) || stack->size < 2)
		return ;
	temp = stack->head;
	while (temp->next != stack->tail)
		temp = temp->next;
	stack->head = stack->tail;
	stack->tail = temp;
	tack->tail->next = stack->head;
}

void	rrr_check(t_Stack *stack_a, t_Stack *stack_b)
{
	rotate_rev_check(stack_a);
	rotate_rev_check(stack_b);
}

int	is_sorted_bonus(t_Stack *stack)
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

void	error(t_Stack *stack_a, t_Stack *stack_b)
{
	write(2, "Error\n", 6);
	free_stacks(stack_a, stack_b);
	exit(1);
}

int		operation_exec(char *op_name, t_Stack *stack_a, t_Stack *stack_b)
{
	if (!ft_strcmp(op_name, "pa\n"))
		pp_check(stack_a, stack_b, 'a');
	else if (!ft_strcmp(op_name, "pb\n"))
		pp_check(stack_a, stack_b, 'b');
	else if (!ft_strcmp(op_name, "sa\n"))
		swap_check(stack_a);
	else if (!ft_strcmp(op_name, "sb\n"))
		swap_check(stack_b);
	else if (!ft_strcmp(op_name, "ss\n"))
		ss_check(stack_a, stack_b);
	else if (!ft_strcmp(op_name, "ra\n"))
		rotate_check(stack_a);
	else if (!ft_strcmp(op_name, "rb\n"))
		rotate_check(stack_b);
	else if (!ft_strcmp(op_name, "rr\n"))
		rr_check(stack_a, stack_b);
	else if (!ft_strcmp(op_name, "rra\n"))
		rotate_rev_check(stack_a);
	else if (!ft_strcmp(op_name, "rrb\n"))
		rotate_rev_check(stack_b);
	else if (!ft_strcmp(op_name, "rrr\n"))
		rrr_check(stack_a, stack_b);
	else
		return (0);
	return (1);
}
