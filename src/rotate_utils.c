/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 07:36:59 by danfern3          #+#    #+#             */
/*   Updated: 2026/03/06 09:47:02 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_n_times(t_stack *a, int cost, bool print)
{
	while (cost > 0)
	{
		ra(a, print);
		cost--;
	}
	while (cost < 0)
	{
		rra(a, print);
		cost++;
	}
}

void	rotate_b_n_times(t_stack *b, int cost, bool print)
{
	while (cost > 0)
	{
		rb(b, print);
		cost--;
	}
	while (cost < 0)
	{
		rrb(b, print);
		cost++;
	}
}

void	exec_rotations(t_stack *a, t_stack *b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(a, b, true);
		(*cost_a)--;
		(*cost_b)--;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(a, b, true);
		(*cost_a)++;
		(*cost_b)++;
	}
	rotate_a_n_times(a, *cost_a, true);
	rotate_b_n_times(b, *cost_b, true);
}

void	align_min_on_top(t_stack *a, bool print)
{
	t_elem	*ptr;
	int		pos;
	int		min_pos;
	int		min_idx;

	ptr = a->top;
	pos = 0;
	min_pos = 0;
	min_idx = INT_MAX;
	while (ptr)
	{
		if (ptr->index < min_idx)
		{
			min_idx = ptr->index;
			min_pos = pos;
		}
		ptr = ptr->next;
		pos++;
	}
	rotate_a_n_times(a, rotation_cost(min_pos, a->size), print);
}
