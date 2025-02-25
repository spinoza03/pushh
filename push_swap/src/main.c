/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilallali <ilallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:53:47 by ilallali          #+#    #+#             */
/*   Updated: 2025/02/25 11:09:17 by ilallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// int is_sapace(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while(str[i])
// 	{
// 		if (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }
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
}
