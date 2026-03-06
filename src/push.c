/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 07:37:06 by danfern3          #+#    #+#             */
/*   Updated: 2026/03/06 09:35:02 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa(t_stack *a, t_stack *b, bool print)
{
	t_elem	*elem;

	if (!b)
		return (0);
	elem = pop_top(b);
	push_top(a, elem);
	if (print)
		ft_printf("pa\n");
	return (1);
}

int	pb(t_stack *a, t_stack *b, bool print)
{
	t_elem	*elem;

	if (!a)
		return (0);
	elem = pop_top(a);
	push_top(b, elem);
	if (print)
		ft_printf("pb\n");
	return (1);
}

void	push_min_to_b(t_stack *a, t_stack *b, bool print)
{
	t_elem	*min_elem;

	min_elem = get_min_value(a);
	while (a->top != min_elem)
	{
		if (min_elem->front <= min_elem->back)
			ra(a, print);
		else
			rra(a, print);
	}
	pb(a, b, print);
}

void	push_max_to_b(t_stack *a, t_stack *b, bool print)
{
	t_elem	*max_elem;

	if (is_stack_empty(a))
		return ;
	max_elem = get_max_value(a);
	while (a->top != max_elem)
	{
		if (max_elem->front <= max_elem->back)
			ra(a, print);
		else
			rra(a, print);
	}
	pb(a, b, print);
}
