/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_utis2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:22:58 by bszikora          #+#    #+#             */
/*   Updated: 2024/07/16 16:23:27 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	smart_rotate_b(t_Stack *b, int c)
{
	if (b->full_len % 2 == 0)
	{
		if (c > b->full_len / 2)
		{
			rotate_b_down(b, c);
		}
		else
		{
			rotate_b_up(b, c);
		}
	}
	else
	{
		if (c > (b->full_len) / 2)
		{
			rotate_b_down(b, c);
		}
		else
		{
			rotate_b_up(b, c);
		}
	}
}

void	print_stack(t_Stack *a, char *name)
{
	int	i;

	i = a->top;
	printf("%s: ", name);
	while (i >= 0)
	{
		printf("%d ", a->nbr[i]);
		i--;
	}
	printf("\n");
}

int	find_smallest(t_Stack *a)
{
	int	smallest;
	int	i;

	smallest = a->nbr[0];
	i = 1;
	while (i <= a->top)
	{
		if (a->nbr[i] < smallest)
		{
			smallest = a->nbr[i];
		}
		i++;
	}
	return (smallest);
}

int	find_smallest_b(t_Stack *b)
{
	int	smallest;
	int	i;

	smallest = b->nbr[0];
	i = 1;
	while (i <= b->top)
	{
		if (b->nbr[i] < smallest)
		{
			smallest = b->nbr[i];
		}
		i++;
	}
	return (smallest);
}

int	find_biggest(t_Stack *a)
{
	int	biggest;
	int	i;

	biggest = a->nbr[0];
	i = 1;
	while (i <= a->top)
	{
		if (a->nbr[i] > biggest)
		{
			biggest = a->nbr[i];
		}
		i++;
	}
	return (biggest);
}
