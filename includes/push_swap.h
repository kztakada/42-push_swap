/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 22:58:42 by katakada          #+#    #+#             */
/*   Updated: 2024/11/11 17:53:03 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

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

void		error_exit(void);
void		free_stack(t_stack *stack);
void		free_strs(char **strs, size_t stack_size, int argc);

#endif