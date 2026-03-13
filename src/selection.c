/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 07:10:18 by danfern3          #+#    #+#             */
/*   Updated: 2026/03/13 07:15:43 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Selection sorting algorithm
 */
void	selection_sort(t_stack *a, t_stack *b, bool print)
{
	t_elem	*value;

	while (!is_stack_sorted(a))
	{
		if (a->top)
		{
			value = get_min_value(a);
			if (value->front == 1)
			{
				sa(a, print);
				continue ;
			}
			while (a->top != value)
			{
				if (value->front <= value->back)
					ra(a, print);
				else
					rra(a, print);
			}
			pb(a, b, print);
		}
	}
	while (b->top)
		pa(a, b, print);
}
