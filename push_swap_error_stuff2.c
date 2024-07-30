/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error_stuff2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:30:36 by bszikora          #+#    #+#             */
/*   Updated: 2024/07/30 14:02:24 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <ctype.h>
#include <stdlib.h>

int	is_it_duplicate_tho(int *array, int limit)
{
	int	i;
	int	j;

	i = 0;
	while (i < limit - 1)
	{
		j = i + 1;
		while (j < limit)
		{
			if (array[i] == array[j])
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_int_range(char *str)
{
	long long	num;
	int			i;
	int			sign;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		if ((sign == 1 && num > INT_MAX) || (sign == -1
				&& - num < INT_MIN))
			return (0);
		i++;
	}
	return (1);
}

void	check_int_range_single(const char *argv)
{
	char	*token;
	char	*input_copy;
	size_t	len;

	len = ft_strlen(argv) + 1;
	input_copy = malloc(len * sizeof(char));
	if (!input_copy)
	{
		write_error("Error\n");
		exit(EXIT_FAILURE);
	}
	ft_strncpy(input_copy, argv, len);
	token = ft_strtok(input_copy, " \t");
	while (token != NULL)
	{
		if (!check_int_range(token))
		{
			free(input_copy);
			write_error("Error\n");
			exit(EXIT_FAILURE);
		}
		token = ft_strtok(NULL, " \t");
	}
	free(input_copy);
}

void	check_pre_stack_single(char *argv)
{
	int	c;

	c = 0;
	check_int_range_single(argv);
	if (argv[0] == '\0')
	{
		write_error("Error\n");
		exit(EXIT_FAILURE);
	}
	while (argv[c] != '\0')
	{
		if (!((argv[c] >= '0' && argv[c] <= '9') || argv[c] == ' '
				|| argv[c] == '\t' || argv[c] == '-'))
		{
			write_error("Error\n");
			exit(EXIT_FAILURE);
		}
		c++;
	}
}

void	cleanup(t_Stack *a, t_Stack *b)
{
	free(a->nbr);
	free(a->current_mid);
	if (a->ar)
	{
		free(a->ar);
	}
	free(b->nbr);
	free(b->current_mid);
	if (b->ar)
	{
		free(b->ar);
	}
}
