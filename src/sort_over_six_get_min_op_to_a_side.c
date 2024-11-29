/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over_six_get_min_op_to_a_side.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:01:35 by katakada          #+#    #+#             */
/*   Updated: 2024/11/29 19:12:39 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_nearest_over_a(size_t index_b, t_stack *stack)
{
	long long	diff_tmp;
	long long	diff;
	size_t		index_a;
	int			a_num;

	diff = (long long)LONG_MAX;
	index_a = 0;
	a_num = stack->a[index_a];
	while (stack->a_size > index_a)
	{
		if (stack->a[index_a] > stack->b[index_b])
		{
			diff_tmp = (long long)stack->a[index_a]
				- (long long)stack->b[index_b];
			if (diff_tmp < diff)
			{
				diff = diff_tmp;
				a_num = stack->a[index_a];
			}
		}
		index_a++;
	}
	return (a_num);
}

t_min_op	get_min_op_to_over_nearest_a(size_t index_b, t_stack *stack)
{
	t_min_op	min_op;
	size_t		index_a;
	int			a_num;

	a_num = get_nearest_over_a(index_b, stack);
	index_a = get_index_by_num(a_num, stack->a_size, stack->a);
	min_op = get_min_op_by_index_ab(index_a, index_b, stack);
	return (min_op);
}

t_min_op	get_min_op_to_a_min(size_t index_b, t_stack *stack)
{
	t_min_op	min_op;
	size_t		index_a_min;

	index_a_min = get_index_by_num(stack->a_min, stack->a_size, stack->a);
	min_op = get_min_op_by_index_ab(index_a_min, index_b, stack);
	return (min_op);
}

t_min_op	get_optimal_min_op_to_a(t_stack *stack, size_t index_b)
{
	t_min_op	min_op;

	if (stack->b[index_b] > stack->a_max || stack->b[index_b] < stack->a_min)
		min_op = get_min_op_to_a_min(index_b, stack);
	else
		min_op = get_min_op_to_over_nearest_a(index_b, stack);
	return (min_op);
}

t_min_op	get_min_op_to_side_a(t_stack *stack)
{
	size_t		index_b;
	t_min_op	min_op;
	t_min_op	min_op_tmp;

	index_b = 0;
	min_op = get_optimal_min_op_to_a(stack, index_b);
	index_b++;
	while (stack->b_size > index_b)
	{
		min_op_tmp = get_optimal_min_op_to_a(stack, index_b);
		if (min_op_tmp.total_count < min_op.total_count)
			min_op = min_op_tmp;
		index_b++;
	}
	return (min_op);
}
