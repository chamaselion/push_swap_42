#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX_SIZE 100

typedef struct {
    int top;
    int nbr[MAX_SIZE];
    int current_a_smallest;
    int current_a_biggest;
    int full_len;
    int full_move_count;
    int* ar;
    int current_mid1;
    int current_mid2;
    int current_mid3;
    int current_mid4;
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

void sa(Stack *a)
{
    if (a->top >= 1)
    {
        int temp = a->nbr[a->top];
        a->nbr[a->top] = a->nbr[a->top - 1];
        a->nbr[a->top - 1] = temp;
    }
}

void sb(Stack *b)
{
    if (b->top >= 1)
    {
        int temp = b->nbr[b->top];
        b->nbr[b->top] = b->nbr[b->top - 1];
        b->nbr[b->top - 1] = temp;
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

int check_phase(Stack* a, int cc)
{
    if(cc <= (a->top / 4))
        return(a->current_mid1);
    if(cc <= (a->top / 4) * 2)
        return(a->current_mid2);
    if(cc <= (a->top / 4) * 3)
        return(a->current_mid3);
    if(cc <= (a->top))
        return(a->current_mid4);
}

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

int count_len(Stack* a)
{
    return a->top + 1;
}

int count_len_b(Stack* b)
{
    return b->top + 1;
}

void mini_sort(Stack *a)
{
    if (a->nbr[a->top] > a->nbr[a->top - 1])
    {
        sa(a);
    }
    if (a->nbr[a->top] > a->nbr[a->top - 2])
    {
        rra(a);
        sa(a);
    }
    else if (a->nbr[a->top - 1] > a->nbr[a->top - 2])
    {
        rra(a);
    }
}

void fill_stack_a(Stack* a)
{
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

int is_sorted(Stack *a)
{
    int i = a->top;
    while (i > 0)
    {
        if (a->nbr[i] < a->nbr[i - 1])
        {
            return 0; // return 0 (false) if a pair of elements is out of order
        }
        i--;
    }
    return 1; // return 1 (true) if all elements are in order
}

void find_key_array(Stack* a)
{
    int chunk_size;
    int chunk1_start;
    int chunk2_start;
    int chunk3_start;
    int chunk4_start;

    if(a->top < 4)
        return ;

    chunk_size = a->top / 4;
    chunk1_start = 0;
    chunk2_start = chunk_size;
    chunk3_start = chunk_size * 2;
    chunk4_start  = a->top;

    a->current_mid1 = a->ar[chunk1_start];
    a->current_mid2 = a->ar[chunk2_start];
    a->current_mid3 = a->ar[chunk3_start];
    a->current_mid4 = a->ar[chunk4_start];
}
void find_value_a(Stack* a, Stack* b)
{
    int c;
    int cc;
    int fm;
    int i;
    int key_storage;
    int l;

    cc = 0;
    l = a->top - 2;
 printf("I work %s", "what s work");
find_key_array(a);
            printf("I work %s", "or not");
while (cc != l)
{
    i = 0;
            printf("I work %s", "in the future");
    key_storage = check_phase(a, cc);
    while(i != (a->top / 4))
    {
                printf("I work %s", "or at least try");
        c = 0;
        while (c <= a->top && a->nbr[a->top - c] > key_storage)
        {
            c++;
        }
        printf("I work %s", "correctly");
        smart_rotate(a, b, c);
        pb(a, b);
        i++;
        cc++;

    }
  
}
}

void push_swap_beta(void)
{
    Stack a = {MAX_SIZE - 1, {}, 1, 10, MAX_SIZE};
    Stack b = {-1, {}, 0, 0, 0};

    fill_stack_a(&a);
    print_stack(&a, "Stack a:\n");
    print_stack(&b, "Stack b:\n");

    find_value_a(&a, &b);

    print_stack(&a, "Stack a:\n");
    print_stack(&b, "Stack b:\n");
}

int main(void)
{
    push_swap_beta();


}