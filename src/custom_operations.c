/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:27:02 by katakada          #+#    #+#             */
/*   Updated: 2024/11/29 12:25:21 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_upper_side(int *stack, size_t stack_size, int target_num)
{
	size_t	i;
	size_t	target_order;

	i = 0;
	while (i < stack_size)
	{
		if (stack[i] == target_num)
			break ;
		i++;
	}
	target_order = i + 1;
	if (stack_size % 2 != 0)
		stack_size++;
	if (target_order <= stack_size / 2)
		return (1);
	else
		return (0);
}

int	optimized_rotate_to_a_min(t_stack *stack, t_list **operations)
{
	int	is_upper;

	if (stack->a_size <= 1)
		return (0);
	if (stack->a[0] == stack->a_min)
		return (0);
	is_upper = is_upper_side(stack->a, stack->a_size, stack->a_min);
	while (stack->a[0] != stack->a_min)
	{
		if (is_upper)
		{
			if (rotate_a(stack, operations))
				return (1);
		}
		else
		{
			if (reverse_rotate_a(stack, operations))
				return (1);
		}
	}
	return (0);
}
