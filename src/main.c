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

int	main(int ac, char **av)
{
	t_stack		a;
	t_stack		b;

	init_stack(&a);
	init_stack(&b);
	if (ac == 1 || (ac == 2 && !av[1][0]) || !process_arguments(ac, av, &a))
		return (0);
	if (!is_stack_sorted(&a))
		sort(&a, &b);
	if (DEBUG_MODE && !is_stack_sorted(&a))
	{
		ft_printf("Error: stack not sorted\n");
		print_stack(&a);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
