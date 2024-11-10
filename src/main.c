/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 22:57:47 by katakada          #+#    #+#             */
/*   Updated: 2024/11/10 18:38:17 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack;
	size_t	i;

	stack = get_init_stack(argc, argv);
	i = 0;
	while (stack->a_size > i)
	{
		ft_printf("%d\n", stack->a[i]);
		i++;
	}
	free_stack(stack);
	return (0);
}
