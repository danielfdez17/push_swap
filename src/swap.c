/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danfern3 <danfern3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 07:37:56 by danfern3          #+#    #+#             */
/*   Updated: 2025/11/07 07:46:32 by danfern3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap(t_stack *stack)
{
	if (!stack || stack->size <= 1)
		return (0);
	ft_swap_int(&stack->top->value, &stack->top->next->value);
	return (1);
}

int	sa(t_stack **a, bool print)
{
	int	movs;

	movs = swap(*a);
	if (movs && print)
		ft_printf("sa\n");
	return (movs);
}

int	sb(t_stack **b, bool print)
{
	int	movs;

	movs = swap(*b);
	if (movs && print)
		ft_printf("sb\n");
	return (swap(*b));
}

int	ss(t_stack **a, t_stack **b, bool print)
{
	int	movs;

	movs = sa(a, 0) + sb(b, 0);
	if (movs > 0 && print)
		ft_printf("ss\n");
	return (movs);
}