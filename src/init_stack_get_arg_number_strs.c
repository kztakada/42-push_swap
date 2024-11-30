/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_get_arg_number_strs.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 19:53:14 by katakada          #+#    #+#             */
/*   Updated: 2024/11/30 20:32:42 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*strjoin_free(char *allocated_str, char *reference_str)
{
	char	*str;

	str = ft_strjoin(allocated_str, reference_str);
	free(allocated_str);
	return (str);
}

int	has_no_number(char *arg_str)
{
	int	i;

	if (!arg_str)
		return (1);
	if (!arg_str[0])
		return (1);
	i = 0;
	while (arg_str[i])
	{
		if (ft_isdigit(arg_str[i]))
			return (0);
		i++;
	}
	return (1);
}

char	*convert_args_to_one_str(int argc, char **argv)
{
	char	*one_str;
	int		i;

	if (argc < 2)
		return (NULL);
	one_str = ft_strdup(argv[1]);
	if (!one_str)
		return (NULL);
	if (argc == 2)
		return (one_str);
	i = 2;
	while (i < argc)
	{
		if (has_no_number(argv[i]))
			return (free(one_str), NULL);
		one_str = strjoin_free(one_str, " ");
		if (!one_str)
			return (NULL);
		one_str = strjoin_free(one_str, argv[i]);
		if (!one_str)
			return (NULL);
		i++;
	}
	return (one_str);
}

void	convert_space(unsigned int index, char *character)
{
	(void)index;
	if ((*character >= '\t' && *character <= '\r'))
		*character = ' ';
}

char	**get_arg_number_strs(int argc, char **argv)
{
	char	**arg_strs;
	char	*one_str;

	one_str = convert_args_to_one_str(argc, argv);
	if (!one_str)
		return (NULL);
	ft_striteri(one_str, &convert_space);
	arg_strs = ft_split(one_str, ' ');
	free(one_str);
	if (!arg_strs)
		return (NULL);
	if (!is_all_int_str(arg_strs))
		return (free_strs(arg_strs), NULL);
	return (arg_strs);
}
