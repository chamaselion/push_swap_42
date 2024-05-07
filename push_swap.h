
#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 100

typedef struct {
    int top;
    int nbr[MAX_SIZE];
    int current_smallest;
    int current_biggest;
    int full_len;
    int full_move_count;
    int* ar;
    int current_mid1;
    int current_mid2;
    int current_mid3;
    int current_mid4;
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
void smart_rotate(Stack* a, Stack* b, int c);
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
void find_value_a(Stack* a, Stack* b);
void push_swap_beta(void);
void smart_rotate_b(Stack* b, int c);

#endif