/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_stuff2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:13:36 by bszikora          #+#    #+#             */
/*   Updated: 2024/07/25 16:13:18 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_stack_a_b(t_Stack *a, t_Stack *b, int size)
{
	a->top = size - 1;
	a->nbr = malloc((size - 1) * sizeof(int));
	a->current_smallest = -1;
	a->current_biggest = -1;
	a->full_len = size;
	a->full_move_count = 0;
	a->ar = 0;
	a->current_mid = malloc((size - 1) * sizeof(int));
	a->no_chunks = 1;
	a->ind = 0;
	b->top = -1;
	b->nbr = malloc((size - 1) * sizeof(int));
	b->current_smallest = -1;
	b->current_biggest = -1;
	b->full_len = 0;
	b->full_move_count = 0;
	b->ar = 0;
	b->current_mid = malloc((size - 1) * sizeof(int));
	b->no_chunks = 0;
	b->ind = 0;
}

int	is_sorted(t_Stack *a)
{
	int	i;

	i = a->top;
	while (i > 0)
	{
		if (a->nbr[i] > a->nbr[i - 1])
		{
			return (0);
		}
		i--;
	}
	return (1);
}

void	reverse_int_arr(t_Stack *a, int limit)
{
	int	strg;
	int	c;

	c = 0;
	while (c <= limit / 2)
	{
		strg = a->nbr[c];
		a->nbr[c] = a->nbr[limit - c];
		a->nbr[limit - c] = strg;
		c++;
	}
}

int	count_integer_in_str(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] && !(str[i] >= '0' && str[i] <= '9'))
		{
			i++;
		}
		if (str[i] != '\0')
		{
			count++;
			while (str[i] && (str[i] >= '0' && str[i] <= '9'))
			{
				i++;
			}
		}
	}
	return (count);
}

void	handle_remaining_stack(t_Stack *a, t_Stack *b)
{
	int	c;

	while (a->top != 0)
	{
		c = 0;
		a->current_smallest = find_smallest(a);
		while (a->nbr[a->top - c] != a->current_smallest)
		{
			c++;
		}
		smart_rotate(a, c);
		pb(a, b);
	}
}
