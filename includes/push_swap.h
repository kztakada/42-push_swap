/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 22:58:42 by katakada          #+#    #+#             */
/*   Updated: 2024/11/30 17:09:07 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

# define TOP 0
# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

typedef struct s_stack
{
	int		*a;
	size_t	a_size;
	int		a_min;
	int		a_max;
	int		*b;
	size_t	b_size;
	int		b_min;
	int		b_max;
}			t_stack;

typedef struct s_min_op
{
	size_t	rotate_a;
	size_t	rotate_b;
	size_t	rotate_ab;
	size_t	r_rotate_a;
	size_t	r_rotate_b;
	size_t	r_rotate_ab;
	int		total_count;
}			t_min_op;

t_stack		*get_validated_stack(int argc, char **argv);
int			is_all_int_str(char **arg_strs, size_t arg_size);
int			has_duplication(int *stack, size_t stack_size);

int			sort_three(t_stack *stack, t_list **operations);
int			sort_under_six(t_stack *stack, t_list **operations);
int			sort_over_six(t_stack *stack, t_list **operations);

int			sort_push_to_b(t_stack *stack, t_list **operations);
t_min_op	get_min_op_to_side_b(t_stack *stack);

t_min_op	get_min_op_to_side_a(t_stack *stack);

t_min_op	get_min_op_by_index_ab(size_t index_a, size_t index_b,
				t_stack *stack);
int			execute_min_op(t_min_op min_op, t_stack *stack,
				t_list **operations);
t_min_op	init_min_op(void);
size_t		get_index_by_num(int num, size_t size, int *stack);

void		print_operations(t_list *operations);

int			optimized_rotate_to_a_min(t_stack *stack, t_list **operations);
int			swap_a(t_stack *stack, t_list **operations);
int			swap_b(t_stack *stack, t_list **operations);
int			swap_ab(t_stack *stack, t_list **operations);
int			push_a(t_stack *stack, t_list **operations);
int			push_b(t_stack *stack, t_list **operations);
int			rotate_a(t_stack *stack, t_list **operations);
int			rotate_b(t_stack *stack, t_list **operations);
int			rotate_ab(t_stack *stack, t_list **operations);
int			reverse_rotate_a(t_stack *stack, t_list **operations);
int			reverse_rotate_b(t_stack *stack, t_list **operations);
int			reverse_rotate_ab(t_stack *stack, t_list **operations);

int			add_back_operation(int op_specifier, t_list **operations);

int			is_sorted(int *stack, size_t stack_size);
int			is_b_side_sorted(t_stack *stack, size_t stack_size);
int			is_a_side_sorted(t_stack *stack, size_t stack_size);

void		error_exit(void);
void		free_stack(t_stack *stack);
void		free_strs(char **strs, size_t stack_size, int argc);

#endif