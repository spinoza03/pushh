/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:53:47 by ilallali          #+#    #+#             */
/*   Updated: 2025/03/01 13:39:22 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (!parse_args(argc, argv, &a) || has_duplicates(a))
	{
		stack_clear(&a);
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	sort_stack(&a, &b);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
