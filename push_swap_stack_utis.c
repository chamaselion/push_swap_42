#include "push_swap.h"

void smart_rotate(Stack* a, Stack* b, int c)
{
    int move_count;

    move_count = 0;

        if(c >= (a->full_len / 2))
        {
            while (move_count < c)
            {
                rra(a);
                move_count++;
            }
            move_count = 0;
        }
        if (c < (a->full_len / 2) )
        {
            while (move_count < c)
            {
                ra(a);
                move_count++;
            }
    }
}

void print_stack(Stack* a, char* name)
{
    printf("%s: ", name);
    for (int i = a->top; i >= 0; i--)
    {
        printf("%d ", a->nbr[i]);
    }
    printf("\n");
}

int find_smallest(Stack* a)
{
    int smallest = a->nbr[0];
    int i;

    i = 1;
    while (i <= a->top)
    {
        if (a->nbr[i] < smallest)
        {
            smallest = a->nbr[i];
        }
        i++;
    }
    return smallest;
}

int find_smallest_b(Stack* b)
{
    int smallest = b->nbr[0];
    int i;

    i = 1;
    while (i <= b->top)
    {
        if (b->nbr[i] < smallest)
        {
            smallest = b->nbr[i];
        }
    i++;
    }
    return smallest;
}

int find_biggest(Stack* a)
{
    int biggest = a->nbr[0];
    int i;

    i = 1;
    while (i <= a->top)
    {
        if (a->nbr[i] > biggest)
        {
            biggest = a->nbr[i];
        }
        i++;
    }
    return biggest;
}