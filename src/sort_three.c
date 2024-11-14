/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:20:05 by katakada          #+#    #+#             */
/*   Updated: 2024/11/14 15:20:34 by katakada         ###   ########.fr       */
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
