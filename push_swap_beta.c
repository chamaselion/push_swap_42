#include "push_swap.h"

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
    printf("%d\n", 1);
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
    printf("%i, %i, %i, %i\n", chunk1_start, chunk2_start, chunk3_start, chunk4_start);
    a->current_mid1 = a->ar[chunk1_start];
    a->current_mid2 = a->ar[chunk2_start];
    a->current_mid3 = a->ar[chunk3_start];
    a->current_mid4 = a->ar[chunk4_start];
    printf("%i, %i, %i, %i", a->current_mid1, a->current_mid2, a->current_mid3, a->current_mid4);
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
    stack_to_array(&a);
      printf("PLS %s\n", "work");
      print_array(a.ar, a.top - 1);
   
    sort_array(a.ar, a.top - 1);
   
      print_array(a.ar, a.top - 1);

    find_value_a(&a, &b);

    print_stack(&a, "Stack a:\n");
    print_stack(&b, "Stack b:\n");
}

int main(void)
{
    push_swap_beta();


}