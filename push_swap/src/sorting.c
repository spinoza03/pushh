#include "../includes/push_swap.h"

// Check if the stack is sorted
int is_sorted(t_stack *stack)
{
    while (stack && stack->next)
    {
        if (stack->value > stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}

// Sort a stack of 3 elements
void sort_three(t_stack **stack_a)
{
    int a = (*stack_a)->value;
    int b = (*stack_a)->next->value;
    int c = (*stack_a)->next->next->value;

    if (a > b && b < c && a < c)
        sa(stack_a, 1); // Case: 2 1 3 → 1 2 3
    else if (a > b && b > c)
    {
        sa(stack_a, 1); // Case: 3 2 1 → 2 3 1
        rra(stack_a, 1); // → 1 2 3
    }
    else if (a > b && b < c && a > c)
        ra(stack_a, 1); // Case: 3 1 2 → 1 2 3
    else if (a < b && b > c && a < c)
    {
        sa(stack_a, 1); // Case: 1 3 2 → 3 1 2
        ra(stack_a, 1); // → 1 2 3
    }
    else if (a < b && b > c && a > c)
        rra(stack_a, 1); // Case: 2 3 1 → 1 2 3
}

// Sort a stack of 5 elements
void sort_five(t_stack **stack_a, t_stack **stack_b)
{
    while (stack_size(*stack_a) > 3)
    {
        if ((*stack_a)->value == find_min(*stack_a))
            pb(stack_a, stack_b, 1);
        else
            ra(stack_a, 1);
    }
    sort_three(stack_a);
    while (*stack_b)
        pa(stack_a, stack_b, 1);
}

// Radix sort for large stacks
void radix_sort(t_stack **stack_a, t_stack **stack_b)
{
    int max_bits = get_max_bits(*stack_a);

    for (int i = 0; i < max_bits; i++)
    {
        int size = stack_size(*stack_a);
        for (int j = 0; j < size; j++)
        {
            if (((*stack_a)->value >> i) & 1)
                ra(stack_a, 1);
            else
                pb(stack_a, stack_b, 1);
        }
        while (*stack_b)
            pa(stack_a, stack_b, 1);
    }
}