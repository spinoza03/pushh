/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:38:37 by ilallali          #+#    #+#             */
/*   Updated: 2025/02/27 15:12:53 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void index_stack(t_stack **stack)
{
    t_stack *tmp = *stack;
    t_stack *cmp;
    int index;

    while (tmp)
    {
        cmp = *stack;
        index = 0;
        while (cmp)
        {
            if (tmp->value > cmp->value)
                index++;
            cmp = cmp->next;
        }
        tmp->index = index;
        tmp = tmp->next;
    }
}
