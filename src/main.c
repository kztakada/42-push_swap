/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 22:57:47 by katakada          #+#    #+#             */
/*   Updated: 2024/11/11 18:04:39 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(int *stack, size_t stack_size)
{
	size_t	i;

	i = 0;
	while (i < stack_size - 1)
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack;
	size_t	i;

	stack = get_init_stack(argc, argv);
	if (!stack)
		return (error_exit(), 1);
	i = 0;
	if (is_sorted(stack->a, stack->a_size))
	{
		ft_printf("This is already sorted.\n");
	}
	while (stack->a_size > i)
	{
		ft_printf("%d\n", stack->a[i]);
		i++;
	}
	free_stack(stack);
	return (0);
}
