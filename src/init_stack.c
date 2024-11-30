/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 19:49:50 by katakada          #+#    #+#             */
/*   Updated: 2024/11/30 19:54:44 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_init_stack(size_t stack_size)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->a = (int *)malloc(sizeof(int) * stack_size);
	if (!stack->a)
		return (free(stack), NULL);
	stack->b = (int *)malloc(sizeof(int) * stack_size);
	if (!stack->b)
		return (free(stack->a), free(stack), NULL);
	stack->a_size = stack_size;
	stack->a_min = INT_MAX;
	stack->a_max = INT_MIN;
	stack->b_size = 0;
	stack->b_min = INT_MAX;
	stack->b_max = INT_MIN;
	return (stack);
}

void	convert_push_to_stack_a(t_stack *stack, char **arg_strs)
{
	size_t	i;

	i = 0;
	while (arg_strs[i])
	{
		stack->a[i] = ft_atoi(arg_strs[i]);
		if (stack->a[i] < stack->a_min)
			stack->a_min = stack->a[i];
		if (stack->a[i] > stack->a_max)
			stack->a_max = stack->a[i];
		i++;
	}
}

int	get_arg_numbers_size(char **arg_strs)
{
	int	i;

	i = 0;
	while (arg_strs[i])
		i++;
	return (i);
}

t_stack	*get_validated_stack(int argc, char **argv)
{
	t_stack	*stack;
	size_t	arg_numbers_size;
	char	**arg_number_strs;

	arg_number_strs = get_arg_number_strs(argc, argv);
	if (!arg_number_strs)
		return (NULL);
	arg_numbers_size = get_arg_numbers_size(arg_number_strs);
	stack = get_init_stack(arg_numbers_size);
	if (!stack)
		return (free_strs(arg_number_strs), NULL);
	convert_push_to_stack_a(stack, arg_number_strs);
	if (has_duplication(stack->a, stack->a_size))
		return (free_stack(stack), free_strs(arg_number_strs), NULL);
	free_strs(arg_number_strs);
	return (stack);
}
