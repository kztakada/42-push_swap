/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over_six_get_min_op.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:44:26 by katakada          #+#    #+#             */
/*   Updated: 2024/11/14 15:55:17 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_min_op	get_ra_rb_operations_by_index_ab(size_t index_a, size_t index_b)
{
	t_min_op	min_op;

	min_op = init_min_op();
	if (index_a > index_b)
	{
		min_op.rotate_a = index_a - index_b;
		min_op.rotate_ab = index_b;
	}
	else if (index_a < index_b)
	{
		min_op.rotate_b = index_b - index_a;
		min_op.rotate_ab = index_a;
	}
	else
		min_op.rotate_ab = index_a;
	min_op.total_count = min_op.rotate_a + min_op.rotate_b + min_op.rotate_ab;
	return (min_op);
}

t_min_op	get_rra_rb_operations_by_index_ab(size_t index_a, size_t index_b,
		t_stack *stack)
{
	t_min_op	min_op;

	min_op = init_min_op();
	min_op.r_rotate_a = stack->a_size - index_a;
	min_op.rotate_b = index_b;
	min_op.total_count = min_op.r_rotate_a + min_op.rotate_b;
	return (min_op);
}

t_min_op	get_ra_rrb_operations_by_index_ab(size_t index_a, size_t index_b,
		t_stack *stack)
{
	t_min_op	min_op;

	min_op = init_min_op();
	min_op.rotate_a = index_a;
	min_op.r_rotate_b = stack->b_size - index_b;
	min_op.total_count = min_op.rotate_a + min_op.r_rotate_b;
	return (min_op);
}

t_min_op	get_rra_rrb_operations_by_index_ab(size_t index_a, size_t index_b,
		t_stack *stack)
{
	t_min_op	min_op;
	size_t		r_index_a;
	size_t		r_index_b;

	min_op = init_min_op();
	r_index_a = stack->a_size - index_a;
	r_index_b = stack->b_size - index_b;
	if (r_index_a > r_index_b)
	{
		min_op.r_rotate_ab = r_index_b;
		min_op.r_rotate_a = r_index_a - r_index_b;
	}
	else if (r_index_a < r_index_b)
	{
		min_op.r_rotate_ab = r_index_a;
		min_op.r_rotate_b = r_index_b - r_index_a;
	}
	else
		min_op.r_rotate_ab = r_index_a;
	min_op.total_count = min_op.r_rotate_a + min_op.r_rotate_b
		+ min_op.r_rotate_ab;
	return (min_op);
}

t_min_op	get_min_op_by_index_ab(size_t index_a, size_t index_b,
		t_stack *stack)
{
	t_min_op	ra_rb_op;
	t_min_op	rra_rb_op;
	t_min_op	ra_rrb_op;
	t_min_op	rra_rrb_op;

	ra_rb_op = get_ra_rb_operations_by_index_ab(index_a, index_b);
	rra_rb_op = get_rra_rb_operations_by_index_ab(index_a, index_b, stack);
	ra_rrb_op = get_ra_rrb_operations_by_index_ab(index_a, index_b, stack);
	rra_rrb_op = get_rra_rrb_operations_by_index_ab(index_a, index_b, stack);
	if (ra_rb_op.total_count < rra_rb_op.total_count
		&& ra_rb_op.total_count < ra_rrb_op.total_count
		&& ra_rb_op.total_count < rra_rrb_op.total_count)
		return (ra_rb_op);
	else if (rra_rb_op.total_count < ra_rb_op.total_count
		&& rra_rb_op.total_count < ra_rrb_op.total_count
		&& rra_rb_op.total_count < rra_rrb_op.total_count)
		return (rra_rb_op);
	else if (ra_rrb_op.total_count < ra_rb_op.total_count
		&& ra_rrb_op.total_count < rra_rb_op.total_count
		&& ra_rrb_op.total_count < rra_rrb_op.total_count)
		return (ra_rrb_op);
	else
		return (rra_rrb_op);
}
