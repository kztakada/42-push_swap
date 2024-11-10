/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_int_number_strs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:51:00 by katakada          #+#    #+#             */
/*   Updated: 2024/11/10 19:21:09 by katakada         ###   ########.fr       */
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
	while (ft_isdigit(*str_pos))
	{
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

int	is_int_number_strs(char **stack_strs)
{
	int		sign;
	size_t	i;

	sign = 1;
	i = 0;
	while ((stack_strs + i))
	{
		while (**(stack_strs + i) == ' ' || (**(stack_strs + i) >= '\t'
				&& **(stack_strs + i) <= '\r'))
			(*(stack_strs + i))++;
		if (**(stack_strs + i) == '-' || **(stack_strs + i) == '+')
		{
			if (**(stack_strs + i) == '-')
				sign = -1;
			(*(stack_strs + i))++;
		}
		if (!is_int_str(*(stack_strs + i), sign))
			return (0);
		i++;
	}
	return (1);
}
