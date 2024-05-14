#include "push_swap.h"

void fill_stack(Stack *a, int argc, char **argv)
{
  
    int i = argc - 1;
    while (i >= 1)
    {
        a->nbr[argc - i - 1] = atoi(argv[i]);
        i--;
    }
     a->top = argc - 2;
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

void mini_sort_3(Stack *a)
{   
    if (a->nbr[a->top] > a->nbr[a->top - 1] && a->nbr[a->top - 2] > a->nbr[a->top - 1])
    {
        sa(a);
    }

    if (a->nbr[a->top] > a->nbr[a->top - 1] && a->nbr[a->top - 1] > a->nbr[a->top - 2])
    {
        sa(a);
        rra(a);
    }
    if (a->nbr[a->top] > a->nbr[a->top - 1] && a->nbr[a->top] > a->nbr[a->top - 2])
    {
        ra(a);
    }

    if (a->nbr[a->top] < a->nbr[a->top - 1] && a->nbr[a->top - 1] < a->nbr[a->top - 2])
    {
        sa(a);
        ra(a);
    }
        if (a->nbr[a->top] < a->nbr[a->top - 1] && a->nbr[a->top] > a->nbr[a->top - 2])
    {
        ra(a);
    }
    
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

void constfil_a(Stack* a)
{
    int numbers[100] = {34, 67, 55, 33, 12, 98, 99, 16, 11, 8, 20, 14, 45, 82, 22, 89, 15, 78, 96, 25, 66, 51, 79, 81, 58, 3, 46, 85, 69, 64, 87, 68, 90, 83, 57, 71, 60, 39, 73, 61, 2, 36, 59, 9, 6, 7, 49, 35, 38, 13, 28, 70, 1, 44, 53, 76, 47, 17, 88, 50, 4, 18, 23, 65, 80, 56, 29, 74, 21, 19, 5, 92, 31, 10, 54, 26, 86, 32, 62, 84, 41, 97, 30, 72, 27, 95, 40, 75, 42, 77, 94, 93, 91, 24, 48, 37, 52, 43, 63, 100};
    for (int i = 0; i < 100; i++) {
        a->nbr[i] = numbers[i];
    }
}
/*
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
*/
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

void push_swap(Stack* a, Stack* b)
{
    int fm;

    print_stack(a, "Stack a:\n");
    print_stack(b, "Stack b:\n");

    a->ar = stack_to_array(a);
    print_array(a->ar, a->top + 1);

    sort_array(a->ar, a->top + 1);
    print_array(a->ar, a->top + 1);
	if (is_sorted(a) == 1)
	{
		return ;
	}
	
    if (a->top + 1 <= 3)
	{
    mini_sort_3(a);
	}
	if (a->top + 1 <= 10)
	{
      mini_sort(a);
    }
	else if (a->top + 1 <= 100)
	{
        do_hundred(a, b);
    }
	else
	{
        do_mhundred(a, b);
    }

    print_stack(a, "Stack a:\n");
    print_stack(b, "Stack b:\n");

    sort_b_to_a(a, b);

    print_stack(a, "Stack a:\n");
    print_stack(b, "Stack b:\n");

    fm = a->full_move_count + b->full_move_count;
    int issort = is_sorted(a);
    free(a->ar);
    printf("Moves:%i\nSort: %i", fm, issort);
}

void write_error(char *str) {
    while (*str) {
        write(2, str, 1);
        str++;
    }
}

int is_digit(char c) {
    return c >= '0' && c <= '9';
}

int is_integer(char *str) {
    if (*str == '-' || *str == '+') {
        str++;
    }

    if (!*str) {
        return 0;
    }

    while (*str) {
        if (!is_digit(*str)) {
            return 0;
        }
        str++;
    }

    return 1;
}
void check_pre_stack(int argc, char **argv) {
    int *check_array = malloc((argc - 1) * sizeof(int));
    int i = 1;

    while (i < argc) {
        if (!is_integer(argv[i])) {
            write_error("Error\n");
            exit(EXIT_FAILURE);
        }

        int val = atoi(argv[i]);
        int j = 0;
        while (j < i - 1) {
            if (check_array[j] == val) {
                write_error("Error\n");
                exit(EXIT_FAILURE);
            }
            j++;
        }

        check_array[i - 1] = val;
        i++;
    }

    free(check_array);
}

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        return 0; // Exit the program if no arguments were provided
    }
    Stack a = {argc - 2, malloc((argc - 1) * sizeof(int)), -1, -1, argc - 1, 1, malloc((argc - 1) * sizeof(int)), -1, -1, -1, -1, -1, -1, -1, -1};
    Stack b = {-1, malloc((argc - 1) * sizeof(int)), -1, -1, 0, 0, malloc((argc - 1) * sizeof(int)), -1, -1, -1, -1, -1, -1, -1, -1};

    check_pre_stack(argc, argv);
    fill_stack(&a, argc, argv);
    push_swap(&a, &b);
}