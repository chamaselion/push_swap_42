/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_stuff3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:02:50 by bszikora          #+#    #+#             */
/*   Updated: 2024/08/06 15:02:58 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
