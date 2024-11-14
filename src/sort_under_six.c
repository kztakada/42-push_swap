/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_six.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 23:29:00 by katakada          #+#    #+#             */
/*   Updated: 2024/11/14 18:23:00 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			if (optimized_rotate_to_a_min(stack, operations))
				return (1);
		}
	}
	if (!is_sorted(stack->a, 3))
	{
		if (sort_three(stack, operations))
			return (1);
	}
	while (stack->b_size > 0)
	{
		if (push_a(stack, operations))
			return (1);
	}
	return (0);
}
