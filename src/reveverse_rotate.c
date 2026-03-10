/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reveverse_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 07:37:32 by danfern3          #+#    #+#             */
/*   Updated: 2026/03/06 09:47:24 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Performs a reverse rotate operation on the given stack. This operation
 * moves the last element of the stack to the top. If the stack is empty 
 * or has only one element, the function does nothing and returns 0.
 * @param stack The stack to perform the reverse rotate operation on
 * @return The number of operations performed (1 if the operation
 * was performed, 0 otherwise)
 */
static int	reverse_rotate(t_stack *stack)
{
	t_elem	*last;

	last = pop_bottom(stack);
	if (!last)
		return (0);
	push_top(stack, last);
	return (1);
}

int	rra(t_stack *a, bool print)
{
	int	movs;

	movs = reverse_rotate(a);
	if (movs && print)
		ft_printf("rra\n");
	return (movs);
}

int	rrb(t_stack *b, bool print)
{
	int	movs;

	movs = reverse_rotate(b);
	if (movs && print)
		ft_printf("rrb\n");
	return (movs);
}

int	rrr(t_stack *a, t_stack *b, bool print)
{
	int	movs;

	movs = rra(a, false) + rrb(b, false);
	if (movs > 0 && print)
		ft_printf("rrr\n");
	return (movs);
}
