/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdalqa <rabdalqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:03:45 by rabdalqa          #+#    #+#             */
/*   Updated: 2025/11/12 18:24:38 by rabdalqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	read_from_input(t_Stack *stack_a, t_Stack *stack_b)
{
	char	*op;

	op = get_next_line(0);
	while (op != NULL)
	{
		operation_exec(op, stack_a, stack_b);
		if (op)
			free(op);
		op = get_next_line(0);
	}
	if (op)
		free(op);
	return ;
}

int	main(int argc, char **argv)
{
	t_Stack	*stack_a;
	t_Stack	*stack_b;

	if (argc < 2)
		return (1);
	if (!check_bonus(argc, argv) || !checkdup_bonus(argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stack_a = create_stack_from_args_bon(argc, argv);
	if (!stack_a)
		return (1);
	stack_b = init_stack();
	if (!stack_b)
		return (free_stacks(stack_a, stack_b));
	read_from_input(stack_a, stack_b);
	if (is_sorted_bonus(stack_a) && is_empty(stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stacks(stack_a, stack_b);
	return (0);
}
