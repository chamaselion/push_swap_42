/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_beta.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:14:42 by bszikora          #+#    #+#             */
/*   Updated: 2024/07/17 15:52:14 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mini_sort_3(t_Stack *a)
{
	if (a->nbr[1] > a->nbr[2] && a->nbr[2] > a->nbr[0])
	{
		sa(a);
		rra(a);
	}
	else if (a->nbr[1] > a->nbr[0] && a->nbr[0] > a->nbr[2])
	{
		sa(a);
	}
	else if (a->nbr[2] > a->nbr[0] && a->nbr[0] > a->nbr[1])
	{
		ra(a);
	}
	else if (a->nbr[2] > a->nbr[1] && a->nbr[1] > a->nbr[0])
	{
		rra(a);
	}
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

void	push_swap(t_Stack *a, t_Stack *b)
{
	a->ar = stack_to_array(a);
	sort_array(a->ar, a->top + 1);
	do_hundred(a, b);
	handle_remaining_stack(a, b);
	sort_b_to_a(a, b);
	free(a->ar);
}

int	main(int argc, char **argv)
{
	t_Stack	a;
	t_Stack	b;

	if (argc == 1)
	{
		return (0);
	}
	initialize_stack_a(&a, argc);
	initialize_stack_b(&b, argc);
	if (argc == 2)
	{
		//check_pre_stack_single(argc, argv[1]);
	}
	else if (argc > 2)
	{
		//check_pre_stack(argc, argv);
	}
	fill_stack(&a, argc, argv);
	print_stack(&a, "filled");
	printf("Atop:%i\n", a.top);
	estimate_optimal_chunks(&a);
	push_swap(&a, &b);
	print_stack(&a, "done");
}
