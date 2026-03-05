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
	int			status_code;

	init_stack(&a);
	init_stack(&b);
	status_code = 0;
	if (ac == 1 || (ac == 2 && !av[1][0]) || !process_arguments(ac, av, &a))
		return (0);
	// print_stack(&a);
	// ft_printf("a->size: %d\n", a.size);
	if (!is_stack_sorted(&a))
		sort(&a, &b);
	// print_stack(&a);
	if (!is_stack_sorted(&a))
		status_code = 1;
	// 	ft_printf("Error: stack not sorted\n");
	free_stack(&a);
	free_stack(&b);
	return (status_code);
}
