#include "../includes/push_swap.h"

void sa(t_stack **stack_a, int print)
{
    if (!stack_a || !*stack_a || !(*stack_a)->next)
        return;

    t_stack *first = *stack_a;
    t_stack *second = first->next;

    first->next = second->next;
    second->next = first;
    *stack_a = second;

    if (print)
        write(1, "sa\n", 3);
}

// Swap the first two elements of Stack B
void sb(t_stack **stack_b, int print)
{
    if (!stack_b || !*stack_b || !(*stack_b)->next)
        return;

    t_stack *first = *stack_b;
    t_stack *second = first->next;

    first->next = second->next;
    second->next = first;
    *stack_b = second;

    if (print)
        write(1, "sb\n", 3);
}

// Swap both Stack A and Stack B
void ss(t_stack **stack_a, t_stack **stack_b, int print)
{
    sa(stack_a, 0);
    sb(stack_b, 0);

    if (print)
        write(1, "ss\n", 3);
}
