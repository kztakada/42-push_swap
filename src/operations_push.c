/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:43:29 by katakada          #+#    #+#             */
/*   Updated: 2024/11/15 22:54:36 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_stack_min_max(t_stack *stack)
{
	size_t	i;

	stack->a_min = INT_MAX;
	stack->a_max = INT_MIN;
	i = 0;
	while (i < stack->a_size)
	{
		if (stack->a[i] < stack->a_min)
			stack->a_min = stack->a[i];
		if (stack->a[i] > stack->a_max)
			stack->a_max = stack->a[i];
		i++;
	}
	stack->b_min = INT_MAX;
	stack->b_max = INT_MIN;
	i = 0;
	while (i < stack->b_size)
	{
		if (stack->b[i] < stack->b_min)
			stack->b_min = stack->b[i];
		if (stack->b[i] > stack->b_max)
			stack->b_max = stack->b[i];
		i++;
	}
}

int	push_a(t_stack *stack, t_list **operations)
{
	size_t	i;

	if (stack->b_size == 0)
		return (0);
	i = stack->a_size;
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = stack->b[0];
	i = 0;
	while (i < stack->b_size - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->a_size++;
	stack->b_size--;
	set_stack_min_max(stack);
	if (operations)
		return (add_back_operation(PA, operations));
	return (0);
}

int	push_b(t_stack *stack, t_list **operations)
{
	size_t	i;

	if (stack->a_size == 0)
		return (0);
	i = stack->b_size;
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[0] = stack->a[0];
	i = 0;
	while (i < stack->a_size - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->b_size++;
	stack->a_size--;
	set_stack_min_max(stack);
	if (operations)
		return (add_back_operation(PB, operations));
	return (0);
}
