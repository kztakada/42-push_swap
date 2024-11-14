/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over_six_get_min_op_to_b_side.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:59:15 by katakada          #+#    #+#             */
/*   Updated: 2024/11/14 15:03:58 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_nearest_under_b(size_t index_a, t_stack *stack)
{
	long long	diff_tmp;
	long long	diff;
	size_t		index_b;
	int			b_num;

	diff = (long long)INT_MAX;
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
	ft_printf("gggggggggggggb_num: %d\n", b_num);
	return (b_num);
}

t_min_op	get_min_op_to_nearest_under_b(size_t index_a, t_stack *stack)
{
	t_min_op	min_op;
	size_t		index_b;
	int			b_num;

	b_num = get_nearest_under_b(index_a, stack);
	index_b = get_index_by_b_num(b_num, stack);
	min_op = get_min_op_by_index_ab(index_a, index_b, stack);
	return (min_op);
}

t_min_op	get_min_op_to_b_max(size_t index_a, t_stack *stack)
{
	t_min_op	min_op;
	size_t		index_b;

	index_b = get_index_by_b_num(stack->b_max, stack);
	min_op = get_min_op_by_index_ab(index_a, index_b, stack);
	return (min_op);
}

t_min_op	get_min_op_to_side_b(t_stack *stack)
{
	size_t		index_a;
	t_min_op	min_op;
	t_min_op	min_op_tmp;

	index_a = 0;
	if (stack->a[index_a] > stack->b_max || stack->a[index_a] < stack->b_min)
		min_op = get_min_op_to_b_max(index_a, stack);
	else
		min_op = get_min_op_to_nearest_under_b(index_a, stack);
	index_a++;
	while (stack->a_size > index_a)
	{
		if (stack->a[index_a] > stack->b_max
			|| stack->a[index_a] < stack->b_min)
			min_op_tmp = get_min_op_to_b_max(index_a, stack);
		else
			min_op_tmp = get_min_op_to_nearest_under_b(index_a, stack);
		if (min_op.total_count > min_op_tmp.total_count)
			min_op = min_op_tmp;
		index_a++;
	}
	return (min_op);
}
