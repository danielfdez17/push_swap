/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 07:36:59 by danfern3          #+#    #+#             */
/*   Updated: 2026/03/06 09:47:02 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate(t_stack *stack)
{
	t_elem	*first;

	if (!stack || stack->size <= 1)
		return (0);
	first = pop_top(stack);
	push_bottom(stack, first);
	return (1);
}

int	ra(t_stack *a, bool print)
{
	int	movs;

	movs = rotate(a);
	if (movs && print)
		ft_printf("ra\n");
	return (movs);
}

int	rb(t_stack *b, bool print)
{
	int	movs;

	movs = rotate(b);
	if (movs && print)
		ft_printf("rb\n");
	return (movs);
}

int	rr(t_stack *a, t_stack *b, bool print)
{
	int	movs;

	movs = ra(a, 0) + rb(b, 0);
	if (movs > 0 && print)
		ft_printf("rr\n");
	return (movs);
}

int	rotation_cost(int pos, int size)
{
	if (size <= 0)
		return (0);
	if (pos <= size / 2)
		return (pos);
	return (-(size - pos));
}
