/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_stuff2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:13:36 by bszikora          #+#    #+#             */
/*   Updated: 2024/07/17 15:54:24 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_stack_a(t_Stack *a, int argc)
{
	a->top = argc - 2;
	a->nbr = malloc((argc - 1) * sizeof(int));
	a->current_smallest = -1;
	a->current_biggest = -1;
	a->full_len = argc - 1;
	a->full_move_count = 0;
	a->ar = 0;
	a->current_mid = malloc((argc - 1) * sizeof(int));
	a->no_chunks = 1;
	a->ind = 0;
}

void	initialize_stack_b(t_Stack *b, int argc)
{
	b->top = -1;
	b->nbr = malloc((argc - 1) * sizeof(int));
	b->current_smallest = -1;
	b->current_biggest = -1;
	b->full_len = 0;
	b->full_move_count = 0;
	b->ar = 0;
	b->current_mid = malloc((argc - 1) * sizeof(int));
	b->no_chunks = 0;
	b->ind = 0;
}
