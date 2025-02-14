/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_mini_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:37:09 by bszikora          #+#    #+#             */
/*   Updated: 2024/07/30 11:04:46 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mini_sort_2(t_Stack *a)
{
	if (a->nbr[1] > a->nbr[0])
	{
		sa(a);
	}
}

void	mini_sort_3(t_Stack *a)
{
	if (a->nbr[2] > a->nbr[1] && a->nbr[1] < a->nbr[0] && a->nbr[2] < a->nbr[0])
	{
		sa(a);
	}
	else if (a->nbr[2] > a->nbr[1] && a->nbr[1] > a->nbr[0])
	{
		sa(a);
		rra(a);
	}
	else if (a->nbr[2] > a->nbr[1] && a->nbr[1] < a->nbr[0]
		&& a->nbr[2] > a->nbr[0])
	{
		ra(a);
	}
	else if (a->nbr[2] < a->nbr[1] && a->nbr[1] > a->nbr[0]
		&& a->nbr[2] < a->nbr[0])
	{
		sa(a);
		ra(a);
	}
	else if (a->nbr[2] < a->nbr[1] && a->nbr[1] > a->nbr[0]
		&& a->nbr[2] > a->nbr[0])
	{
		rra(a);
	}
}

void	mini_sort_4(t_Stack *a, t_Stack *b)
{
	int	c;
	int	i;

	i = 0;
	c = find_smallest(a);
	while (a->nbr[a->top - i] != c)
	{
		i++;
	}
	smart_rotate(a, i);
	pb(a, b);
	mini_sort_3(a);
	pa(a, b);
}

void	mini_sort_5(t_Stack *a, t_Stack *b)
{
	int	c;
	int	i;

	i = 0;
	c = find_smallest(a);
	while (a->nbr[a->top - i] != c)
	{
		i++;
	}
	smart_rotate(a, i);
	pb(a, b);
	mini_sort_4(a, b);
	pa(a, b);
}
