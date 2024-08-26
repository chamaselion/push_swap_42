/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_chunk_stuff.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:03:14 by bszikora          #+#    #+#             */
/*   Updated: 2024/08/02 14:58:47 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_element(int arr[], int n)
{
	int	max;
	int	i;

	max = arr[0];
	i = 1;
	while (i < n)
	{
		if (arr[i] > max)
			max = arr[i];
		i++;
	}
	free(arr);
	return (max);
}

int	longest_increasing_subsequence(int arr[], int n)
{
	int	*lis;
	int	i;
	int	j;

	lis = (int *)malloc(sizeof(int) * n);
	i = 1;
	lis[0] = 1;
	while (i < n)
	{
		lis[i] = 1;
		j = 0;
		while (j < i)
		{
			if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
			{
				lis[i] = lis[j] + 1;
			}
			j++;
		}
		i++;
	}
	return (find_max_element(lis, n));
}

void	estimate_optimal_chunks(t_Stack *a)
{
	int	lis_length;
	int	threshold;

	lis_length = longest_increasing_subsequence(a->nbr, a->top);
	threshold = 0.2 * a->top;
	if (lis_length > threshold && a->top <= 99)
	{
		a->no_chunks = 4;
		a->ind = 1;
	}
	else if (lis_length <= threshold && a->top <= 99)
	{
		a->no_chunks = 5;
		a->ind = 1;
	}
	else if (lis_length > threshold && a->top > 99)
	{
		a->no_chunks = 10;
		a->ind = 1;
	}
	else if (lis_length <= threshold && a->top > 99)
	{
		a->no_chunks = 12;
		a->ind = 1;
	}
}

void	set_chunks(t_Stack *a)
{
	if (a->top <= 99)
	{
		a->no_chunks = 4;
		a->ind = 1;
	}
	if (a->top > 99)
	{
		a->ind = 0;
		a->no_chunks = 10;
	}
}
