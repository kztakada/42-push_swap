/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 17:50:48 by katakada          #+#    #+#             */
/*   Updated: 2024/11/10 18:34:45 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	free_stack(t_stack *stack)
{
	free(stack->a);
	free(stack->b);
	free(stack);
}

void	free_strs(char **strs, int argc)
{
	size_t	i;

	i = 0;
	if (argc > 2)
		return ;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}
