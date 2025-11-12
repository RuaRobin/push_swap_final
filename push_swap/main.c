/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdalqa <rabdalqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:57:32 by rabdalqa          #+#    #+#             */
/*   Updated: 2025/11/12 18:12:54 by rabdalqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_Stack	*stack_a;
	t_Stack	*stack_b;

	if (argc < 2)
		return (1);
	if (!check(argc, argv) || !checkdup(argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stack_a = create_stack_from_args(argc, argv);
	if (!stack_a)
		return (1);
	stack_b = init_stack();
	if (!stack_b)
		return (free_stacks(stack_a, stack_b));
	if (is_sorted(stack_a))
		return (free_stacks(stack_a, stack_b));
	if (stack_a->size <= 3)
		small_sort(stack_a);
	else
		push_swap(stack_a, stack_b);
	free_stacks(stack_a, stack_b);
	return (0);
}
