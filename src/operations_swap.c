/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:41:23 by katakada          #+#    #+#             */
/*   Updated: 2024/11/11 20:36:36 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_a(t_stack *stack, t_list **operations)
{
	int	tmp;

	if (stack->a_size < 2)
		return (0);
	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
	if (operations)
		return (add_back_operation(SA, operations));
	return (0);
}

int	swap_b(t_stack *stack, t_list **operations)
{
	int	tmp;

	if (stack->b_size < 2)
		return (0);
	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
	if (operations)
		return (add_back_operation(SB, operations));
	return (0);
}

int	swap_ab(t_stack *stack, t_list **operations)
{
	swap_a(stack, NULL);
	swap_b(stack, NULL);
	return (add_back_operation(SS, operations));
}
