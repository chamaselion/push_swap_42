/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:15:41 by bszikora          #+#    #+#             */
/*   Updated: 2024/07/31 13:49:43 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_phase_hundred(t_Stack *a, int cc)
{
	if (cc <= a->no_chunks)
		return (a->current_mid[cc - 1]);
	return (0);
}

void	find_key_array(t_Stack *a)
{
	int	chunk_size;
	int	i;

	chunk_size = (a->top + 1) / a->no_chunks;
	i = 0;
	while (i < a->no_chunks)
	{
		a->current_mid[i] = a->ar[chunk_size * (i + 1)];
		i++;
	}
}

void	do_hundred(t_Stack *a, t_Stack *b)
{
	int	c;
	int	cc;
	int	i;
	int	key_storage;
	int	l;

	cc = 1;
	l = a->top + 1;
	find_key_array(a);
	while (cc <= (a->no_chunks - a->ind))
	{
		i = 0;
		key_storage = check_phase_hundred(a, cc);
		while (i < (l / a->no_chunks) && a->top != -1)
		{
			c = 0;
			a->full_len = a->top + 1;
			while (a->nbr[a->top - c] > key_storage && c != a->top - 1)
				c++;
			smart_rotate(a, c);
			pb(a, b);
			i++;
		}
		cc++;
	}
}

void	sort_b_to_a(t_Stack *a, t_Stack *b)
{
	int	c;

	while (b->top != -1)
	{
		find_biggest_b(b);
		b->full_len = b->top + 1;
		c = 0;
		while (b->nbr[b->top - c] < b->current_biggest && c != b->top)
		{
			c++;
		}
		smart_rotate_b(b, c);
		pa(a, b);
	}
}
