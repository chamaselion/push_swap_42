/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error_stuff2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:30:36 by bszikora          #+#    #+#             */
/*   Updated: 2024/07/17 15:37:07 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_pre_stack_single(int argc, char *argv)
{
	int	*check_array;
	int	i;
	int	val;

	check_array = malloc((argc - 1) * sizeof(int)); 
	i = 1;
	if (argv[1] == '\0' || argv[0] == '\0')
	{
		write_error("Error\n");
		exit(EXIT_FAILURE);
	}
	while (argv[i])
	{
		if (!is_integer(argv))
		{
			write_error("Error\n");
			exit(EXIT_FAILURE);
		}
		val = atoi(argv);
		if (is_value_duplicate(check_array, val, strlen(argv)))
		{
			write_error("Error\n");
			exit(EXIT_FAILURE);
		}
		check_array[i] = val;
		i++;
	}
	free(check_array);
}

