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

// todo: optimize this function by checking if the min node is closer to the top or bottom of the stack and rotate accordingly
void	push_min_to_b(t_stack *a, t_stack *b, bool print)
{
	t_elem	*min_node;

	min_node = stack_get_min(a);
	while (a->top != min_node)
	{
		if (min_node->index <= a->size / 2)
			ra(a, print);
		else
			rra(a, print);
	}
	pb(a, b, print);
}
