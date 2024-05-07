#include "push_swap.h"

void sa(Stack *a)
{
    if (a->top >= 1)
    {
        int temp = a->nbr[a->top];
        a->nbr[a->top] = a->nbr[a->top - 1];
        a->nbr[a->top - 1] = temp;
    }
    a->full_move_count++;
}

void sb(Stack *b)
{
    if (b->top >= 1)
    {
        int temp = b->nbr[b->top];
        b->nbr[b->top] = b->nbr[b->top - 1];
        b->nbr[b->top - 1] = temp;
    }
    b->full_move_count++;
}

void ra(Stack* a)
{
    if (a->top < 0)
    {
        return;
    }

    int temp = a->nbr[a->top];

    for (int i = a->top; i > 0; i--)
    {
        a->nbr[i] = a->nbr[i - 1];
    }

    a->nbr[0] = temp;
    printf("ra\n");
    a->full_move_count++;
}

void rb(Stack* b)
{
    if (b->top < 0)
    {
        return;
    }

    int temp = b->nbr[b->top];

    for (int i = b->top; i > 0; i--)
    {
        b->nbr[i] = b->nbr[i - 1];
    }

    b->nbr[0] = temp;
    printf("rb\n");
    b->full_move_count++;
}

void pb(Stack* a, Stack* b)
{
    if (a->top >= 0)
    {
        b->nbr[++b->top] = a->nbr[a->top--];
    }
    printf("PUSHED HERE\n");
    a->full_move_count++;
}

void pa(Stack* a, Stack* b)
{
    if (b->top >= 0)
    {
        a->nbr[++a->top] = b->nbr[b->top--];
    }
    printf("PUSHED HERE\n");
    a->full_move_count++;
}

void rra(Stack* a)
{
    if (a->top < 0)
    {
        return;
    }

    int temp = a->nbr[0];


    for (int i = 0; i < a->top; i++)
    {
        a->nbr[i] = a->nbr[i + 1];
    }

    a->nbr[a->top] = temp;
   // printf("rra\n");
    a->full_move_count++;
}

void rrb(Stack* b)
{
    if (b->top < 0)
    {
        return;
    }

    int temp = b->nbr[0];


    for (int i = 0; i < b->top; i++)
    {
        b->nbr[i] = b->nbr[i + 1];
    }

    b->nbr[b->top] = temp;
    printf("rrb\n");
    b->full_move_count++;
}