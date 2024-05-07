void find_key_array(Stack* a)
{
    int chunk_size;
    int chunk1_end;
    int chunk2_end;
    int chunk3_end;
    int chunk4_end;
     
    chunk_size = (a->top + 1) / 4;
    chunk1_end = chunk_size;
    chunk2_end = chunk_size * 2;
    chunk3_end = chunk_size * 3;
    chunk4_end  = a->top;
    a->current_mid1 = a->ar[chunk1_end];
    a->current_mid2 = a->ar[chunk2_end];
    a->current_mid3 = a->ar[chunk3_end];
    a->current_mid4 = a->ar[chunk4_end];

}

void find_value_a(Stack* a, Stack* b)
{
    int c;
    int cc;
    int i;
    int key_storage;
    int l;

    cc = 1;
    l = a->top + 1;
find_key_array(a);
while (cc <= 4)
{
    i = 0;
    key_storage = check_phase(a, cc);
    while(i <= (l / 4) && a->top != -1)
    {
        c = 0;
        a->full_len = a->top + 1;
        printf("Key:%i:%i\n", cc, key_storage);
        while (a->nbr[a->top - c] > key_storage && c != a->top - 1)
        {
            c++;
        }
        printf("nbr: %i\natop:%i\nc%i\n", a->nbr[a->top - c], a->top, c);
        smart_rotate(a, b, c);
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
