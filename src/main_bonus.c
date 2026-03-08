/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 09:47:35 by danfern3          #+#    #+#             */
/*   Updated: 2026/03/06 09:47:59 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	init_stack(&a);
	init_stack(&b);
	if (ac == 1 || (ac == 2 && !av[1][0]) || !process_arguments(ac, av, &a))
		return (0);
	read_moves(&a, &b);
	if (!is_stack_sorted(&a) || !is_stack_empty(&b))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	free_stack(&a);
	free_stack(&b);
	return (0);
}
