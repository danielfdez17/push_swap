/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 07:37:56 by danfern3          #+#    #+#             */
/*   Updated: 2026/03/06 09:44:21 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Performs a swap operation on the given stack. This operation swaps the
 * values of the first two elements.
 * If the stack is empty or has only one element, the function does
 * nothing and returns 0.
 * @param stack The stack to perform the swap operation on
 * @return The number of operations performed (1 if the operation
 * was performed, 0 otherwise)
 */
static int	swap(t_stack *stack)
{
	if (!stack || stack->size <= 1)
		return (0);
	ft_swap_int(&stack->top->value, &stack->top->next->value);
	return (1);
}

int	sa(t_stack *a, bool print)
{
	int	movs;

	movs = swap(a);
	if (movs && print)
		ft_printf("sa\n");
	return (movs);
}

int	sb(t_stack *b, bool print)
{
	int	movs;

	movs = swap(b);
	if (movs && print)
		ft_printf("sb\n");
	return (movs);
}

int	ss(t_stack *a, t_stack *b, bool print)
{
	int	movs;

	movs = sa(a, false) + sb(b, false);
	if (movs > 0 && print)
		ft_printf("ss\n");
	return (movs);
}
