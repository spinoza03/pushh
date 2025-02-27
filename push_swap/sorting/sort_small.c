/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:20:37 by ilallali          #+#    #+#             */
/*   Updated: 2025/02/27 14:32:42 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack *find_smallest(t_stack *stack)
{
    t_stack *smallest = stack;
    while (stack)
    {
        if (stack->value < smallest->value)
            smallest = stack;
        stack = stack->next;
    }
    return (smallest);
}

void sort_two(t_stack **stack_a)
{
        sa(stack_a);
}

void sort_three(t_stack **stack_a)
{
    int a = (*stack_a)->value;
    int b = (*stack_a)->next->value;
    int c = (*stack_a)->next->next->value;

    if (a > b && a > c)
        ra(stack_a);
    if (b > a && b > c)
        rra(stack_a);
    if ((*stack_a)->value > (*stack_a)->next->value)
        sa(stack_a);
}
void sort_four_or_five(t_stack **stack_a, t_stack **stack_b)
{
    while (stack_size(*stack_a) > 3)
    {
        move_to_top(stack_a, find_smallest(*stack_a));
        pb(stack_a, stack_b);
    }
    sort_three(stack_a);
    while (*stack_b)
        pa(stack_a, stack_b);
}

