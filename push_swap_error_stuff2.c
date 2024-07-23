/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error_stuff2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:30:36 by bszikora          #+#    #+#             */
/*   Updated: 2024/07/17 15:37:07 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <ctype.h>
#include <stdlib.h>

int getNextInt(char *str, char **nextPos) {
    if (str == NULL || *str == '\0') {
        *nextPos = str;
        return 0;
    }
    while (*str && !isdigit(*str) && *str != '-' && *str != '+') {
        str++;
    }

    if (*str == '\0') {
        *nextPos = str;
        return 0;
    }
    char *end;
    int num = (int)strtol(str, &end, 10);
    *nextPos = end;

    return num;
}

int	is_it_duplicate_tho(int *array, int limit)
{
    int i;
    int j;

	i = 0;

    while (i < limit - 1)
	{
        j = i + 1;
        while (j < limit)
		{
            if (array[i] == array[j])
			{
                return 1;
            }
            j++;
        }
        i++;
    }
    return 0;
}

void check_pre_stack_single(char *argv)
{
	int c;

	c = 0;
	printf("The string:%s\n", argv);
	if (argv[0] == '\0')
	{
		write_error("Error\n");
		exit(EXIT_FAILURE);
	}
	while (argv[c] != '\0')
	{   
		if (!((argv[c] >= '0' && argv[c] <= '9') || argv[c] == ' ' || argv[c] == '\t'))
		{
			write_error("Error\n");
			exit(EXIT_FAILURE);
		}
		c++;
	}
}

