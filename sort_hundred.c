#include "push_swap.h"
int check_phase_hundred(Stack* a, int cc)
{
    if (cc <= a->no_chunks)
        return a->current_mid[cc - 1];
    return 0;
}

void find_key_array(Stack* a)
{
    int chunk_size = (a->top + 1) / a->no_chunks;

	int	i;

	i = 0;

    while (i < a->no_chunks)
    {
        a->current_mid[i] = a->ar[chunk_size * (i + 1)];
		i++;
    }

}

void do_hundred(Stack* a, Stack* b)
{
    int c;
    int cc;
    int i;
    int key_storage;
    int l;

    cc = 1;
    l = a->top + 1;
find_key_array(a);
while (cc <= a->no_chunks)
{
    i = 0;
    key_storage = check_phase_hundred(a, cc);
    while(i <= (l / a->no_chunks) && a->top != -1)
    {
        c = 0;
        a->full_len = a->top + 1;
        printf("Key:%i:%i\n", cc, key_storage);
        while (a->nbr[a->top - c] > key_storage && c != a->top - 1)
        {
            c++;
        }
        printf("nbr: %i\natop:%i\nc%i\n", a->nbr[a->top - c], a->top, c);
        smart_rotate(a, c);
        pb(a, b);
        i++;
    }
cc++;
}
}

void  sort_b_to_a (Stack* a, Stack* b)
{
    int c;
    while (b->top != -1)
    {    
        find_biggest_b(b);
        b->full_len = b->top + 1;
        c = 0;
        while (b->nbr[b->top - c] < b->current_biggest && c != b->top)
        {
            c++;
        }
        printf("found nbr: %i\n", b->nbr[b->top - c]);
        smart_rotate_b(b, c);
        printf("Current biggest:%i\nProcessed nbr: %i\n", b->current_biggest, b->nbr[b->top]);
        pa(a, b);
    }

}
