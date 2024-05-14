
#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef struct {
    int top;
    int *nbr;
    int current_smallest;
    int current_biggest;
    int full_len;
    int full_move_count;
    int* ar;
    int current_mid1;
    int current_mid2;
    int current_mid3;
    int current_mid4;
    int current_mid5;
    int current_mid6;
    int current_mid7;
    int current_mid8;
} Stack;


void sa(Stack *a);
void sb(Stack *b);
void ra(Stack* a);
void rb(Stack* b);
void pb(Stack* a, Stack* b);
void pa(Stack* a, Stack* b);
void rra(Stack* a);
void rrb(Stack* b);
void print_array(int* array, int size);
int* stack_to_array(Stack* a);
int check_phase(Stack* a, int cc);
void smart_rotate(Stack* a, int c);
void  nsmart_reverse_rotate(Stack* b, int c);
void sort_array(int* array, int size);
void print_stack(Stack* a, char* name);
int find_smallest(Stack* a);
int find_smallest_b(Stack* b);
int find_biggest(Stack* a);
void find_biggest_b(Stack* b);
int count_len(Stack* a);
int count_len_b(Stack* b);
void mini_sort(Stack *a);
void fill_stack_a(Stack* a);
int is_sorted(Stack *a);
void find_key_array(Stack* a);
void push_swap(Stack* a, Stack* b);
void smart_rotate_b(Stack* b, int c);
void find_key_array(Stack* a);
void find_value_a(Stack* a, Stack* b);
void  sort_b_to_a (Stack* a, Stack* b);
void do_mhundred(Stack* a, Stack* b);
void find_key_array_mhundred(Stack* a);
int check_phase_mhundred(Stack* a, int cc);
void do_hundred(Stack* a, Stack* b);
void put_sort(Stack* a, Stack* b);
void put_sort_a_to_be(Stack* a, Stack* b, int c);
void    let_it_be(Stack* a, Stack* b);

#endif