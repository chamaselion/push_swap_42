/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_stuff2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:13:36 by bszikora          #+#    #+#             */
/*   Updated: 2024/08/06 15:02:23 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_malloc(int **arr, int l)
{
	*arr = (int *)malloc(sizeof(int) * l);
	if (!*arr)
		return (1);
	return (0);
}

void	initialize_stack_a_b(t_Stack *a, t_Stack *b, int size)
{
	a->top = size - 1;
	if (ft_malloc(&a->nbr, (size)) == 1)
		return ;
	a->current_smallest = -1;
	a->current_biggest = -1;
	a->full_len = size;
	a->full_move_count = 0;
	a->ar = 0;
	if (ft_malloc(&a->current_mid, size) == 1)
		return ;
	a->no_chunks = 1;
	a->ind = 0;
	b->top = -1;
	if (ft_malloc(&b->nbr, size) == 1)
		return ;
	b->current_smallest = -1;
	b->current_biggest = -1;
	b->full_len = 0;
	b->full_move_count = 0;
	b->ar = 0;
	if (ft_malloc(&b->current_mid, (size)) == 1)
		return ;
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
