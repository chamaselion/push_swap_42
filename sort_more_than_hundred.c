#include "push_swap.h"

int check_phase_mhundred(Stack* a, int cc)
{
    if(cc <= 1)
        return(a->current_mid1);
    if(cc <= 2)
        return(a->current_mid2);
    if(cc <= 3)
        return(a->current_mid3);
    if(cc <= 4)
        return(a->current_mid4);
    if(cc <= 5)
        return(a->current_mid5);
    if(cc <= 6)
        return(a->current_mid6);
    if(cc <= 7)
        return(a->current_mid7);
    if(cc <= 8)
	{
        return(a->current_mid8);
	}
	return (0);
}

void find_key_array_mhundred(Stack* a)
{
    int chunk_size;
     
    chunk_size = (a->top + 1) / 8;

    a->current_mid1 = a->ar[chunk_size];
    a->current_mid2 = a->ar[chunk_size * 2];
    a->current_mid3 = a->ar[chunk_size * 3];
    a->current_mid4 = a->ar[chunk_size * 4];
    a->current_mid5 = a->ar[chunk_size * 5];
    a->current_mid6 = a->ar[chunk_size * 6];
    a->current_mid7 = a->ar[chunk_size * 7];
    a->current_mid8 = a->ar[a->top];

}

void do_mhundred(Stack* a, Stack* b)
{
    int c;
    int cc;
    int i;
    int key_storage;
    int l;

    cc = 1;
    l = a->top + 1;
find_key_array_mhundred(a);
while (cc <= 8)
{
    i = 0;
    key_storage = check_phase_mhundred(a, cc);
    while(i <= (l / 8) && a->top != -1)
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
