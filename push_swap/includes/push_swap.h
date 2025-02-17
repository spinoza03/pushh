#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_stack
{
    int             value;
    struct s_stack  *next;
} t_stack;

// Parsing and stack utilities
int     parse_args(int argc, char **argv, t_stack **stack_a);
int     is_valid_integer(char *str);
int     has_duplicates(t_stack *stack);
t_stack	*stack_new_node(int value);
void    add_node(t_stack **stack, int value);
void    free_stack(t_stack **stack);
void	stack_clear(t_stack **stack);
void	stack_add_back(t_stack **stack, t_stack *new_node);
int	    process_numbers(char *str, t_stack **stack_a);
int	    check_num(char *str);
int	    check_arr(char **arr);
int     valid_stack(t_stack *stack);
int stack_size(t_stack *stack);
void	free_array(char **arr);

// Stack operations
void    sa(t_stack **stack_a, int print);
void    sb(t_stack **stack_b, int print);
void    ss(t_stack **stack_a, t_stack **stack_b, int print);
void    pa(t_stack **stack_a, t_stack **stack_b, int print);
void    pb(t_stack **stack_a, t_stack **stack_b, int print);
void    ra(t_stack **stack_a, int print);
void    rb(t_stack **stack_b, int print);
void    rr(t_stack **stack_a, t_stack **stack_b, int print);
void    rra(t_stack **stack_a, int print);
void    rrb(t_stack **stack_b, int print);
void    rrr(t_stack **stack_a, t_stack **stack_b, int print);

// Sorting algorithms
int     is_sorted(t_stack *stack);
void    sort_three(t_stack **stack_a);
void    sort_five(t_stack **stack_a, t_stack **stack_b);
void    radix_sort(t_stack **stack_a, t_stack **stack_b);

#endif