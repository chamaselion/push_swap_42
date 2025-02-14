/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error_stuff3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 14:58:11 by bszikora          #+#    #+#             */
/*   Updated: 2024/08/06 15:00:21 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_call(t_Stack *a, t_Stack *b)
{
	write_error("Error\n");
	cleanup(a, b);
	exit(EXIT_FAILURE);
}
