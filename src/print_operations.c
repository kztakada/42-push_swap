/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 23:31:15 by katakada          #+#    #+#             */
/*   Updated: 2024/11/11 23:39:27 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_swap(int op_nmber)
{
	if (op_nmber == SA)
		ft_printf("sa\n");
	else if (op_nmber == SB)
		ft_printf("sb\n");
	else if (op_nmber == SS)
		ft_printf("ss\n");
}

void	print_push(int op_nmber)
{
	if (op_nmber == PA)
		ft_printf("pa\n");
	else if (op_nmber == PB)
		ft_printf("pb\n");
}

void	print_rotate(int op_nmber)
{
	if (op_nmber == RA)
		ft_printf("ra\n");
	else if (op_nmber == RB)
		ft_printf("rb\n");
	else if (op_nmber == RR)
		ft_printf("rr\n");
}

void	print_reverse_rotate(int op_nmber)
{
	if (op_nmber == RRA)
		ft_printf("rra\n");
	else if (op_nmber == RRB)
		ft_printf("rrb\n");
	else if (op_nmber == RRR)
		ft_printf("rrr\n");
}

void	print_operations(t_list *operations)
{
	t_list	*ops;

	ops = operations;
	while (ops)
	{
		if (*(int *)ops->content == SA || *(int *)ops->content == SB
			|| *(int *)ops->content == SS)
			print_swap(*(int *)ops->content);
		else if (*(int *)ops->content == PA || *(int *)ops->content == PB)
			print_push(*(int *)ops->content);
		else if (*(int *)ops->content == RA || *(int *)ops->content == RB
			|| *(int *)ops->content == RR)
			print_rotate(*(int *)ops->content);
		else if (*(int *)ops->content == RRA || *(int *)ops->content == RRB
			|| *(int *)ops->content == RRR)
			print_reverse_rotate(*(int *)ops->content);
		ops = ops->next;
	}
}
