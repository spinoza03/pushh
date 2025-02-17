/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allali <allali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:53:47 by ilallali          #+#    #+#             */
/*   Updated: 2025/02/16 18:39:55 by allali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int argc, char **argv)
{
    t_stack *stack_a = NULL;
    t_stack *stack_b = NULL;

    if (argc < 2)
        return (1);

    if (!parse_args(argc, argv, &stack_a))
    {
        write(2, "Error\n", 6);
        free_stack(&stack_a);
        return (1);
    }

    if (is_sorted(stack_a))
    {
        free_stack(&stack_a);
        return (0);
    }

    int size = stack_size(stack_a);
    if (size <= 3)
        sort_three(&stack_a);
    else if (size <= 5)
        sort_five(&stack_a, &stack_b);
    else
        radix_sort(&stack_a, &stack_b);

    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}