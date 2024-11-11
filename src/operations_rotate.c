/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:42:19 by katakada          #+#    #+#             */
/*   Updated: 2024/11/11 20:36:25 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_a(t_stack *stack, t_list **operations)
{
	int		tmp;
	size_t	i;

	if (stack->a_size < 2)
		return (0);
	tmp = stack->a[0];
	i = 0;
	while (i < stack->a_size - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[i] = tmp;
	if (operations)
		return (add_back_operation(RA, operations));
	return (0);
}

int	rotate_b(t_stack *stack, t_list **operations)
{
	int		tmp;
	size_t	i;

	if (stack->b_size < 2)
		return (0);
	tmp = stack->b[0];
	i = 0;
	while (i < stack->b_size - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[i] = tmp;
	if (operations)
		return (add_back_operation(RB, operations));
	return (0);
}

int	rotate_ab(t_stack *stack, t_list **operations)
{
	rotate_a(stack, NULL);
	rotate_b(stack, NULL);
	return (add_back_operation(RR, operations));
}
