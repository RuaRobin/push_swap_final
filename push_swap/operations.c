/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdalqa <rabdalqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:53:13 by rabdalqa          #+#    #+#             */
/*   Updated: 2025/11/12 14:07:14 by rabdalqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// pb and pa

void	pp(t_Stack *stack_a, t_Stack *stack_b, char stack_speci)
{
	int	popped;

	if (stack_speci == 'b')
	{
		if (is_empty(stack_a))
			return ;
		popped = pop(stack_a);
		push(stack_b, popped);
		write(1, "pb\n", 3);
	}
	else
	{
		if (is_empty(stack_b))
			return ;
		popped = pop(stack_b);
		push(stack_a, popped);
		write(1, "pa\n", 3);
	}
}

//swap or swap b
void	swap(t_Stack *stack, char stack_speci)
{
	int	temp;

	if (is_empty(stack) || stack->size < 2)
		return ;
	temp = stack->head->data;
	stack->head->data = stack->head->next->data;
	stack->head->next->data = temp;
	if (stack_speci == 'b')
		write(1, "sb\n", 3);
	else if (stack_speci == 'a')
		write(1, "sa\n", 3);
}

void	ss(t_Stack *stack_a, t_Stack *stack_b)
{
	swap(stack_b, 'N');
	swap(stack_a, 'N');
	write(1, "ss\n", 3);
}
//rotate a or b

void	rotate(t_Stack *stack, char stack_spec)
{
	if (is_empty(stack) || stack->size < 2)
		return ;
	stack->head = stack->head->next;
	stack->tail = stack->tail->next;
	if (stack_spec == 'a')
		write(1, "ra\n", 3);
	else if (stack_spec == 'b')
		write(1, "rb\n", 3);
}

//rotate a and b
void	rr(t_Stack *stack_a, t_Stack *stack_b)
{
	rotate(stack_a, 'N');
	rotate(stack_b, 'N');
	write(1, "rr\n", 3);
}
