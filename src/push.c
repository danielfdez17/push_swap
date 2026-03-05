/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 07:37:06 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/07 07:38:42 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa(t_stack **a, t_stack **b, bool print)
{
	t_elem	*elem;

	if (!*b)
		return (0);
	elem = pop_top(b);
	push_top(a, elem);
	if (print)
		ft_printf("pa\n");
	return (1);
}

int	pb(t_stack **a, t_stack **b, bool print)
{
	t_elem	*elem;

	if (!*a)
		return (0);
	elem = pop_top(a);
	push_top(b, elem);
	if (print)
		ft_printf("pb\n");
	return (1);
}
