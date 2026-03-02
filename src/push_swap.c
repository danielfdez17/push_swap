/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 07:36:22 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/07 08:52:29 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		sa(a, TRUE);
	else if (size == 3)
		sort_three(a, TRUE);
	else if (size <= MAX_SELECTION_NUMBER)
		selection_sort(a, b, TRUE);
	else
		radix_sort(a, b, size, TRUE);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (0);
	if (ac == 2)
		av = ft_split(av[1], ' ');
	else
		++av;
	if (!init_stack(&a, av))
		return (0);
	if (!is_stack_sorted(a))
		sort(&a, &b, get_size(a));
	if (!is_stack_sorted(a))
		ft_printf("haha\n");
	free_stack(a);
	free_stack(b);
	return (0);
}
// ! checker_linux usage: ARG="9 8 7 6 5 4 3 2 1";
// ./push_swap $ARG | ./checker_linux $ARG
