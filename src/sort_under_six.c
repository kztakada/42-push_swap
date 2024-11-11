/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_six.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 23:29:00 by katakada          #+#    #+#             */
/*   Updated: 2024/11/12 00:20:36 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_three(t_stack *stack, t_list **operations)
{
	if (stack->a[0] == stack->a_max)
	{
		if (rotate_a(stack, operations))
			return (1);
		if (is_sorted(stack->a, 3))
			return (0);
		else
			return (swap_a(stack, operations));
	}
	else if (stack->a[1] == stack->a_max)
	{
		if (stack->a[2] == stack->a_min)
			return (reverse_rotate_a(stack, operations));
		if (push_b(stack, operations))
			return (1);
		if (swap_a(stack, operations))
			return (1);
		return (push_a(stack, operations));
	}
	else
	{
		return (swap_a(stack, operations));
	}
}

int	is_upper_side(int *stack, size_t stack_size, int target_num)
{
	size_t	i;

	i = 0;
	while (i < stack_size)
	{
		if (stack[i] == target_num)
			break ;
		i++;
	}
	if (i < stack_size / 2)
		return (1);
	else
		return (0);
}

int	optimized_rotate(t_stack *stack, t_list **operations)
{
	int	is_upper;

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

int	sort_under_six(t_stack *stack, t_list **operations)
{
	while (stack->a_size > 3)
	{
		if (stack->a[0] == stack->a_min)
		{
			if (push_b(stack, operations))
				return (1);
		}
		else
		{
			if (optimized_rotate(stack, operations))
				return (1);
		}
	}
	if (sort_three(stack, operations))
		return (1);
	while (stack->b_size > 0)
	{
		if (push_a(stack, operations))
			return (1);
	}
	return (0);
}
