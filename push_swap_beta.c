#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX_SIZE 100

typedef struct {
    int top;
    int nbr[MAX_SIZE];
    int current_a_smallest;
    int current_a_biggest;
    int current_middle;
    int full_len;
    int full_move_count;
    int* ar;
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

int* stack_to_array(Stack* a)
{
    int* array = malloc(sizeof(int) * (a->top + 1));
    int i = 0;
    while (i <= a->top)
    {
        array[i] = a->nbr[i];
        i++;
    }
    return array;
}

void sort_array(int* array, int size)
{
    int i = 0;
    while (i < size - 1)
    {
        int j = 0;
        while (j < size - i - 1)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}

void print_array(int* array, int size)
{
    int i = 0;
    printf("[");
    while (i < size)
    {
        printf("%d", array[i]);
        if (i < size - 1)
        {
            printf(", ");
        }
        i++;
    }
    printf("]\n");
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

void fill_stack_a(Stack* a) {
    // Initialize random number generator
    srand(time(NULL));

    // Reset the top of the stack
    a->top = MAX_SIZE - 1;

    // Fill the stack with random numbers
    for (int i = 0; i < MAX_SIZE; i++) {
        int random_num = rand(); // Generate a random number
        a->nbr[i] = random_num; // Add it to the stack
    }

    // Reset the current smallest and biggest values
    a->current_a_smallest = a->nbr[0];
    a->current_a_biggest = a->nbr[0];

    // Find the actual smallest and biggest values
    for (int i = 1; i < MAX_SIZE; i++) {
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
    //int fm;
    Stack a = {MAX_SIZE - 1, {}, 1, 10, MAX_SIZE};
    Stack b = {-1, {}, 0, 0, 0};

    fill_stack_a(&a);

    a.ar = stack_to_array(&a);
    sort_array(a.ar, a.top + 1);



   /*handle_a(&a, &b);
    sort_b(&b);
    while (b.nbr[b.top] != -1)
    {
        pa(&a, &b);
    }
    
    fm = a.full_move_count + b.full_move_count;
    printf("Full move count: %i\n", fm);
    print_stack(&a, "Final a:");
    print_stack(&b, "Final b:");
    */
}

int main(void)
{
    push_swap_beta();


}