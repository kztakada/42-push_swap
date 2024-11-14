/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 23:27:55 by katakada          #+#    #+#             */
/*   Updated: 2024/11/14 16:51:23 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(int *stack, size_t stack_size)
{
	size_t	i;

	i = 0;
	while (i < stack_size - 1)
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	is_b_side_sorted(t_stack *stack, size_t stack_size)
{
	size_t	i;

	i = 0;
	while (i < stack_size - 1)
	{
		if (stack->b[i] < stack->b[i + 1] && (stack->b[i + 1] != stack->b_max))
			return (0);
		i++;
	}
	return (1);
}

int	is_a_side_sorted(t_stack *stack, size_t stack_size)
{
	size_t	i;

	i = 0;
	while (i < stack_size - 1)
	{
		if (stack->a[i] > stack->a[i + 1] && (stack->a[i + 1] != stack->a_min))
			return (0);
		i++;
	}
	return (1);
}
