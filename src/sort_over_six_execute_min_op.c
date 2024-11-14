/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over_six_execute_min_op.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:52:44 by katakada          #+#    #+#             */
/*   Updated: 2024/11/14 15:41:51 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	execute_rotate_op(t_min_op min_op, t_stack *stack, t_list **operations)
{
	size_t	i;

	i = 0;
	while (min_op.rotate_a > i)
	{
		if (rotate_a(stack, operations))
			return (1);
		i++;
	}
	i = 0;
	while (min_op.rotate_b > i)
	{
		if (rotate_b(stack, operations))
			return (1);
		i++;
	}
	i = 0;
	while (min_op.rotate_ab > i)
	{
		if (rotate_ab(stack, operations))
			return (1);
		i++;
	}
	return (0);
}

int	execute_r_rotate_op(t_min_op min_op, t_stack *stack, t_list **operations)
{
	size_t	i;

	i = 0;
	while (min_op.r_rotate_a > i)
	{
		if (reverse_rotate_a(stack, operations))
			return (1);
		i++;
	}
	i = 0;
	while (min_op.r_rotate_b > i)
	{
		if (reverse_rotate_b(stack, operations))
			return (1);
		i++;
	}
	i = 0;
	while (min_op.r_rotate_ab > i)
	{
		if (reverse_rotate_ab(stack, operations))
			return (1);
		i++;
	}
	return (0);
}

int	execute_min_op(t_min_op min_op, t_stack *stack, t_list **operations)
{
	if (execute_rotate_op(min_op, stack, operations))
		return (1);
	if (execute_r_rotate_op(min_op, stack, operations))
		return (1);
	return (0);
}
