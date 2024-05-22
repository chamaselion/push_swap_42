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


void push_swap(Stack* a, Stack* b)
{
    int fm;
	//int	wtf;

    print_stack(a, "Stack a:\n");
    print_stack(b, "Stack b:\n");

    a->ar = stack_to_array(a);
    print_array(a->ar, a->top + 1);

    sort_array(a->ar, a->top + 1);
    print_array(a->ar, a->top + 1);
	do_hundred(a, b);
    print_stack(a, "Stack a:\n");
    print_stack(b, "Stack b:\n");

    sort_b_to_a(a, b);

    print_stack(a, "Stack a:\n");
    print_stack(b, "Stack b:\n");

    fm = a->full_move_count + b->full_move_count;
    int issort = is_sorted(a);
    free(a->ar);
    printf("Moves:%i\nSort: %i\nChunks:%i\n", fm, issort, a->no_chunks);
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
Stack a = {argc - 2, malloc((argc - 1) * sizeof(int)), -1, -1, argc - 1, 0, malloc((argc - 1) * sizeof(int)), malloc((argc - 1) * sizeof(int)), 1};
Stack b = {-1, malloc((argc - 1) * sizeof(int)), -1, -1, 0, 0, malloc((argc - 1) * sizeof(int)), malloc((argc - 1) * sizeof(int)), 0};

    check_pre_stack(argc, argv);
    fill_stack(&a, argc, argv);
	a.no_chunks = 10;
    push_swap(&a, &b);
}
