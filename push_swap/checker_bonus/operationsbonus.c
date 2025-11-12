/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operationsbonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdalqa <rabdalqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:53:13 by rabdalqa          #+#    #+#             */
/*   Updated: 2025/11/12 16:50:40 by rabdalqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// pb and pa

void	pp_check(t_Stack *stack_a, t_Stack *stack_b, char stack_speci)
{
	int	popped;

	if (stack_speci == 'b')
	{
		if (is_empty(stack_a))
			return ;
		popped = pop(stack_a);
		push(stack_b, popped);
	}
	else
	{
		if (is_empty(stack_b))
			return ;
		popped = pop(stack_b);
		push(stack_a, popped);
	}
}

//swap or swap b
void	swap_check(t_Stack *stack)
{
	int	temp;

	if (is_empty(stack) || stack->size < 2)
		return ;
	temp = stack->head->data;
	stack->head->data = stack->head->next->data;
	stack->head->next->data = temp;
}

void	ss_check(t_Stack *stack_a, t_Stack *stack_b)
{
	swap_check(stack_b);
	swap_check(stack_a);
}
//rotate a or b

void	rotate_check(t_Stack *stack)
{
	if (is_empty(stack) || stack->size < 2)
		return ;
	stack->head = stack->head->next;
	stack->tail = stack->tail->next;
}

//rotate a and b
void	rr_check(t_Stack *stack_a, t_Stack *stack_b)
{
	rotate_check(stack_a);
	rotate_check(stack_b);
}
