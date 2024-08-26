/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error_stuff.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:02:07 by bszikora          #+#    #+#             */
/*   Updated: 2024/08/06 15:00:13 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_error(char *str)
{
	while (*str)
	{
		write(2, str, 1);
		str++;
	}
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_integer(char *str)
{
	if (*str == '-' || *str == '+')
	{
		str++;
	}
	if (!*str)
	{
		return (0);
	}
	while (*str)
	{
		if (!is_digit(*str))
		{
			return (0);
		}
		str++;
	}
	return (1);
}

int	is_value_duplicate(int *check_array, int val, int limit)
{
	int	j;

	j = 0;
	while (j < limit)
	{
		if (check_array[j] == val)
		{
			return (1);
		}
		j++;
	}
	return (0);
}

void	check_pre_stack(int argc, char **argv, t_Stack *a, t_Stack *b)
{
	int	*check_array;
	int	i;
	int	val;

	check_array = malloc((argc - 1) * sizeof(int));
	if (!check_array)
		return ;
	i = 1;
	while (i < argc)
	{
		if (!is_integer(argv[i]) || check_int_range(argv[i]) == 0)
		{
			free(check_array);
			error_call(a, b);
		}
		val = ft_atoi(argv[i]);
		if (is_value_duplicate(check_array, val, i - 1))
		{
			free(check_array);
			error_call(a, b);
		}
		check_array[i - 1] = val;
		i++;
	}
	free(check_array);
}
