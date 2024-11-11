/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:43:13 by katakada          #+#    #+#             */
/*   Updated: 2024/11/11 20:36:14 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate_a(t_stack *stack, t_list **operations)
{
	int		tmp;
	size_t	i;

	if (stack->a_size < 2)
		return (0);
	tmp = stack->a[stack->a_size - 1];
	i = stack->a_size - 1;
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[i] = tmp;
	if (operations)
		return (add_back_operation(RRA, operations));
	return (0);
}

int	reverse_rotate_b(t_stack *stack, t_list **operations)
{
	int		tmp;
	size_t	i;

	if (stack->b_size < 2)
		return (0);
	tmp = stack->b[stack->b_size - 1];
	i = stack->b_size - 1;
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[i] = tmp;
	if (operations)
		return (add_back_operation(RRB, operations));
	return (0);
}

int	reverse_rotate_ab(t_stack *stack, t_list **operations)
{
	reverse_rotate_a(stack, NULL);
	reverse_rotate_b(stack, NULL);
	return (add_back_operation(RRR, operations));
}
