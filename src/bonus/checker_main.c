/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 23:25:28 by katakada          #+#    #+#             */
/*   Updated: 2024/11/29 20:23:35 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_command_push_swap(t_stack *stack, char *new_line)
{
	if (!ft_strncmp(new_line, "sa", 2) && new_line[2] == '\n')
		return (swap_a(stack, NULL), 1);
	if (!ft_strncmp(new_line, "sb", 2) && new_line[2] == '\n')
		return (swap_b(stack, NULL), 1);
	if (!ft_strncmp(new_line, "ss", 2) && new_line[2] == '\n')
		return (swap_ab(stack, NULL), 1);
	if (!ft_strncmp(new_line, "pa", 2) && new_line[2] == '\n')
		return (push_a(stack, NULL), 1);
	if (!ft_strncmp(new_line, "pb", 2) && new_line[2] == '\n')
		return (push_b(stack, NULL), 1);
	return (0);
}

int	check_command_rotate(t_stack *stack, char *new_line)
{
	if (!ft_strncmp(new_line, "ra", 2) && new_line[2] == '\n')
		return (rotate_a(stack, NULL), 1);
	if (!ft_strncmp(new_line, "rb", 2) && new_line[2] == '\n')
		return (rotate_b(stack, NULL), 1);
	if (!ft_strncmp(new_line, "rr", 2) && new_line[2] == '\n')
		return (rotate_ab(stack, NULL), 1);
	if (!ft_strncmp(new_line, "rra", 3) && new_line[3] == '\n')
		return (reverse_rotate_a(stack, NULL), 1);
	if (!ft_strncmp(new_line, "rrb", 3) && new_line[3] == '\n')
		return (reverse_rotate_b(stack, NULL), 1);
	if (!ft_strncmp(new_line, "rrr", 3) && new_line[3] == '\n')
		return (reverse_rotate_ab(stack, NULL), 1);
	return (0);
}

void	check_command(t_stack *stack, char *new_line)
{
	char	*cmp_line;

	cmp_line = new_line;
	while (new_line)
	{
		if (!check_command_push_swap(stack, new_line))
			if (!check_command_rotate(stack, new_line))
				return (free(new_line), free_stack(stack), error_exit());
		new_line = get_next_line(0);
		free(cmp_line);
		cmp_line = new_line;
	}
	if (stack->b_size)
		ft_printf("KO\n");
	else if (!is_sorted(stack->a, stack->a_size))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
}

int	main(int argc, char *argv[])
{
	t_stack	*stack;
	char	*new_line;

	if (argc < 2)
		return (0);
	stack = get_validated_stack(argc, argv);
	if (!stack)
		return (error_exit(), 1);
	new_line = get_next_line(0);
	if (!new_line && !is_sorted(stack->a, stack->a_size))
		ft_printf("KO\n");
	else if (!new_line && is_sorted(stack->a, stack->a_size))
		ft_printf("OK\n");
	else
		check_command(stack, new_line);
	free_stack(stack);
	return (0);
}
