/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 23:25:52 by katakada          #+#    #+#             */
/*   Updated: 2024/11/16 01:02:29 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_sentinel_operation(void)
{
	t_list	*operation;
	int		*op_number;

	op_number = (int *)malloc(sizeof(int));
	if (!op_number)
		return (exit(1), NULL);
	*op_number = TOP;
	operation = ft_lstnew(op_number);
	if (!operation)
		return (exit(1), NULL);
	return (operation);
}

void	print_stack(t_stack *stack)
{
	size_t	i;

	i = 0;
	ft_printf("A stack\n");
	while (stack->a_size > i)
	{
		ft_printf("%d\n", stack->a[i]);
		i++;
	}
	i = 0;
	ft_printf("B stack\n");
	while (stack->b_size > i)
	{
		ft_printf("%d\n", stack->b[i]);
		i++;
	}
}

int	start_sort(t_stack *stack, t_list **operations)
{
	if (stack->a_size == 2)
		return (swap_a(stack, operations));
	if (stack->a_size == 3)
		return (sort_three(stack, operations));
	if (stack->a_size >= 4 && stack->a_size <= 6)
		return (sort_under_six(stack, operations));
	return (sort_over_six(stack, operations));
}

int	main(int argc, char *argv[])
{
	t_stack	*stack;
	t_list	*operations;

	if (argc < 2)
		return (0);
	stack = get_init_stack(argc, argv);
	if (!stack)
		return (error_exit(), 1);
	operations = get_sentinel_operation();
	if (!operations)
		return (free_stack(stack), error_exit(), 1);
	if (!is_sorted(stack->a, stack->a_size))
	{
		if (start_sort(stack, &operations))
		{
			ft_lstclear(&operations, free);
			return (free_stack(stack), error_exit(), 1);
		}
	}
	print_operations(operations);
	free_stack(stack);
	ft_lstclear(&operations, free);
	return (0);
}