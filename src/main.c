/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 22:57:47 by katakada          #+#    #+#             */
/*   Updated: 2024/11/11 20:47:18 by katakada         ###   ########.fr       */
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

t_list	*get_top_operation(void)
{
	t_list	*operation;
	int		*op_number;

	op_number = (int *)malloc(sizeof(int));
	if (!op_number)
		return (NULL);
	*op_number = TOP;
	operation = ft_lstnew(op_number);
	if (!operation)
		return (NULL);
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

void	print_operations(t_list *operations)
{
	t_list	*ops;

	ops = operations;
	while (ops)
	{
		if (*(int *)ops->content == TOP)
			ft_printf("top\n");
		else if (*(int *)ops->content == SA)
			ft_printf("sa\n");
		else if (*(int *)ops->content == SB)
			ft_printf("sb\n");
		else if (*(int *)ops->content == SS)
			ft_printf("ss\n");
		else if (*(int *)ops->content == PA)
			ft_printf("pa\n");
		else if (*(int *)ops->content == PB)
			ft_printf("pb\n");
		else if (*(int *)ops->content == RA)
			ft_printf("ra\n");
		else if (*(int *)ops->content == RB)
			ft_printf("rb\n");
		else if (*(int *)ops->content == RR)
			ft_printf("rr\n");
		else if (*(int *)ops->content == RRA)
			ft_printf("rra\n");
		else if (*(int *)ops->content == RRB)
			ft_printf("rrb\n");
		else if (*(int *)ops->content == RRR)
			ft_printf("rrr\n");
		ops = ops->next;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*stack;
	t_list	*operations;

	stack = get_init_stack(argc, argv);
	if (!stack)
		return (error_exit(), 1);
	operations = get_top_operation();
	if (!operations)
		return (free_stack(stack), error_exit(), 1);
	print_stack(stack);
	if (is_sorted(stack->a, stack->a_size))
	{
		ft_printf("This is already sorted.\n");
	}
	push_b(stack, &operations);
	print_stack(stack);
	push_b(stack, &operations);
	print_stack(stack);
	swap_ab(stack, &operations);
	// print_operations(operations);
	print_stack(stack);
	free_stack(stack);
	ft_lstclear(&operations, free);
	return (0);
}
