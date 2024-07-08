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

void mini_sort_3(Stack* a)
{
    if (a->nbr[1] > a->nbr[2] && a->nbr[2] > a->nbr[0])
    {
        // {0 2 1} : sa rra
        sa(a);
        rra(a);
    }
    else if (a->nbr[1] > a->nbr[0] && a->nbr[0] > a->nbr[2])
    {
        // {1 0 2} : sa
        sa(a);
    }
    else if (a->nbr[2] > a->nbr[0] && a->nbr[0] > a->nbr[1])
    {
        // {2 1 0} : ra
        ra(a);
    }
    else if (a->nbr[2] > a->nbr[1] && a->nbr[1] > a->nbr[0])
    {
        // {2 0 1} : rra
        rra(a);
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

void	handle_remaining_stack(Stack* a, Stack *b)
{
	int	c;

	while (a->top != 0)
	{
		c = 0;
		a->current_smallest = find_smallest(a);
		while (a->nbr[a->top - c] != a->current_smallest)
		{
			c++;
		}
		smart_rotate(a, c);
		pb(a, b);
	}
	//mini_sort_3(a);
}

void push_swap(Stack* a, Stack* b)
{

    a->ar = stack_to_array(a);

    sort_array(a->ar, a->top + 1);

	do_hundred(a, b);
	handle_remaining_stack(a, b);
    sort_b_to_a(a, b);

    free(a->ar);
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

int find_max_element(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

int longest_increasing_subsequence(int arr[], int n)
{
    int lis[n];
    lis[0] = 1;

    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
    }

    return find_max_element(lis, n);
}

void estimate_optimal_chunks(Stack *a)
{
    // Estimate the sortedness of the data
    int lis_length = longest_increasing_subsequence(a->nbr, a->top);
    int threshold = 0.2 * a->top;

    if (lis_length > threshold && a->top <= 99)
    {
        a->no_chunks = 5;
        a->ind = 1;
    }
    else if (lis_length <= threshold && a->top <= 99)
    {
        a->no_chunks = 4;
        a->ind = 1;
    }
    else if (lis_length > threshold && a->top > 99)
    {
        a->no_chunks = 10;
        a->ind = 0;
    }
    else if (lis_length <= threshold && a->top > 99)
    {
        a->no_chunks = 10;
        a->ind = 0;
    }
}

void	set_chunks(Stack* a)
{
	if (a->top <= 99)
	{
		a->no_chunks = 4;
		a->ind = 1;
	}
	if (a->top > 99)
	{
		a->ind = 0;
		a->no_chunks = 10;
	}
}

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        return 0; // Exit the program if no arguments were provided
    }
Stack a = {argc - 2, malloc((argc - 1) * sizeof(int)), -1, -1, argc - 1, 0, malloc((argc - 1) * sizeof(int)), malloc((argc - 1) * sizeof(int)), 1, 0};
Stack b = {-1, malloc((argc - 1) * sizeof(int)), -1, -1, 0, 0, malloc((argc - 1) * sizeof(int)), malloc((argc - 1) * sizeof(int)), 0, 0};

    check_pre_stack(argc, argv);
    fill_stack(&a, argc, argv);
	estimate_optimal_chunks(&a);
    push_swap(&a, &b);
}
