/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:47:06 by katakada          #+#    #+#             */
/*   Updated: 2024/11/29 17:58:27 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	add_back_operation(int op_specifier, t_list **operations)
{
	int	*op_nunber;

	op_nunber = (int *)malloc(sizeof(int));
	if (!op_nunber)
		return (1);
	*op_nunber = op_specifier;
	if (ft_lstadd_back(operations, ft_lstnew(op_nunber)))
		return (1);
	return (0);
}
