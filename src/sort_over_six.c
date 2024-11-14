/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over_six.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:25:35 by katakada          #+#    #+#             */
/*   Updated: 2024/11/14 15:18:42 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_over_six(t_stack *stack, t_list **operations)
{
	if (sort_push_to_b(stack, operations))
		return (1);
	if (!is_sorted(stack->a, stack->a_size))
	{
		if (sort_three(stack, operations))
			return (1);
	}
	// if (sort_push_buck_to_a(stack, operations))
	// 	return (1);
	if (is_sorted(stack->a, stack->a_size))
		return (0);
	if (optimized_rotate_to_a_min(stack, operations))
		return (1);
	return (0);
}