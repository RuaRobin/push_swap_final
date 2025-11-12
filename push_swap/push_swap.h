/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdalqa <rabdalqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:06:03 by rabdalqa          #+#    #+#             */
/*   Updated: 2025/11/12 18:12:13 by rabdalqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

//create stack
typedef struct t_StackNode
{
	int					data;
	struct t_StackNode	*next;
}						t_StackNode;
typedef struct t_Stack
{
	t_StackNode			*head;
	t_StackNode			*tail;
	size_t				size;

}						t_Stack;

//stack ops
t_Stack					*init_stack(void);
void					push(t_Stack *stack, int data);
int						pop(t_Stack *stack);
int						peek(t_Stack *Stack);
int						is_empty(t_Stack *Stack);
int						free_stacks(t_Stack *Stack_a, t_Stack *Stack_b);
int						peek(t_Stack *Stack);
int						get_index(t_Stack *Stack, t_StackNode *target);
t_StackNode				*get_node(t_Stack *s, size_t index);

//subject ops
void					pp(t_Stack *from, t_Stack *to, char Stack_spec);
void					swap(t_Stack *Stack, char Stack_spec);
void					ss(t_Stack *Stack_a, t_Stack *Stack_b);
void					rotate(t_Stack *Stack, char Stack_spec);
void					rr(t_Stack *Stack_a, t_Stack *Stack_b);
void					rotate_rev(t_Stack *t_Stack, char Stack_spec);
void					rrr(t_Stack *Stack_a, t_Stack *Stack_b);

//parsing inputs
int						check(int argnum, char **input);
int						checkdup(int argnum, char **input);
t_Stack					*create_stack_from_args(int argnum, char **input);

//sorting related
void					small_sort(t_Stack *Stack_a);
void					sort_three(t_Stack *Stack);
int						is_sorted(t_Stack *Stack);
void					move_tohead(t_Stack *Stack_a, size_t nodeA_ind,
							t_Stack *Stack_b, size_t node_b_ind);
void					push_swap(t_Stack *Stack_a, t_Stack *Stack_b);
int						find_target(t_StackNode *node, t_Stack *Stack);
void					move_a_tohead(t_Stack *A, t_StackNode *nodeA,
							size_t node_indix);
int						find_min_index(t_Stack *s);
int						find_min(int *arr, size_t size);
int						find_max(t_Stack *s);
void					bring_min_to_top(t_Stack *s);

#endif