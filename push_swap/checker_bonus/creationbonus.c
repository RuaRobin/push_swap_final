/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creationbonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdalqa <rabdalqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:37:24 by rabdalqa          #+#    #+#             */
/*   Updated: 2025/11/12 18:12:04 by rabdalqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_Stack	*init_stack(void)
{
	t_Stack	*stack;

	stack = (t_Stack *)malloc(sizeof(t_Stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	return (stack);
}

int	is_empty(t_Stack *stack)
{
	return (!stack || stack->size == 0);
}

void	push(t_Stack *stack, int data)
{
	t_StackNode	*newnode;

	if (!stack)
		return ;
	newnode = (t_StackNode *)malloc(sizeof(t_StackNode));
	if (!newnode)
		return ;
	newnode->data = data;
	if (stack->size == 0)
	{
		newnode->next = newnode;
		stack->head = newnode;
		stack->tail = newnode;
	}
	else
	{
		newnode->next = stack->head;
		stack->tail->next = newnode;
		stack->head = newnode;
	}
	stack->size++;
}

int	pop(t_Stack *stack)
{
	t_StackNode	*temp;
	int			popped;

	if (is_empty(stack))
		return (-1);
	temp = stack->head;
	popped = temp->data;
	if (stack->size == 1)
	{
		stack->head = NULL;
		stack->tail = NULL;
	}
	else
	{
		stack->head = stack->head->next;
		stack->tail->next = stack->head;
	}
	free(temp);
	stack->size--;
	return (popped);
}

int	free_stacks(t_Stack *stack_a, t_Stack *stack_b)
{
	if (stack_a)
	{
		while (stack_a->size > 0)
			pop(stack_a);
		free(stack_a);
	}
	if (stack_b)
	{
		while (stack_b->size > 0)
			pop(stack_b);
		free(stack_b);
	}
	return (1);
}
