/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_beta.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:14:42 by bszikora          #+#    #+#             */
/*   Updated: 2024/07/30 12:44:23 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_Stack *a, t_Stack *b)
{
	if (a->top == 1)
	{
		mini_sort_2(a);
	}
	else if (a->top == 2)
	{
		mini_sort_3(a);
	}
	else if (a->top == 3)
	{
		mini_sort_4(a, b);
	}
	else if (a->top == 4)
	{
		mini_sort_5(a, b);
	}
	else if (a->top > 4)
	{
		a->ar = stack_to_array(a);
		sort_array(a->ar, a->top + 1);
		do_hundred(a, b);
		handle_remaining_stack(a, b);
		sort_b_to_a(a, b);
		free(a->ar);
	}
}

void	handle_single_arg(t_Stack *a, t_Stack *b, char *arg)
{
	int	count;

	count = count_integer_in_str(arg);
	initialize_stack_a_b(a, b, (count));
	check_pre_stack_single(arg);
	fill_stack_from_str(a, arg);
	reverse_int_arr(a, a->top);
	if (is_it_duplicate_tho(a->nbr, a->top))
	{
		write_error("Error\n");
		exit(EXIT_FAILURE);
	}
}

void	handle_multiple_args(t_Stack *a, t_Stack *b, int argc, char **argv)
{
	int	count;

	count = argc;
	initialize_stack_a_b(a, b, count);
	check_pre_stack(argc, argv);
	fill_stack(a, argc, argv);
}

void	process_stacks(t_Stack *a, t_Stack *b)
{
	if (is_sorted(a) == 1)
	{
		write_error("Error\n");
		exit(EXIT_FAILURE);
	}
	estimate_optimal_chunks(a);
	push_swap(a, b);
}

int	main(int argc, char **argv)
{
	t_Stack	a;
	t_Stack	b;

	if (argc == 1)
	{
		return (0);
	}
	if (argc == 2)
	{
		handle_single_arg(&a, &b, argv[1]);
	}
	else if (argc > 2)
	{
		handle_multiple_args(&a, &b, argc, argv);
	}
	process_stacks(&a, &b);
}
