/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:53:47 by ilallali          #+#    #+#             */
/*   Updated: 2025/02/14 16:26:45 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int argc, char **argv)
{
    t_stack *stack_a;

    stack_a = NULL;

    if (argc == 1)
    {
        return (1);
    }

    if (!parse_args(argc, argv, &stack_a))
    {
        ft_putstr_fd("Error\n", 2);
        return (1);
    }

    ft_putstr_fd("Stack a: ", 1);
    t_stack *current = stack_a;
    while (current)
    {
        ft_putnbr_fd(current->value, 1);
        ft_putstr_fd(" ", 1);
        current = current->next;
    }
    ft_putstr_fd("\n", 1);

    stack_clear(&stack_a);

    stack_clear(&stack_a);

    return (0);
}