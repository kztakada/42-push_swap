/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over_six_to_b_side.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:28:44 by katakada          #+#    #+#             */
/*   Updated: 2024/11/14 19:35:54 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_sort_to_b_till_3_left(t_stack *stack, t_list **operations)
{
	t_min_op	min_op;

	while (stack->a_size > 3)
	{
		if (is_sorted(stack->a, stack->a_size))
			return (0);
		min_op = get_min_op_to_side_b(stack);
		if (execute_min_op(min_op, stack, operations))
			return (1);
		if (push_b(stack, operations))
			return (1);
	}
	return (0);
}

int	sort_push_to_b(t_stack *stack, t_list **operations)
{
	if (push_b(stack, operations))
		return (1);
	if (is_sorted(stack->a, stack->a_size))
		return (0);
	if (push_b(stack, operations))
		return (1);
	if (is_sorted(stack->a, stack->a_size))
		return (0);
	if (push_sort_to_b_till_3_left(stack, operations))
		return (1);
	return (0);
}
