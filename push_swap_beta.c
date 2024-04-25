#include <stdio.h>

#define MAX_SIZE 10

typedef struct {
    int top;
    int nbr[MAX_SIZE];
    int current_a_smallest;
    int current_a_biggest;
    int full_len;
} Stack;

void ra(Stack* a);
void pb(Stack* a, Stack* b);
void rrb(Stack* a);
void print_stack(Stack* a, char* name);
int find_smallest(Stack* a);
int find_biggest(Stack* a);
void handle_a_to_be(Stack* a, Stack* b, int c);
void let_it_be(Stack* a, Stack* b);
void handle_a(Stack* a, Stack* b);
void push_swap_beta(void);

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
}

void pb(Stack* a, Stack* b)
{
    if (a->top >= 0)
    {
        b->nbr[++b->top] = a->nbr[a->top--];
    }
    printf("PUSHED HERE\n");
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
    printf("rra\n");
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
    for (int i = 1; i <= a->top; i++)
    {
        if (a->nbr[i] < smallest)
        {
            smallest = a->nbr[i];
        }
    }
    return smallest;
}

int find_biggest(Stack* a)
{
    int biggest = a->nbr[0];
    for (int i = 1; i <= a->top; i++)
    {
        if (a->nbr[i] > biggest)
        {
            biggest = a->nbr[i];
        }
    }
    return biggest;
}

int count_len(Stack* a)
{
    return a->top + 1;
}

void handle_a(Stack* a, Stack* b)
{
    int c;

    c = 0;

    while(c <= a->top)
    {
        a->current_a_smallest = find_smallest(a);
        a->current_a_biggest = find_biggest(a);
        a->full_len = count_len(a);
        handle_a_to_be(a, b, c);
        c++;
        print_stack(a, "Stack A");
        print_stack(b, "Stack B");
        printf("Counter %i\n", c);
        printf("smallest %i\n", a->current_a_smallest);
        printf("bigest %i\n", a->current_a_biggest);
        printf("\n");
    }
}

void    handle_a_to_be(Stack* a, Stack* b, int c)
{
    int c_clone;
    int move_count;

    c_clone = c;
    move_count = 0;

    if (a->nbr[a->top - c_clone] == a->current_a_smallest || a->nbr[a->top - c_clone] == a->current_a_biggest)
    {
        if(c_clone > (a->full_len / 2))
        {
            while (move_count < (c_clone))
            {
                rra(a);
                move_count++;
            }
            move_count = 0;
        }
        if (c_clone < (a->full_len / 2) )
        {
            while (move_count < (c_clone))
            {
                ra(a);
                move_count++;
            }
            move_count = 0;
        }
        if(c_clone == (a->full_len / 2))
                ra(a);
    }
    printf("\n");
    let_it_be(a, b);
    return ;
}

void    let_it_be(Stack* a, Stack* b)
{
if (a->nbr[a->top] == a->current_a_smallest || a->nbr[a->top] == a->current_a_biggest )
{
    if (a->nbr[a->top] == a->current_a_biggest)
    {
        pb(a, b);
    }
    if (a->nbr[a->top] == a->current_a_smallest)
    {
        pb(a, b);
        rrb(b);
    }
}
return ;
}

void push_swap_beta(void)
{
    Stack a = {MAX_SIZE - 1, {12, 20, 13, 45, 31, 76, 1, 2, 99}, 1, 10, MAX_SIZE};
    Stack b = {-1, {}, 0, 0, 0};
    handle_a(&a, &b);
}

int main(void)
{
    push_swap_beta();

}