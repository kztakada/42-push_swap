/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_init_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:38:42 by katakada          #+#    #+#             */
/*   Updated: 2024/11/30 17:05:50 by katakada         ###   ########.fr       */
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

void	convert_space(unsigned int index, char *character)
{
	(void)index;
	if ((*character >= '\t' && *character <= '\r'))
		*character = ' ';
}

char	**get_arg_strs_and_size(int argc, char **argv, size_t *stack_size)
{
	char	**arg_strs;

	arg_strs = NULL;
	if (argc == 2)
	{
		ft_striteri(argv[1], &convert_space);
		arg_strs = ft_split(argv[1], ' ');
		if (!arg_strs)
			return (NULL);
		while (arg_strs[(*stack_size)])
			(*stack_size)++;
	}
	else
	{
		arg_strs = argv + 1;
		(*stack_size) = argc - 1;
	}
	return (arg_strs);
}

t_stack	*get_validated_stack(int argc, char **argv)
{
	t_stack	*stack;
	size_t	stack_size;
	char	**arg_strs;

	stack_size = 0;
	arg_strs = get_arg_strs_and_size(argc, argv, &stack_size);
	if (!arg_strs)
		return (NULL);
	if (!is_all_int_str(arg_strs, stack_size))
		return (free_strs(arg_strs, stack_size, argc), NULL);
	stack = get_init_stack(stack_size);
	if (!stack)
		return (free_strs(arg_strs, stack_size, argc), NULL);
	convert_push_to_stack_a(stack, arg_strs);
	if (has_duplication(stack->a, stack->a_size))
		return (free_stack(stack), free_strs(arg_strs, stack_size, argc), NULL);
	free_strs(arg_strs, stack_size, argc);
	return (stack);
}
