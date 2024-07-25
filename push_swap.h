/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:15:25 by bszikora          #+#    #+#             */
/*   Updated: 2024/07/25 16:13:56 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <unistd.h>
# include <ctype.h>

typedef struct Stack
{
	int	top;
	int	*nbr;
	int	current_smallest;
	int	current_biggest;
	int	full_len;
	int	full_move_count;
	int	*ar;
	int	*current_mid;
	int	no_chunks;
	int	ind;
}		t_Stack;

/* push_swap_movements */
void	sa(t_Stack *a);
void	sb(t_Stack *b);
void	ra(t_Stack *a);
void	rb(t_Stack *b);
void	pb(t_Stack *a, t_Stack *b);
void	pa(t_Stack *a, t_Stack *b);
void	rra(t_Stack *a);
void	rrb(t_Stack *b);

/* push_swap_error_stuff */
void	write_error(char *str);
int		is_digit(char c);
int		is_integer(char *str);
int		is_value_duplicate(int *check_array, int val, int limit);
void	check_pre_stack(int argc, char **argv);
void	check_pre_stack_single(char *argv);
int		is_it_duplicate_tho(int *array, int limit);

/* push_swap_chunk_stuff */
int		find_max_element(int arr[], int n);
int		longest_increasing_subsequence(int arr[], int n);
void	estimate_optimal_chunks(t_Stack *a);
void	set_chunks(t_Stack *a);

/* push_swap_beta */
void	push_swap(t_Stack *a, t_Stack *b);
int		main(int argc, char **argv);

/* push_swap_stack_stuff */
void	handle_remaining_stack(t_Stack *a, t_Stack *b);
int		count_integer_in_str(char *str);
void	fill_stack(t_Stack *a, int argc, char **argv);
void	print_array(int *array, int size);
int		*stack_to_array(t_Stack *a);
void	sort_array(int *array, int size);
void	initialize_stack_a_b(t_Stack *a, t_Stack *b, int argc);
void	smart_rotate(t_Stack *a, int c);
void	smart_rotate_b(t_Stack *b, int c);
void	print_stack(t_Stack *a, char *name);
int		find_smallest_b(t_Stack *b);
int		find_biggest(t_Stack *a);
void	find_biggest_b(t_Stack *b);
int		find_smallest(t_Stack *a);
int		find_smallest_b(t_Stack *b);
int		find_biggest(t_Stack *a);
void	find_biggest_b(t_Stack *b);
void	rotate_b_down(t_Stack *b, int c);
void	rotate_b_up(t_Stack *b, int c);
int		count_integers_in_string(char *str);
void	fill_stack_from_str(t_Stack *a, char *input);
void	reverse_int_arr(t_Stack *a, int limit);
int		is_sorted(t_Stack *a);

/* push_swap_sort */
int		check_phase_hundred(t_Stack *a, int cc);
void	find_key_array(t_Stack *a);
void	do_hundred(t_Stack *a, t_Stack *b);
void	sort_b_to_a(t_Stack *a, t_Stack *b);
void	mini_sort_5(t_Stack *a, t_Stack *b);
void	mini_sort_4(t_Stack *a, t_Stack *b);
void	mini_sort_3(t_Stack *a);
void	mini_sort_2(t_Stack *a);

/* push_swap_utis */

#endif