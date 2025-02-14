/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_utis.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:15:17 by bszikora          #+#    #+#             */
/*   Updated: 2024/07/30 11:04:52 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_down(t_Stack *a, int c)
{
	int	move_count;

	move_count = 0;
	while (move_count < ((a->top + 1) - c))
	{
		rra(a);
		move_count++;
	}
}

void	rotate_a_up(t_Stack *a, int c)
{
	int	move_count;

	move_count = 0;
	while (move_count < c)
	{
		ra(a);
		move_count++;
	}
}

void	smart_rotate(t_Stack *a, int c)
{
	if (a->full_len % 2 == 0)
	{
		if (c >= a->full_len / 2)
		{
			rotate_a_down(a, c);
		}
		else
		{
			rotate_a_up(a, c);
		}
	}
	else
	{
		if (c > (a->full_len) / 2)
		{
			rotate_a_down(a, c);
		}
		else
		{
			rotate_a_up(a, c);
		}
	}
}

void	rotate_b_down(t_Stack *b, int c)
{
	int	move_count;

	move_count = 0;
	while (move_count < ((b->top + 1) - c))
	{
		rrb(b);
		move_count++;
	}
}

void	rotate_b_up(t_Stack *b, int c)
{
	int	move_count;

	move_count = 0;
	while (move_count < c)
	{
		rb(b);
		move_count++;
	}
}
