/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:47:06 by katakada          #+#    #+#             */
/*   Updated: 2024/11/11 20:47:25 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_back_operation(int num, t_list **operations)
{
	int	*op_nunber;

	op_nunber = (int *)malloc(sizeof(int));
	if (!op_nunber)
		return (exit(1), 1);
	*op_nunber = num;
	ft_lstadd_back(operations, ft_lstnew(op_nunber));
	return (0);
}
