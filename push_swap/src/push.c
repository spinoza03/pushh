#include "../includes/push_swap.h"

void pa(t_stack **stack_a, t_stack **stack_b, int print)
{
    if (!stack_b || !*stack_b)
        return;

    t_stack *temp = *stack_b;
    *stack_b = (*stack_b)->next;
    temp->next = *stack_a;
    *stack_a = temp;

    if (print)
        write(1, "pa\n", 3);
}

// Push the top element of Stack A to Stack B
void pb(t_stack **stack_a, t_stack **stack_b, int print)
{
    if (!stack_a || !*stack_a)
        return;

    t_stack *temp = *stack_a;
    *stack_a = (*stack_a)->next;
    temp->next = *stack_b;
    *stack_b = temp;

    if (print)
        write(1, "pb\n", 3);
}