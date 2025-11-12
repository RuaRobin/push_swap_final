/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabdalqa <rabdalqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 14:06:03 by rabdalqa          #+#    #+#             */
/*   Updated: 2025/11/12 18:24:02 by rabdalqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6
# endif

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
int						is_empty(t_Stack *Stack);

//subject ops
void					pp_check(t_Stack *from, t_Stack *to, char Stack_spec);
void					swap_check(t_Stack *Stack);
void					ss_check(t_Stack *Stack_a, t_Stack *Stack_b);
void					rotate_check(t_Stack *Stack);
void					rr_check(t_Stack *Stack_a, t_Stack *Stack_b);
void					rotate_rev_check(t_Stack *t_Stack);
void					rrr_check(t_Stack *Stack_a, t_Stack *Stack_b);

//parsing inputs
int						check_bonus(int argnum, char **input);
int						checkdup_bonus(int argnum, char **input);
t_Stack					*create_stack_from_args_bon(int argnum, char **input);

//sorting related
int						is_sorted_bonus(t_Stack *Stack);
void					operation_exec(char *op_name, t_Stack *stack_a,
							t_Stack *stack_b);

//get next line
char					*get_next_line(int fd);
size_t					ft_strlcpy(char *dst, const char *src, size_t size);
char					*ft_strchr(const char *s, int c);
size_t					ft_strlen(const char *s);
char					*ft_strdup(const char *s);
char					*free_and_null(char **ptr);
#endif