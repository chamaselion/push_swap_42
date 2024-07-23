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

void mini_sort_2(t_Stack *a)
{
    if (a->nbr[1] > a->nbr[0])
    {
        sa(a);
    }
}

void mini_sort_3(t_Stack *a)
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
    else if (a->nbr[2] > a->nbr[1] && a->nbr[1] < a->nbr[0] && a->nbr[2] > a->nbr[0])
    {
        ra(a);
    }
    else if (a->nbr[2] < a->nbr[1] && a->nbr[1] > a->nbr[0] && a->nbr[2] < a->nbr[0])
    {
        sa(a);
        ra(a);
    }
    else if (a->nbr[2] < a->nbr[1] && a->nbr[1] > a->nbr[0] && a->nbr[2] > a->nbr[0])
    {
        rra(a);
    }
}

void mini_sort_4(t_Stack *a, t_Stack *b)
{
int c;
int i;

i = 0;
c = find_smallest(a);
while (a->nbr[a->top - i] != c)
{
	i++;
}

printf("Smallest:%i\n", i);
smart_rotate(a, i);
pb(a, b);
mini_sort_3(a);
print_stack(a, "A");
print_stack(b, "B");
pa(a, b);

}

void mini_sort_5(t_Stack *a, t_Stack *b)
{
int c;
int i;

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

int	is_sorted(t_Stack *a)
{
	int	i;

	i = a->top;
	while (i >= 0)
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
	if (a->top == 1)
	{
		mini_sort_2(a);
		printf("minisort2\n");
	}
	
	else if (a->top == 2)
	{
		mini_sort_3(a);
		printf("minisort3\n");
	}

	else if (a->top == 3)
	{
		mini_sort_4(a, b);
		printf("minisort4\n");
	}
	else if (a->top == 4)
	{
		mini_sort_5(a, b);
		printf("minisort4\n");
	}
	else if (a->top > 4)
	{
	a->ar = stack_to_array(a);
	sort_array(a->ar, a->top + 1);
	do_hundred(a, b);
	handle_remaining_stack(a, b);
	sort_b_to_a(a, b);
	free(a->ar);
	printf("bigsort\n");
	}
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
		check_pre_stack_single(argv[1]);
		fill_stack_from_str(&a, argv[1]);
		reverse_int_arr(&a, a.top);
		if (is_it_duplicate_tho(a.nbr, a.top))
		{
			write_error("Error\n");
			exit(EXIT_FAILURE);
		}
	}
	else if (argc > 2)
	{
		check_pre_stack(argc, argv);
		fill_stack(&a, argc, argv);
	}
	if (is_sorted(&a) == 1)
	{
		write_error("Error\n");
		exit(EXIT_FAILURE);
	}
	estimate_optimal_chunks(&a);
	push_swap(&a, &b);
	//print_stack(&a, "Done");
	int res = a.full_move_count + b.full_move_count;
	int issort = is_sorted(&a);
	printf("mc:%i\nissort:%i", res, issort);
}
