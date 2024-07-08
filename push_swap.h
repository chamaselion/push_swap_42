
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
    int* current_mid;
	int no_chunks;
	int	ind;
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
void let_it_be(Stack* a, Stack* b);
int check_phase_hundred_p(Stack* phantom_a, int cc);
void do_hundred_p(Stack* phantom_a, Stack* phantom_b);
void sort_b_to_a_p (Stack* phantom_a, Stack* phantom_b);
void find_key_array_p(Stack* phantom_a);
void sa_p(Stack *phantom_a);
void sb_p(Stack *phantom_b);
void ra_p(Stack* phantom_a);
void rra_p(Stack* phantom_a);
void rrb_p(Stack* phantom_b);
void pb_p(Stack* phantom_a, Stack* phantom_b);
void pa_p(Stack* phantom_a, Stack* phantom_b);
void rb_p(Stack* phantom_b);
int find_optimal_chunks(Stack* a, Stack* b);
void smart_rotate_b_p(Stack* phantom_b, int c);
void find_biggest_b_p(Stack* phantom_b);

#endif