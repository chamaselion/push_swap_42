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
    if(cc <= 1)
        return(a->current_mid1);
    if(cc <= 2)
        return(a->current_mid2);
    if(cc <= 3)
        return(a->current_mid3);
    if(cc <= 4)
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

void constfil_a(Stack* a)
{
    int numbers[100] = {34, 67, 55, 33, 12, 98, 99, 16, 11, 8, 20, 14, 45, 82, 22, 89, 15, 78, 96, 25, 66, 51, 79, 81, 58, 3, 46, 85, 69, 64, 87, 68, 90, 83, 57, 71, 60, 39, 73, 61, 2, 36, 59, 9, 6, 7, 49, 35, 38, 13, 28, 70, 1, 44, 53, 76, 47, 17, 88, 50, 4, 18, 23, 65, 80, 56, 29, 74, 21, 19, 5, 92, 31, 10, 54, 26, 86, 32, 62, 84, 41, 97, 30, 72, 27, 95, 40, 75, 42, 77, 94, 93, 91, 24, 48, 37, 52, 43, 63, 100};
    for (int i = 0; i < 100; i++) {
        a->nbr[i] = numbers[i];
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
    a->current_smallest = a->nbr[0];
    a->current_biggest = a->nbr[0];

    // Find the actual smallest and biggest values
    for (int i = 1; i < MAX_SIZE; i++) {
        if (a->nbr[i] < a->current_smallest) {
            a->current_smallest = a->nbr[i];
        }
        if (a->nbr[i] > a->current_biggest) {
            a->current_biggest = a->nbr[i];
        }
    }
}

int is_sorted(Stack *a)
{
    int i = a->top;
    while (i > 0)
    {
        if (a->nbr[i] > a->nbr[i - 1])
        {
            return 0; // return 0 (false) if a pair of elements is out of order
        }
        i--;
    }
    return 1; // return 1 (true) if all elements are in order
}

void bubble_sort_pass(Stack *a)
{
    int i = 0;
    while (i < a->top)
    {
        if (a->nbr[i] > a->nbr[i + 1])
        {
            sa(a);
        }
        ra(a);
        i++;
    }
}

void push_swap_beta(void)
{
    Stack a = {MAX_SIZE - 1, {}, 1, 10, MAX_SIZE};
    Stack b = {-1, {}, 0, 0, 0};
    int fm;

   fill_stack_a(&a);
   //constfil_a(&a);

          print_stack(&a, "Stack a:\n");
   
          print_stack(&b, "Stack b:\n");
   a.ar = stack_to_array(&a);
         print_array(a.ar, a.top + 1);
   
    sort_array(a.ar, a.top + 1);
          print_array(a.ar, a.top + 1);
    find_value_a(&a, &b);

        print_stack(&a, "Stack a:\n");
        print_stack(&b, "Stack b:\n");

    sort_b_to_a(&a, &b);

        print_stack(&a, "Stack a:\n");
        print_stack(&b, "Stack b:\n");
    fm = a.full_move_count + b.full_move_count;
    int issort = is_sorted(&a);
    printf("Moves:%i\nSort: %i", fm, issort);
}

int main(void)
{
    push_swap_beta();
}