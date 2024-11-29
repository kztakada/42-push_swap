/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over_six_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:47:42 by katakada          #+#    #+#             */
/*   Updated: 2024/11/29 18:21:49 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_min_op	init_min_op(void)
{
	t_min_op	min_op;

	min_op.rotate_a = 0;
	min_op.rotate_b = 0;
	min_op.rotate_ab = 0;
	min_op.r_rotate_a = 0;
	min_op.r_rotate_b = 0;
	min_op.r_rotate_ab = 0;
	min_op.total_count = 0;
	return (min_op);
}

size_t	get_index_by_num(int num, size_t size, int *stack)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (stack[i] == num)
			return (i);
		i++;
	}
	return (exit(1), 0);
}
