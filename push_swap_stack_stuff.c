/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_stuff.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:04:10 by bszikora          #+#    #+#             */
/*   Updated: 2024/07/17 15:40:52 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(t_Stack *a, int argc, char **argv)
{
	int	i;

	if (argc > 2)
	{
		i = argc - 1;
		while (i >= 1)
		{
			a->nbr[argc - i - 1] = atoi(argv[i]);
			i--;
		}
		a->top = argc - 2;
	}
	else if (argc == 2)
	{
		i = 0;
		a->nbr[0] = atoi(argv[1]);
		a->top = strlen(argv[1]);
	}
}

void	fill_stack_from_string(t_Stack *a, char *input)
{
	char	*token;
	int		i;
	long	val;
	char	*endptr;

	i = 0;
	token = strtok(input, " ");
	while (token != NULL)
	{
		val = strtol(token, &endptr, 10);
		if (*endptr != '\0')
		{
			fprintf(stderr, "Error: Invalid integer in input '%s'\n", token);
			exit(EXIT_FAILURE);
		}
		a->nbr[i] = (int)val;
		i++;
		token = strtok(NULL, " ");
	}
	a->top = i - 1;
}

void	print_array(int *array, int size)
{
	int	i;

	i = 0;
	printf("[");
	while (i < size)
	{
		printf("%d", array[i]);
		if (i < size - 1)
		{
			printf(", ");
		}
		i++;
	}
	printf("]\n");
}

int	*stack_to_array(t_Stack *a)
{
	int	*array;
	int	i;

	array = malloc(sizeof(int) * (a->top + 1));
	i = 0;
	while (i <= a->top)
	{
		array[i] = a->nbr[i];
		i++;
	}
	return (array);
}

void	sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
