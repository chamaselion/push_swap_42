/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap-movements2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:15:40 by bszikora          #+#    #+#             */
/*   Updated: 2024/07/16 15:15:58 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_Stack *a, t_Stack *b)
{
	if (b->top >= 0)
	{
		a->nbr[++a->top] = b->nbr[b->top--];
	}
	printf("pa\n");
	a->full_move_count++;
}

void	rra(t_Stack *a)
{
	int	temp;
	int	i;

	i = 0;
	if (a->top < 0)
	{
		return ;
	}
	temp = a->nbr[0];
	while (i < a->top)
	{
		a->nbr[i] = a->nbr[i + 1];
		i++;
	}
	a->nbr[a->top] = temp;
	printf("rra\n");
	a->full_move_count++;
}

void	rrb(t_Stack *b)
{
	int	temp;
	int	i;

	i = 0;
	if (b->top < 0)
	{
		return ;
	}
	temp = b->nbr[0];
	while (i < b->top)
	{
		b->nbr[i] = b->nbr[i + 1];
		i++;
	}
	b->nbr[b->top] = temp;
	printf("rrb\n");
	b->full_move_count++;
}
