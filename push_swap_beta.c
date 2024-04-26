#include <stdio.h>

#define MAX_SIZE 10

typedef struct {
    int top;
    int nbr[MAX_SIZE];
    int current_a_smallest;
    int current_a_biggest;
    int full_len;
    int full_move_count;
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

int find_smallest_b(Stack* b)
{
    int smallest = b->nbr[0];
    for (int i = 1; i <= b->top; i++)
    {
        if (b->nbr[i] < smallest)
        {
            smallest = b->nbr[i];
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
    int fm;

    while(a->top != -1)
    {
        a->current_a_smallest = find_smallest(a);
        a->current_a_biggest = find_biggest(a);
        a->full_len = count_len(a);
        c = 0;
        while (a->nbr[a->top - c] != a->current_a_biggest && a->nbr[a->top - c] != a->current_a_smallest)
        {
            c++;
        }
        
        handle_a_to_be(a, b, c);

        fm = a->full_move_count + b->full_move_count;
        printf("\n");
        print_stack(a, "Stack A at end");
        print_stack(b, "Stack B at end");
        printf("\n");
       // printf("Counter %i\n", c);
       // printf("Full move count: %i\n", fm);
       // printf("smallest %i\n", a->current_a_smallest);
       // printf("bigest %i\n", a->current_a_biggest);
        printf("\n");
    }
  
}

void    handle_a_to_be(Stack* a, Stack* b, int c)
{
    int move_count;

    move_count = 0;

    if (a->nbr[a->top - c] == a->current_a_smallest || a->nbr[a->top - c] == a->current_a_biggest)
    {
        if(c > (a->full_len / 2))
        {
            while (move_count < (c))
            {
                rra(a);
                move_count++;
            }
            move_count = 0;
        }
        if (c < (a->full_len / 2) )
        {
            while (move_count < (c))
            {
                ra(a);
                move_count++;
            }
        }
        else
                ra(a);
    }
    print_stack(a, "Stack A in progress");
    print_stack(b, "Stack B in progress");
    printf("\n");
    let_it_be(a, b);

}

void    let_it_be(Stack* a, Stack* b)
{
    int c;

    c = 0;
if (a->nbr[a->top] == a->current_a_smallest || a->nbr[a->top] == a->current_a_biggest )
{
    if (a->nbr[a->top] == a->current_a_biggest)
    {
        pb(a, b);
    }
    if (a->nbr[a->top] == a->current_a_smallest)
    {
        pb(a, b);
        rb(b);
    }
       else if (a->top == 0)
    {
        pb(a, b);
    }
}
return ;
}

void    sort_b(Stack* b)
{
    int final_smoll;

    final_smoll = find_smallest_b(b);
    while(b->nbr[b->top] != final_smoll)
    {
        rb(b);
    }
    print_stack(b, "Final b:");
}

#include <stdlib.h>
#include <time.h>

void fill_stack_a(Stack* a) {
    // Initialize random number generator
    srand(time(NULL));

    // Generate a random number of elements
    int num_elements = rand() % MAX_SIZE + 1; // Between 1 and MAX_SIZE

    // Reset the top of the stack
    a->top = num_elements - 1;

    // Fill the stack with random numbers
    for (int i = 0; i < num_elements; i++) {
        int random_num = rand(); // Generate a random number
        a->nbr[i] = random_num; // Add it to the stack
    }

    // Reset the current smallest and biggest values
    a->current_a_smallest = a->nbr[0];
    a->current_a_biggest = a->nbr[0];

    // Find the actual smallest and biggest values
    for (int i = 1; i < num_elements; i++) {
        if (a->nbr[i] < a->current_a_smallest) {
            a->current_a_smallest = a->nbr[i];
        }
        if (a->nbr[i] > a->current_a_biggest) {
            a->current_a_biggest = a->nbr[i];
        }
    }
}

void push_swap_beta(void)
{
    int fm;
    Stack a = {MAX_SIZE - 1, {}, 1, 10, MAX_SIZE};
    Stack b = {-1, {}, 0, 0, 0};

    fill_stack_a(&a);

    handle_a(&a, &b);
    sort_b(&b);
    fm = a.full_move_count + b.full_move_count;
    printf("Full move count: %i\n", fm);
}

int main(void)
{
    push_swap_beta();


}