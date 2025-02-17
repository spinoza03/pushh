#include "../includes/push_swap.h"

// Rotate Stack A (shift all elements up by 1)
void ra(t_stack **stack_a, int print)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return;
    t_stack *last = *stack_a;
    while (last->next)
        last = last->next;

    last->next = *stack_a;
    *stack_a = (*stack_a)->next;
    last->next->next = NULL;

    if (print)
        write(1, "ra\n", 3);
}

// Rotate Stack B (shift all elements up by 1)
void rb(t_stack **stack_b, int print)
{
    if (!stack_b || !*stack_b || !(*stack_b)->next)
        return;

    t_stack *last = *stack_b;
    while (last->next)
        last = last->next;

    last->next = *stack_b;
    *stack_b = (*stack_b)->next;
    last->next->next = NULL;

    if (print)
        write(1, "rb\n", 3);
}

// Rotate both Stack A and Stack B
void rr(t_stack **stack_a, t_stack **stack_b, int print)
{
    ra(stack_a, 0);
    rb(stack_b, 0);

    if (print)
        write(1, "rr\n", 3);
}

// Reverse rotate Stack A (shift all elements down by 1)
void rra(t_stack **stack_a, int print)
{
    if (!stack_a || !*stack_a || !(*stack_a)->next)
        return;

    t_stack *second_last = NULL;
    t_stack *last = *stack_a;

    while (last->next)
    {
        second_last = last;
        last = last->next;
    }

    second_last->next = NULL;
    last->next = *stack_a;
    *stack_a = last;

    if (print)
        write(1, "rra\n", 4);
}

// Reverse rotate Stack B (shift all elements down by 1)
void rrb(t_stack **stack_b, int print)
{
    if (!stack_b || !*stack_b || !(*stack_b)->next)
        return;

    t_stack *second_last = NULL;
    t_stack *last = *stack_b;

    while (last->next)
    {
        second_last = last;
        last = last->next;
    }

    second_last->next = NULL;
    last->next = *stack_b;
    *stack_b = last;

    if (print)
        write(1, "rrb\n", 4);
}

// Reverse rotate both Stack A and Stack B
void rrr(t_stack **stack_a, t_stack **stack_b, int print)
{
    rra(stack_a, 0);
    rrb(stack_b, 0);

    if (print)
        write(1, "rrr\n", 4);
}