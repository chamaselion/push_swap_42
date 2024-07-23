/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_movements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:15:03 by bszikora          #+#    #+#             */
/*   Updated: 2024/07/16 15:16:03 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_Stack *a)
{
	int	temp;

	if (a->top >= 1)
	{
		temp = a->nbr[a->top];
		a->nbr[a->top] = a->nbr[a->top - 1];
		a->nbr[a->top - 1] = temp;
	}
	printf("sa\n");
	a->full_move_count++;
}

void	sb(t_Stack *b)
{
	int	temp;

	if (b->top >= 1)
	{
		temp = b->nbr[b->top];
		b->nbr[b->top] = b->nbr[b->top - 1];
		b->nbr[b->top - 1] = temp;
	}
	printf("sb\n");
	b->full_move_count++;
}

void	ra(t_Stack *a)
{
	int	temp;
	int	i;

	i = a->top;
	if (a->top < 0)
	{
		return ;
	}
	temp = a->nbr[a->top];
	while (i > 0)
	{
		a->nbr[i] = a->nbr[i - 1];
		i--;
	}
	a->nbr[0] = temp;
	printf("ra\n");
	a->full_move_count++;
}

void	rb(t_Stack *b)
{
	int	temp;
	int	i;

	i = b->top;
	if (b->top < 0)
	{
		return ;
	}
	temp = b->nbr[b->top];
	while (i > 0)
	{
		b->nbr[i] = b->nbr[i - 1];
		i--;
	}
	b->nbr[0] = temp;
	printf("rb\n");
	b->full_move_count++;
}

void	pb(t_Stack *a, t_Stack *b)
{
	if (a->top >= 0)
	{
		b->nbr[++b->top] = a->nbr[a->top--];
	}
	printf("pb\n");
	a->full_move_count++;
}
