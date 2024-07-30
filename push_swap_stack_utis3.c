/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_utis3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:23:31 by bszikora          #+#    #+#             */
/*   Updated: 2024/07/30 11:04:55 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_biggest_b(t_Stack *b)
{
	int	biggest;
	int	i;

	biggest = b->nbr[0];
	i = 1;
	while (i <= b->top)
	{
		if (b->nbr[i] > biggest)
		{
			biggest = b->nbr[i];
		}
		i++;
	}
	b->current_biggest = biggest;
}
