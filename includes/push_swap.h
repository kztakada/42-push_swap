/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 22:58:42 by katakada          #+#    #+#             */
/*   Updated: 2024/11/11 20:30:43 by katakada         ###   ########.fr       */
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

t_stack		*get_init_stack(int argc, char **argv);
int			is_int_number_strs(char **stack_strs, size_t stack_size);
int			has_duplication(int *stack, size_t stack_size);

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

int			add_back_operation(int num, t_list **operations);

void		error_exit(void);
void		free_stack(t_stack *stack);
void		free_strs(char **strs, size_t stack_size, int argc);

#endif