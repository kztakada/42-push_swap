/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over_six_get_min_op_to_b_side.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:59:15 by katakada          #+#    #+#             */
/*   Updated: 2024/11/29 19:13:26 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_nearest_under_b(size_t index_a, t_stack *stack)
{
	long long	diff_tmp;
	long long	diff;
	size_t		index_b;
	int			b_num;

	diff = (long long)LONG_MAX;
	index_b = 0;
	b_num = stack->b[index_b];
	while (stack->b_size > index_b)
	{
		if (stack->a[index_a] > stack->b[index_b])
		{
			diff_tmp = (long long)stack->a[index_a]
				- (long long)stack->b[index_b];
			if (diff_tmp < diff)
			{
				diff = diff_tmp;
				b_num = stack->b[index_b];
			}
		}
		index_b++;
	}
	return (b_num);
}

t_min_op	get_min_op_to_under_nearest_b(size_t index_a, t_stack *stack)
{
	t_min_op	min_op;
	size_t		index_b;
	int			b_num;

	b_num = get_nearest_under_b(index_a, stack);
	index_b = get_index_by_num(b_num, stack->b_size, stack->b);
	min_op = get_min_op_by_index_ab(index_a, index_b, stack);
	return (min_op);
}

t_min_op	get_min_op_to_b_max(size_t index_a, t_stack *stack)
{
	t_min_op	min_op;
	size_t		index_b_max;

	index_b_max = get_index_by_num(stack->b_max, stack->b_size, stack->b);
	min_op = get_min_op_by_index_ab(index_a, index_b_max, stack);
	return (min_op);
}

t_min_op	get_optimal_min_op_to_b(t_stack *stack, size_t index_a)
{
	t_min_op	min_op;

	if (stack->a[index_a] > stack->b_max || stack->a[index_a] < stack->b_min)
		min_op = get_min_op_to_b_max(index_a, stack);
	else
		min_op = get_min_op_to_under_nearest_b(index_a, stack);
	return (min_op);
}

t_min_op	get_min_op_to_side_b(t_stack *stack)
{
	size_t		index_a;
	t_min_op	min_op;
	t_min_op	min_op_tmp;

	index_a = 0;
	min_op = get_optimal_min_op_to_b(stack, index_a);
	index_a++;
	while (stack->a_size > index_a)
	{
		min_op_tmp = get_optimal_min_op_to_b(stack, index_a);
		if (min_op.total_count > min_op_tmp.total_count)
			min_op = min_op_tmp;
		index_a++;
	}
	return (min_op);
}
