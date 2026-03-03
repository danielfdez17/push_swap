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
	t_stack	*elem;

	if (!*b)
		return (0);
	elem = pop_front(b);
	push_front(a, elem);
	if (print)
		ft_printf("pa\n");
	return (1);
}

int	pb(t_stack **a, t_stack **b, bool print)
{
	t_stack	*elem;

	if (!*a)
		return (0);
	elem = pop_front(a);
	push_front(b, elem);
	if (print)
		ft_printf("pb\n");
	return (1);
}
