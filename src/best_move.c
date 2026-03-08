/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 07:36:59 by danfern3          #+#    #+#             */
/*   Updated: 2026/03/06 09:47:02 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_target_pos_in_a_helper(t_stack *a)
{
	t_elem	*ptr;
	int		pos;
	int		target_pos;
	int		target_index;

	ptr = a->top;
	pos = 0;
	target_pos = 0;
	target_index = INT_MAX;
	while (ptr)
	{
		if (ptr->index < target_index)
		{
			target_index = ptr->index;
			target_pos = pos;
		}
		ptr = ptr->next;
		pos++;
	}
	return (target_pos);
}

static int	find_target_pos_in_a(t_stack *a, int b_index)
{
	t_elem	*ptr;
	int		pos;
	int		target_pos;
	int		target_index;

	if (is_stack_empty(a))
		return (0);
	ptr = a->top;
	pos = 0;
	target_pos = -1;
	target_index = INT_MAX;
	while (ptr)
	{
		if (ptr->index > b_index && ptr->index < target_index)
		{
			target_index = ptr->index;
			target_pos = pos;
		}
		ptr = ptr->next;
		pos++;
	}
	if (target_pos != -1)
		return (target_pos);
	return (find_target_pos_in_a_helper(a));
}

void	get_best_move(t_stack *a, t_stack *b, int *cost_a, int *cost_b)
{
	t_best_move	bm;
	int			pos_b;

	bm.elem = b->top;
	pos_b = -1;
	bm.best_total = INT_MAX;
	while (bm.elem && ++pos_b < INT_MAX)
	{
		bm.current_a = rotation_cost(
				find_target_pos_in_a(a, bm.elem->index), a->size);
		bm.current_b = rotation_cost(pos_b, b->size);
		bm.total = ft_abs_int(bm.current_a) + ft_abs_int(bm.current_b);
		if ((bm.current_a >= 0 && bm.current_b >= 0)
			|| (bm.current_a < 0 && bm.current_b < 0))
			bm.total = ft_max_int(
					ft_abs_int(bm.current_a), ft_abs_int(bm.current_b));
		if (bm.total < bm.best_total)
		{
			bm.best_total = bm.total;
			*cost_a = bm.current_a;
			*cost_b = bm.current_b;
		}
		bm.elem = bm.elem->next;
	}
}
