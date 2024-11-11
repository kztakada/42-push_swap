/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_init_stack_funcs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:55:19 by katakada          #+#    #+#             */
/*   Updated: 2024/11/11 17:55:20 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_int_str(char *str_pos, int sign)
{
	unsigned long	int_value;
	int				digit_value;
	unsigned long	max_limit;

	int_value = 0;
	max_limit = (unsigned long)INT_MAX;
	if (!ft_isdigit(*str_pos))
		return (error_exit(), 0);
	while (ft_isdigit(*str_pos))
	{
		if (!ft_isdigit(*str_pos))
			return (error_exit(), 0);
		digit_value = *str_pos - '0';
		if (sign == 1 && int_value > ((max_limit - digit_value) / 10))
			return (error_exit(), 0);
		if (sign == -1 && int_value > ((max_limit + 1 - digit_value) / 10))
			return (error_exit(), 0);
		int_value = int_value * 10 + digit_value;
		str_pos++;
	}
	return (1);
}

int	is_int_number_strs(char **stack_strs, size_t stack_size)
{
	int		sign;
	size_t	i;
	size_t	j;

	sign = 1;
	i = 0;
	while (i < stack_size)
	{
		j = 0;
		while (stack_strs[i][j] == ' ' || (stack_strs[i][j] >= '\t'
				&& stack_strs[i][j] <= '\r'))
			j++;
		if (stack_strs[i][j] == '-' || stack_strs[i][j] == '+')
		{
			if (stack_strs[i][j] == '-')
				sign = -1;
			j++;
		}
		if (!is_int_str(&(stack_strs[i][j]), sign))
			return (0);
		i++;
	}
	return (1);
}

int	has_duplication(int *stack, size_t stack_size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < stack_size)
	{
		j = i + 1;
		while (j < stack_size)
		{
			if (stack[i] == stack[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
