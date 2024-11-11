/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 22:57:47 by katakada          #+#    #+#             */
/*   Updated: 2024/11/11 17:05:15 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack;
	size_t	i;

	stack = get_init_stack(argc, argv);
	if (!stack)
		return (error_exit(), 1);
	i = 0;
	while (stack->a_size > i)
	{
		ft_printf("%d\n", stack->a[i]);
		i++;
	}
	free_stack(stack);
	return (0);
}
